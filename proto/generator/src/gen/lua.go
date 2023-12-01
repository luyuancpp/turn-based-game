package gen

import (
	"bufio"
	"gengo/config"
	"gengo/util"
	"os"
	"path/filepath"
	"reflect"
	"strconv"
	"strings"
)

const msg = "message "
const begin = "{"
const end = "}"
const setName = "::set_"
const mapType = "map"
const stringType = "string"

func WriteLoadClientLuaFile() {
	util.Wg.Add(1)
	go func() {
		defer util.Wg.Done()
		var fds []os.DirEntry
		var err error
		if fds, err = os.ReadDir(config.ClientLuaDir); err != nil {
			return
		}
		data := "#include <sol/sol.hpp>\n" +
			"#include \"muduo/base/Logging.h\"\n" +
			"#include \"src/util/file2string.h\"\n" +
			"#include \"src/thread_local/thread_local_storage_lua.h\"\n" +
			"void LoadLuaScript()\n{\n"
		data += config.Tab + "std::string contents;\n"
		for _, fd := range fds {
			if !util.IsLuaFile(fd) {
				continue
			}
			data += config.Tab + "contents = File2String(\"" + config.ClientLuaProjectRelative + fd.Name() + "\");\n"
			data += config.Tab + "{\n"
			data += config.Tab2 + "auto r = tls_lua_state.script(contents);\n"
			data += config.Tab2 + "if (!r.valid())\n"
			data += config.Tab2 + "{\n"
			data += config.Tab3 + "sol::error err = r;\n"
			data += config.Tab3 + "LOG_FATAL << err.what();\n"
			data += config.Tab2 + "}\n"
			data += config.Tab + "}\n"
		}
		data += "\n}\n"
		WriteMd5Data2File(config.ClientLuaServiceFile, data)
	}()
}

func toCppIntType(typeString string) (newType string, convert bool) {
	if reflect.DeepEqual(typeString, "int32") ||
		reflect.DeepEqual(typeString, "uint32") ||
		reflect.DeepEqual(typeString, "uint64") ||
		reflect.DeepEqual(typeString, "int64") {
		typeString = typeString + "_t"
		return typeString, true
	}
	return typeString, false
}

func GetTypeRefString(typeString string) (valueTypeRef string) {
	if isCppType(typeString) {
		valueTypeRef, _ = toCppIntType(typeString)
	} else {
		valueTypeRef = typeString + "&"
	}
	return valueTypeRef
}

func isCppType(typeString string) bool {
	return reflect.DeepEqual(typeString, "int32") ||
		reflect.DeepEqual(typeString, "uint32") ||
		reflect.DeepEqual(typeString, "uint64") ||
		reflect.DeepEqual(typeString, "int64") ||
		reflect.DeepEqual(typeString, "int32_t") ||
		reflect.DeepEqual(typeString, "uint32_t") ||
		reflect.DeepEqual(typeString, "uint64_t") ||
		reflect.DeepEqual(typeString, "int64_t") ||
		reflect.DeepEqual(typeString, "bool") ||
		reflect.DeepEqual(typeString, "float") ||
		reflect.DeepEqual(typeString, "double")
}

