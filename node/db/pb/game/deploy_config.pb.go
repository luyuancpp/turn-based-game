// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.34.1
// 	protoc        v5.26.1
// source: common/deploy_config.proto

package game

import (
	protoreflect "google.golang.org/protobuf/reflect/protoreflect"
	protoimpl "google.golang.org/protobuf/runtime/protoimpl"
	reflect "reflect"
	sync "sync"
)

const (
	// Verify that this generated code is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(20 - protoimpl.MinVersion)
	// Verify that runtime/protoimpl is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(protoimpl.MaxVersion - 20)
)

type ConnetionParam struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Ip         string `protobuf:"bytes,1,opt,name=ip,proto3" json:"ip,omitempty"`
	Port       uint32 `protobuf:"varint,2,opt,name=port,proto3" json:"port,omitempty"`
	DbHost     string `protobuf:"bytes,3,opt,name=db_host,json=dbHost,proto3" json:"db_host,omitempty"`
	DbUser     string `protobuf:"bytes,4,opt,name=db_user,json=dbUser,proto3" json:"db_user,omitempty"`
	DbPassword string `protobuf:"bytes,5,opt,name=db_password,json=dbPassword,proto3" json:"db_password,omitempty"`
	DbPort     uint32 `protobuf:"varint,6,opt,name=db_port,json=dbPort,proto3" json:"db_port,omitempty"`
	DbDbname   string `protobuf:"bytes,7,opt,name=db_dbname,json=dbDbname,proto3" json:"db_dbname,omitempty"`
}

func (x *ConnetionParam) Reset() {
	*x = ConnetionParam{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_deploy_config_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *ConnetionParam) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*ConnetionParam) ProtoMessage() {}

func (x *ConnetionParam) ProtoReflect() protoreflect.Message {
	mi := &file_common_deploy_config_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use ConnetionParam.ProtoReflect.Descriptor instead.
func (*ConnetionParam) Descriptor() ([]byte, []int) {
	return file_common_deploy_config_proto_rawDescGZIP(), []int{0}
}

func (x *ConnetionParam) GetIp() string {
	if x != nil {
		return x.Ip
	}
	return ""
}

func (x *ConnetionParam) GetPort() uint32 {
	if x != nil {
		return x.Port
	}
	return 0
}

func (x *ConnetionParam) GetDbHost() string {
	if x != nil {
		return x.DbHost
	}
	return ""
}

func (x *ConnetionParam) GetDbUser() string {
	if x != nil {
		return x.DbUser
	}
	return ""
}

func (x *ConnetionParam) GetDbPassword() string {
	if x != nil {
		return x.DbPassword
	}
	return ""
}

func (x *ConnetionParam) GetDbPort() uint32 {
	if x != nil {
		return x.DbPort
	}
	return 0
}

func (x *ConnetionParam) GetDbDbname() string {
	if x != nil {
		return x.DbDbname
	}
	return ""
}

type ConnetionParamJsonFormat struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Data []*ConnetionParam `protobuf:"bytes,1,rep,name=data,proto3" json:"data,omitempty"`
}

func (x *ConnetionParamJsonFormat) Reset() {
	*x = ConnetionParamJsonFormat{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_deploy_config_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *ConnetionParamJsonFormat) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*ConnetionParamJsonFormat) ProtoMessage() {}

