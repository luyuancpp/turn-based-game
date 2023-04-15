import os
from os import system
import md5tool
import shutil
import genpublic

servicearray = []
servicefilenamearray = []
md5dir = './md5/logic_proto/'
logicprotodir = './logic_proto/'

if not os.path.exists(md5dir):
    os.makedirs(md5dir)

def scanservice():
    for (dirpath, dirnames, filenames) in os.walk(logicprotodir):
        for filename in filenames:  
            if filename.find('client_player') >= 0 or filename.find('server_player') >= 0 or filename.find(genpublic.lobby_file_prefix) >= 0 or filename.find(genpublic.lobby_file_prefix) > 0:
                continue  
            with open(dirpath + filename,'r', encoding='utf-8') as file:
                for fileline in file:
                    if fileline.find('service ') < 0:
                        continue
                    servicearray.append(fileline.split(' ')[1])
                    servicefilenamearray.append(filename.replace('.proto', '.h'))
                    break;

def genheadfile(writedfilename):
    global servicearray
    newstr = '#pragma once\n'
    newstr += '#include <array>\n'
    newstr += '#include <memory>\n'
    newstr += '#include <google/protobuf/message.h>\n\n'
    newstr += 'extern std::array<std::unique_ptr<::google::protobuf::Service>, ' + str(len(servicearray)) + '> g_server_service;\n'
    with open(writedfilename, 'w', encoding='utf-8')as file:
        file.write(newstr)

def gencppfile(writedfilename):
    global servicearray
    newstr = '#include <array>\n'
    newstr += '#include <memory>\n'
    newstr += '#include <google/protobuf/message.h>\n\n'
    for filename in servicefilenamearray:
        newstr += '#include "'  + filename + '"\n'
    newstr += 'std::array<std::unique_ptr<::google::protobuf::Service>, ' + str(len(servicearray)) + '> g_server_service{\n'
    for service in servicearray:
        newstr += 'std::unique_ptr<::google::protobuf::Service>(new ' +  service.replace('\n', '') + 'Impl),\n'
    newstr = newstr.strip(',\n') + '};\n'
    with open(writedfilename, 'w', encoding='utf-8')as file:
        file.write(newstr)

scanservice()
genheadfile('./md5/server_service.h')
gencppfile('./md5/controller_server/server_service.cpp')
gencppfile('./md5/game_server/server_service.cpp')

cppmd5info = genpublic.md5fileinfo()
cppmd5info.filename = 'server_service.cpp'
cppmd5info.destdir = '../controller_server/src/service/logic_proto/'
cppmd5info.md5dir = './md5/controller_server/'
    
genpublic.md5copy(cppmd5info)

cppmd5info.filename = 'server_service.h'
cppmd5info.destdir = '../controller_server/src/service/logic_proto/'
cppmd5info.md5dir = './md5/'
genpublic.md5copy(cppmd5info)

cppmd5info.filename = 'server_service.cpp'
cppmd5info.destdir = '../game_server/src/service/logic_proto/'
cppmd5info.md5dir = './md5/game_server/'
genpublic.md5copy(cppmd5info)

cppmd5info.filename = 'server_service.h'
cppmd5info.destdir = '../game_server/src/service/logic_proto/'
cppmd5info.md5dir = './md5/'
genpublic.md5copy(cppmd5info)

#md5copy('./md5/server_service.h', '../controller_server/src/service/logic_proto/server_service.h')
#md5copy('./md5/controller_server/server_service.cpp', '../controller_server/src/service/logic_proto/server_service.cpp')
#md5copy('./md5/game_server/server_service.cpp', '../game_server/src/service/logic_proto/server_service.cpp')
#md5copy('./md5/server_service.h', '../game_server/src/service/logic_proto/server_service.h')