func writeSol2LuaFileByProtoFile(fd os.DirEntry, filePath string) {
	defer util.Wg.Done()
	isMsgCode := 0
	isEnumCode := 0
	fileBaseName := filepath.Base(strings.ToLower(strings.ReplaceAll(fd.Name(), config.ProtoEx, "")))

	f, err := os.Open(filePath + fd.Name())
	if err != nil {
		return
	}
	data := util.IncludeName(filePath, fd.Name()) +
		"#include <sol/sol.hpp>\n" +
		"#include \"src/thread_local/thread_local_storage_lua.h\"\n" +
		"void Pb2sol2" + fileBaseName + "()" + "\n{\n"
	defer func(f *os.File) {
		err := f.Close()
		if err != nil {
			return
		}
	}(f)
	scanner := bufio.NewScanner(f)
	className := ""
	for scanner.Scan() {
		line := scanner.Text()
		if strings.Contains(line, "enum") {
			isEnumCode = 1
			continue
		} else if strings.Contains(line, end) && isEnumCode == 1 {
			isEnumCode = 0
			continue
		} else if isEnumCode == 1 {
			continue
		}
		if strings.Contains(line, msg) {
			isMsgCode = 1
			className = strings.Trim(strings.Split(line, " ")[1], "\n")
			data += "tls_lua_state.new_usertype<" + className + ">(\"" + className + "\",\n"
			continue
		}
		if strings.Contains(line, begin) {
			continue
		} else if strings.Contains(line, end) && isMsgCode == 1 {
			data += "\"DebugString\",\n"
			data += "&" + className + "::DebugString,\n"
			data += "sol::base_classes, sol::bases<::google::protobuf::Message>());\n\n"
			isMsgCode = 0
			continue
		} else if isMsgCode == 1 {
			s := strings.Split(strings.Trim(strings.Trim(line, "\t"), " "), " ")
			if len(s) < 3 {
				continue
			}
			filedTypeName := s[0]
			filedName := s[1]
			templateName := ""
			isRepeatedFiled := true
			mapKeyType := ""
			mapValueType := ""
			//填入真正的类型
			if isCppType(filedTypeName) {
				templateName = ""
				isRepeatedFiled = false
			} else if filedTypeName == stringType {
				templateName = "<const std::string&>"
				isRepeatedFiled = false
			} else if filedTypeName == "repeated" {
				filedTypeName = s[1]
				filedName = s[2]
			} else if strings.Contains(filedTypeName, mapType) {
				filedTypeName = mapType
				mapKeyType = strings.Split(strings.Trim(s[0], "\tmap<"), ",")[0]
				mapKeyType, _ = toCppIntType(mapKeyType)
				mapValueType, _ = toCppIntType(strings.Split(strings.Trim(strings.Trim(s[1], "\t"), " "), ">")[0])
				filedName = s[2]
			} else {
				data += "\"" + filedName + "\",\n"
				data += "[](" + className + "& pb) ->decltype(auto){ return pb." + filedName + "();},\n"
				data += "\"mutable_" + filedName + "\",\n"
				data += "[](" + className + "& pb) ->decltype(auto){ return pb.mutable_" + filedName + "();},\n"
				continue
			}
			if !isRepeatedFiled {
				data += "\"" + filedName + "\",\n"
				data += "sol::property(&" + className + "::" + filedName + ", &" + className + setName + filedName
				data += templateName + "),\n"
			} else {
				if filedTypeName == "string" {
					templateName = "<const std::string&>"
					data += "\"add_" + filedName + "\",\n"
					data += "[](" + className + "& pb, const std::string& value) ->decltype(auto){ return pb.add_" +
						filedName + "(value);},\n"
					data += "\"" + filedName + "\",\n"
					data += "[](" + className + "& pb, int index) ->decltype(auto){ return pb." + filedName + "(index);},\n"
					data += "\"set_" + filedName + "\",\n"
					data += "[](" + className + "& pb, int index, const std::string& value) ->decltype(auto){ return pb.set_" +
						filedName + "(index, value);},\n"
				} else if filedTypeName == mapType {
					data += "\"count_" + filedName + "\",\n"
					data += "[](" + className + "& pb, " + GetTypeRefString(mapKeyType) + " key) ->decltype(auto){ return pb." +
						filedName + "().count(key);},\n"
					data += "\"insert_" + filedName + "\",\n"
					data += "[](" + className + "& pb, " + GetTypeRefString(mapKeyType) + " key, " + GetTypeRefString(mapValueType) +
						" value) ->decltype(auto){ return pb.mutable_" + filedName + "()->emplace(key, value).second;},\n"
					data += "\"" + filedName + "\",\n"
					data += "[](" + className + "& pb, " + GetTypeRefString(mapKeyType) + " key) ->decltype(auto){\n"
					data += " auto it =  pb.mutable_" + filedName + "()->find(key);\n"
					if isCppType(mapValueType) {
						vt, _ := toCppIntType(mapValueType)
						data += " if (it == pb.mutable_" + filedName + "()->end()){ return " + vt + "(); }\n"
					} else {
						data += " if (it == pb.mutable_" + filedName + "()->end()){ static " + mapValueType + " instance; return instance; }\n"
					}
					data += " return it->second;},\n"
				} else {
					typename, convert := toCppIntType(filedTypeName)
					if convert {
						data += "\"add_" + filedName + "\",\n"
						data += "&" + className + "::add_" + filedName + ",\n"
						data += "\"" + filedName + "\",\n"
						data += "[](const " + className + "& pb, int index) ->decltype(auto){ return pb." + filedName + "(index);},\n"
						data += "\"set_" + filedName + "\",\n"
						data += "[](" + className + "& pb, int index, " + typename + " value) ->decltype(auto){ return pb.set_" + filedName + "(index, value);},\n"
					} else {
						data += "\"add_" + filedName + "\",\n"
						data += "&" + className + "::add_" + filedName + ",\n"
						data += "\"" + filedName + "\",\n"
						data += "[](const " + className + "& pb, int index) ->decltype(auto){ return pb." + filedName + "(index);},\n"
						data += "\"mutable_" + filedName + "\",\n"
						data += "[](" + className + "& pb, int index) ->decltype(auto){ return pb.mutable_" + filedName + "(index);},\n"
					}
				}
				data += "\"" + filedName + "_size\",\n"
				data += "&" + className + "::" + filedName + "_size,\n"
				data += "\"clear_" + filedName + "\",\n"
				data += "&" + className + "::clear_" + filedName + ",\n"
			}
		}
	}
	data += "}\n"
	WriteMd5Data2File(config.PbcLuaDirName+fileBaseName+config.CppSol2Ex, data)
}