func (x *ConnetionParamJsonFormat) ProtoReflect() protoreflect.Message {
	mi := &file_common_deploy_config_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use ConnetionParamJsonFormat.ProtoReflect.Descriptor instead.
func (*ConnetionParamJsonFormat) Descriptor() ([]byte, []int) {
	return file_common_deploy_config_proto_rawDescGZIP(), []int{1}
}

func (x *ConnetionParamJsonFormat) GetData() []*ConnetionParam {
	if x != nil {
		return x.Data
	}
	return nil
}

type GameConfigInfo struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	ZoneId          uint32   `protobuf:"varint,1,opt,name=zone_id,json=zoneId,proto3" json:"zone_id,omitempty"`
	LobbyId         uint32   `protobuf:"varint,2,opt,name=lobby_id,json=lobbyId,proto3" json:"lobby_id,omitempty"`
	Loglevel        uint32   `protobuf:"varint,3,opt,name=loglevel,proto3" json:"loglevel,omitempty"`
	ServerType      uint32   `protobuf:"varint,4,opt,name=server_type,json=serverType,proto3" json:"server_type,omitempty"`
	MqTopics        []string `protobuf:"bytes,5,rep,name=mq_topics,json=mqTopics,proto3" json:"mq_topics,omitempty"`
	AccessPoint     string   `protobuf:"bytes,6,opt,name=access_point,json=accessPoint,proto3" json:"access_point,omitempty"`
	MessageBodySize uint32   `protobuf:"varint,7,opt,name=message_body_size,json=messageBodySize,proto3" json:"message_body_size,omitempty"`
	Total           uint32   `protobuf:"varint,8,opt,name=total,proto3" json:"total,omitempty"`
	AccessKey       string   `protobuf:"bytes,9,opt,name=access_key,json=accessKey,proto3" json:"access_key,omitempty"`
	AccessSecret    string   `protobuf:"bytes,10,opt,name=access_secret,json=accessSecret,proto3" json:"access_secret,omitempty"`
}

func (x *GameConfigInfo) Reset() {
	*x = GameConfigInfo{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_deploy_config_proto_msgTypes[2]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *GameConfigInfo) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*GameConfigInfo) ProtoMessage() {}

func (x *GameConfigInfo) ProtoReflect() protoreflect.Message {
	mi := &file_common_deploy_config_proto_msgTypes[2]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use GameConfigInfo.ProtoReflect.Descriptor instead.
func (*GameConfigInfo) Descriptor() ([]byte, []int) {
	return file_common_deploy_config_proto_rawDescGZIP(), []int{2}
}

func (x *GameConfigInfo) GetZoneId() uint32 {
	if x != nil {
		return x.ZoneId
	}
	return 0
}

func (x *GameConfigInfo) GetLobbyId() uint32 {
	if x != nil {
		return x.LobbyId
	}
	return 0
}

func (x *GameConfigInfo) GetLoglevel() uint32 {
	if x != nil {
		return x.Loglevel
	}
	return 0
}

func (x *GameConfigInfo) GetServerType() uint32 {
	if x != nil {
		return x.ServerType
	}
	return 0
}

func (x *GameConfigInfo) GetMqTopics() []string {
	if x != nil {
		return x.MqTopics
	}
	return nil
}

func (x *GameConfigInfo) GetAccessPoint() string {
	if x != nil {
		return x.AccessPoint
	}
	return ""
}

func (x *GameConfigInfo) GetMessageBodySize() uint32 {
	if x != nil {
		return x.MessageBodySize
	}
	return 0
}

func (x *GameConfigInfo) GetTotal() uint32 {
	if x != nil {
		return x.Total
	}
	return 0
}

func (x *GameConfigInfo) GetAccessKey() string {
	if x != nil {
		return x.AccessKey
	}
	return ""
}

func (x *GameConfigInfo) GetAccessSecret() string {
	if x != nil {
		return x.AccessSecret
	}
	return ""
}

type LobbyConfigInfo struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	LobbyId  uint32 `protobuf:"varint,1,opt,name=lobby_id,json=lobbyId,proto3" json:"lobby_id,omitempty"`
	Loglevel uint32 `protobuf:"varint,3,opt,name=loglevel,proto3" json:"loglevel,omitempty"`
}

func (x *LobbyConfigInfo) Reset() {
	*x = LobbyConfigInfo{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_deploy_config_proto_msgTypes[3]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *LobbyConfigInfo) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*LobbyConfigInfo) ProtoMessage() {}