func WriteSol2LuaFile() {
	util.Wg.Add(1)
	go func() {
		defer util.Wg.Done()
		data := "#include <google/protobuf/message.h>\n" +
			"#include <sol/sol.hpp>\n" +
			"#include \"src/thread_local/thread_local_storage_lua.h\"\n\n"
		declarationData := ""
		callData := ""

		for i := 0; i < len(config.ProtoDirs); i++ {
			fds, err := os.ReadDir(config.ProtoDirs[i])
			if err != nil {
				continue
			}
			for _, fd := range fds {
				if !util.IsProtoFile(fd) {
					continue
				}
				if strings.Contains(fd.Name(), config.MysqlName) {
					continue
				}
				util.Wg.Add(1)
				writeSol2LuaFileByProtoFile(fd, config.ProtoDirs[i])

				fileBaseName := filepath.Base(strings.ToLower(strings.ReplaceAll(fd.Name(), config.ProtoEx, "")))
				declarationData += "void Pb2sol2" + fileBaseName + "();\n"
				callData += "Pb2sol2" + fileBaseName + "();\n"
			}

		}
		data += declarationData + "\n"
		data += "void pb2sol2()\n{\n"
		data += "tls_lua_state.new_usertype<::google::protobuf::Message>(\"Message\");\n"
		data += callData + "\n"
		data += "}\n"
		WriteMd5Data2File(config.PbcLuaDirName+"pb"+config.CppSol2Ex, data)
	}()

}

func writeLuaServiceMethodCppFile(methodList RpcMethodInfos) {
	defer util.Wg.Done()

	if len(methodList) <= 0 {
		return
	}
	var data = "#include <cstdint>\n\n"
	data += "#include \"src/thread_local/thread_local_storage_lua.h\"\n"
	data += methodList[0].IncludeName() + "\n\n"

	data += "void Init" + methodList[0].Service + "Lua()\n{\n"
	for i := 0; i < len(methodList); i++ {
		data += config.Tab + "tls_lua_state[\"" + methodList[i].KeyName() + config.MessageIdName + "\"] = " +
			strconv.FormatUint(methodList[i].Id, 10) + ";\n"
		data += config.Tab + "tls_lua_state[\"" + methodList[i].KeyName() + config.MethodIndexName + "\"] = " +
			strconv.FormatUint(methodList[i].Index, 10) + ";\n"
		data += config.Tab + "tls_lua_state[\"" + methodList[i].KeyName() +
			"\"] = []()-> const ::google::protobuf::MethodDescriptor* {\n" +
			config.Tab2 + "return " + methodList[i].Service + "_Stub::descriptor()->method(" +
			strconv.FormatUint(methodList[i].Index, 10) + ");\n" +
			config.Tab + "};\n\n"
	}
	data += "}\n"
	fileName := methodList[0].FileBaseName() + "_service" + config.LuaCppEx
	WriteMd5Data2File(config.PbcLuaDirName+fileName, data)
}

func writeInitLuaServiceFile() {
	defer util.Wg.Done()
	data := "void InitServiceLua()\n{\n"
	ServiceList := GetSortServiceList()
	for _, key := range ServiceList {
		methodList, ok := ServiceMethodMap[key]
		if !ok {
			continue
		}
		if len(methodList) <= 0 {
			continue
		}
		firstMethodInfo := methodList[0]
		data += config.Tab + "void Init" + firstMethodInfo.Service + "Lua();\n"
		data += config.Tab + "Init" + firstMethodInfo.Service + "Lua();\n\n"
	}
	data += "}\n"
	WriteMd5Data2File(config.LuaServiceFileName, data)
}

func WriteLuaServiceHeadHandlerFile() {
	for _, v := range ServiceMethodMap {
		util.Wg.Add(1)
		go writeLuaServiceMethodCppFile(v)
	}
	util.Wg.Add(1)
	go writeInitLuaServiceFile()
}