func (x *LobbyConfigInfo) ProtoReflect() protoreflect.Message {
	mi := &file_common_deploy_config_proto_msgTypes[3]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use LobbyConfigInfo.ProtoReflect.Descriptor instead.
func (*LobbyConfigInfo) Descriptor() ([]byte, []int) {
	return file_common_deploy_config_proto_rawDescGZIP(), []int{3}
}

func (x *LobbyConfigInfo) GetLobbyId() uint32 {
	if x != nil {
		return x.LobbyId
	}
	return 0
}

func (x *LobbyConfigInfo) GetLoglevel() uint32 {
	if x != nil {
		return x.Loglevel
	}
	return 0
}

var File_common_deploy_config_proto protoreflect.FileDescriptor

var file_common_deploy_config_proto_rawDesc = []byte{
	0x0a, 0x1a, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2f, 0x64, 0x65, 0x70, 0x6c, 0x6f, 0x79, 0x5f,
	0x63, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x22, 0xbd, 0x01, 0x0a,
	0x0e, 0x43, 0x6f, 0x6e, 0x6e, 0x65, 0x74, 0x69, 0x6f, 0x6e, 0x50, 0x61, 0x72, 0x61, 0x6d, 0x12,
	0x0e, 0x0a, 0x02, 0x69, 0x70, 0x18, 0x01, 0x20, 0x01, 0x28, 0x09, 0x52, 0x02, 0x69, 0x70, 0x12,
	0x12, 0x0a, 0x04, 0x70, 0x6f, 0x72, 0x74, 0x18, 0x02, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x04, 0x70,
	0x6f, 0x72, 0x74, 0x12, 0x17, 0x0a, 0x07, 0x64, 0x62, 0x5f, 0x68, 0x6f, 0x73, 0x74, 0x18, 0x03,
	0x20, 0x01, 0x28, 0x09, 0x52, 0x06, 0x64, 0x62, 0x48, 0x6f, 0x73, 0x74, 0x12, 0x17, 0x0a, 0x07,
	0x64, 0x62, 0x5f, 0x75, 0x73, 0x65, 0x72, 0x18, 0x04, 0x20, 0x01, 0x28, 0x09, 0x52, 0x06, 0x64,
	0x62, 0x55, 0x73, 0x65, 0x72, 0x12, 0x1f, 0x0a, 0x0b, 0x64, 0x62, 0x5f, 0x70, 0x61, 0x73, 0x73,
	0x77, 0x6f, 0x72, 0x64, 0x18, 0x05, 0x20, 0x01, 0x28, 0x09, 0x52, 0x0a, 0x64, 0x62, 0x50, 0x61,
	0x73, 0x73, 0x77, 0x6f, 0x72, 0x64, 0x12, 0x17, 0x0a, 0x07, 0x64, 0x62, 0x5f, 0x70, 0x6f, 0x72,
	0x74, 0x18, 0x06, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x06, 0x64, 0x62, 0x50, 0x6f, 0x72, 0x74, 0x12,
	0x1b, 0x0a, 0x09, 0x64, 0x62, 0x5f, 0x64, 0x62, 0x6e, 0x61, 0x6d, 0x65, 0x18, 0x07, 0x20, 0x01,
	0x28, 0x09, 0x52, 0x08, 0x64, 0x62, 0x44, 0x62, 0x6e, 0x61, 0x6d, 0x65, 0x22, 0x3f, 0x0a, 0x18,
	0x43, 0x6f, 0x6e, 0x6e, 0x65, 0x74, 0x69, 0x6f, 0x6e, 0x50, 0x61, 0x72, 0x61, 0x6d, 0x4a, 0x73,
	0x6f, 0x6e, 0x46, 0x6f, 0x72, 0x6d, 0x61, 0x74, 0x12, 0x23, 0x0a, 0x04, 0x64, 0x61, 0x74, 0x61,
	0x18, 0x01, 0x20, 0x03, 0x28, 0x0b, 0x32, 0x0f, 0x2e, 0x43, 0x6f, 0x6e, 0x6e, 0x65, 0x74, 0x69,
	0x6f, 0x6e, 0x50, 0x61, 0x72, 0x61, 0x6d, 0x52, 0x04, 0x64, 0x61, 0x74, 0x61, 0x22, 0xc7, 0x02,
	0x0a, 0x0e, 0x47, 0x61, 0x6d, 0x65, 0x43, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x49, 0x6e, 0x66, 0x6f,
	0x12, 0x17, 0x0a, 0x07, 0x7a, 0x6f, 0x6e, 0x65, 0x5f, 0x69, 0x64, 0x18, 0x01, 0x20, 0x01, 0x28,
	0x0d, 0x52, 0x06, 0x7a, 0x6f, 0x6e, 0x65, 0x49, 0x64, 0x12, 0x19, 0x0a, 0x08, 0x6c, 0x6f, 0x62,
	0x62, 0x79, 0x5f, 0x69, 0x64, 0x18, 0x02, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x07, 0x6c, 0x6f, 0x62,
	0x62, 0x79, 0x49, 0x64, 0x12, 0x1a, 0x0a, 0x08, 0x6c, 0x6f, 0x67, 0x6c, 0x65, 0x76, 0x65, 0x6c,
	0x18, 0x03, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x08, 0x6c, 0x6f, 0x67, 0x6c, 0x65, 0x76, 0x65, 0x6c,
	0x12, 0x1f, 0x0a, 0x0b, 0x73, 0x65, 0x72, 0x76, 0x65, 0x72, 0x5f, 0x74, 0x79, 0x70, 0x65, 0x18,
	0x04, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x0a, 0x73, 0x65, 0x72, 0x76, 0x65, 0x72, 0x54, 0x79, 0x70,
	0x65, 0x12, 0x1b, 0x0a, 0x09, 0x6d, 0x71, 0x5f, 0x74, 0x6f, 0x70, 0x69, 0x63, 0x73, 0x18, 0x05,
	0x20, 0x03, 0x28, 0x09, 0x52, 0x08, 0x6d, 0x71, 0x54, 0x6f, 0x70, 0x69, 0x63, 0x73, 0x12, 0x21,
	0x0a, 0x0c, 0x61, 0x63, 0x63, 0x65, 0x73, 0x73, 0x5f, 0x70, 0x6f, 0x69, 0x6e, 0x74, 0x18, 0x06,
	0x20, 0x01, 0x28, 0x09, 0x52, 0x0b, 0x61, 0x63, 0x63, 0x65, 0x73, 0x73, 0x50, 0x6f, 0x69, 0x6e,
	0x74, 0x12, 0x2a, 0x0a, 0x11, 0x6d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x5f, 0x62, 0x6f, 0x64,
	0x79, 0x5f, 0x73, 0x69, 0x7a, 0x65, 0x18, 0x07, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x0f, 0x6d, 0x65,
	0x73, 0x73, 0x61, 0x67, 0x65, 0x42, 0x6f, 0x64, 0x79, 0x53, 0x69, 0x7a, 0x65, 0x12, 0x14, 0x0a,
	0x05, 0x74, 0x6f, 0x74, 0x61, 0x6c, 0x18, 0x08, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x05, 0x74, 0x6f,
	0x74, 0x61, 0x6c, 0x12, 0x1d, 0x0a, 0x0a, 0x61, 0x63, 0x63, 0x65, 0x73, 0x73, 0x5f, 0x6b, 0x65,
	0x79, 0x18, 0x09, 0x20, 0x01, 0x28, 0x09, 0x52, 0x09, 0x61, 0x63, 0x63, 0x65, 0x73, 0x73, 0x4b,
	0x65, 0x79, 0x12, 0x23, 0x0a, 0x0d, 0x61, 0x63, 0x63, 0x65, 0x73, 0x73, 0x5f, 0x73, 0x65, 0x63,
	0x72, 0x65, 0x74, 0x18, 0x0a, 0x20, 0x01, 0x28, 0x09, 0x52, 0x0c, 0x61, 0x63, 0x63, 0x65, 0x73,
	0x73, 0x53, 0x65, 0x63, 0x72, 0x65, 0x74, 0x22, 0x48, 0x0a, 0x0f, 0x4c, 0x6f, 0x62, 0x62, 0x79,
	0x43, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x49, 0x6e, 0x66, 0x6f, 0x12, 0x19, 0x0a, 0x08, 0x6c, 0x6f,
	0x62, 0x62, 0x79, 0x5f, 0x69, 0x64, 0x18, 0x01, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x07, 0x6c, 0x6f,
	0x62, 0x62, 0x79, 0x49, 0x64, 0x12, 0x1a, 0x0a, 0x08, 0x6c, 0x6f, 0x67, 0x6c, 0x65, 0x76, 0x65,
	0x6c, 0x18, 0x03, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x08, 0x6c, 0x6f, 0x67, 0x6c, 0x65, 0x76, 0x65,
	0x6c, 0x42, 0x09, 0x5a, 0x07, 0x70, 0x62, 0x2f, 0x67, 0x61, 0x6d, 0x65, 0x62, 0x06, 0x70, 0x72,
	0x6f, 0x74, 0x6f, 0x33,
}

var (
	file_common_deploy_config_proto_rawDescOnce sync.Once
	file_common_deploy_config_proto_rawDescData = file_common_deploy_config_proto_rawDesc
)

func file_common_deploy_config_proto_rawDescGZIP() []byte {
	file_common_deploy_config_proto_rawDescOnce.Do(func() {
		file_common_deploy_config_proto_rawDescData = protoimpl.X.CompressGZIP(file_common_deploy_config_proto_rawDescData)
	})
	return file_common_deploy_config_proto_rawDescData
}

var file_common_deploy_config_proto_msgTypes = make([]protoimpl.MessageInfo, 4)
var file_common_deploy_config_proto_goTypes = []interface{}{
	(*ConnetionParam)(nil),           // 0: ConnetionParam
	(*ConnetionParamJsonFormat)(nil), // 1: ConnetionParamJsonFormat
	(*GameConfigInfo)(nil),           // 2: GameConfigInfo
	(*LobbyConfigInfo)(nil),          // 3: LobbyConfigInfo
}
var file_common_deploy_config_proto_depIdxs = []int32{
	0, // 0: ConnetionParamJsonFormat.data:type_name -> ConnetionParam
	1, // [1:1] is the sub-list for method output_type
	1, // [1:1] is the sub-list for method input_type
	1, // [1:1] is the sub-list for extension type_name
	1, // [1:1] is the sub-list for extension extendee
	0, // [0:1] is the sub-list for field type_name
}

func init() { file_common_deploy_config_proto_init() }
func file_common_deploy_config_proto_init() {
	if File_common_deploy_config_proto != nil {
		return
	}
	if !protoimpl.UnsafeEnabled {
		file_common_deploy_config_proto_msgTypes[0].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*ConnetionParam); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_common_deploy_config_proto_msgTypes[1].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*ConnetionParamJsonFormat); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_common_deploy_config_proto_msgTypes[2].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*GameConfigInfo); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_common_deploy_config_proto_msgTypes[3].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*LobbyConfigInfo); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
	}
	type x struct{}
	out := protoimpl.TypeBuilder{
		File: protoimpl.DescBuilder{
			GoPackagePath: reflect.TypeOf(x{}).PkgPath(),
			RawDescriptor: file_common_deploy_config_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   4,
			NumExtensions: 0,
			NumServices:   0,
		},
		GoTypes:           file_common_deploy_config_proto_goTypes,
		DependencyIndexes: file_common_deploy_config_proto_depIdxs,
		MessageInfos:      file_common_deploy_config_proto_msgTypes,
	}.Build()
	File_common_deploy_config_proto = out.File
	file_common_deploy_config_proto_rawDesc = nil
	file_common_deploy_config_proto_goTypes = nil
	file_common_deploy_config_proto_depIdxs = nil
}
