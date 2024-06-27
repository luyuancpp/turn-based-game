// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.34.1
// 	protoc        v4.25.1
// source: common_proto/gate_service.proto

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

type GsMessageExtern struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	SessionId uint64 `protobuf:"varint,1,opt,name=session_id,json=sessionId,proto3" json:"session_id,omitempty"`
}

func (x *GsMessageExtern) Reset() {
	*x = GsMessageExtern{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_proto_gate_service_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *GsMessageExtern) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*GsMessageExtern) ProtoMessage() {}

func (x *GsMessageExtern) ProtoReflect() protoreflect.Message {
	mi := &file_common_proto_gate_service_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use GsMessageExtern.ProtoReflect.Descriptor instead.
func (*GsMessageExtern) Descriptor() ([]byte, []int) {
	return file_common_proto_gate_service_proto_rawDescGZIP(), []int{0}
}

func (x *GsMessageExtern) GetSessionId() uint64 {
	if x != nil {
		return x.SessionId
	}
	return 0
}

type GateNodeKickConnRequest struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	SessionId uint64 `protobuf:"varint,1,opt,name=session_id,json=sessionId,proto3" json:"session_id,omitempty"`
}

func (x *GateNodeKickConnRequest) Reset() {
	*x = GateNodeKickConnRequest{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_proto_gate_service_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *GateNodeKickConnRequest) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*GateNodeKickConnRequest) ProtoMessage() {}

func (x *GateNodeKickConnRequest) ProtoReflect() protoreflect.Message {
	mi := &file_common_proto_gate_service_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use GateNodeKickConnRequest.ProtoReflect.Descriptor instead.
func (*GateNodeKickConnRequest) Descriptor() ([]byte, []int) {
	return file_common_proto_gate_service_proto_rawDescGZIP(), []int{1}
}

func (x *GateNodeKickConnRequest) GetSessionId() uint64 {
	if x != nil {
		return x.SessionId
	}
	return 0
}

var File_common_proto_gate_service_proto protoreflect.FileDescriptor

var file_common_proto_gate_service_proto_rawDesc = []byte{
	0x0a, 0x1f, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x5f, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x2f, 0x67,
	0x61, 0x74, 0x65, 0x5f, 0x73, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x2e, 0x70, 0x72, 0x6f, 0x74,
	0x6f, 0x1a, 0x18, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x5f, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x2f,
	0x65, 0x6d, 0x70, 0x74, 0x79, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x1a, 0x19, 0x63, 0x6f, 0x6d,
	0x6d, 0x6f, 0x6e, 0x5f, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x2f, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e,
	0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x1a, 0x1e, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x5f, 0x70,
	0x72, 0x6f, 0x74, 0x6f, 0x2f, 0x6e, 0x6f, 0x64, 0x65, 0x5f, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e,
	0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x1a, 0x21, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x5f, 0x70,
	0x72, 0x6f, 0x74, 0x6f, 0x2f, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x5f, 0x6d, 0x65, 0x73, 0x73,
	0x61, 0x67, 0x65, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x22, 0x30, 0x0a, 0x0f, 0x47, 0x73, 0x4d,
	0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x45, 0x78, 0x74, 0x65, 0x72, 0x6e, 0x12, 0x1d, 0x0a, 0x0a,
	0x73, 0x65, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x5f, 0x69, 0x64, 0x18, 0x01, 0x20, 0x01, 0x28, 0x04,
	0x52, 0x09, 0x73, 0x65, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x49, 0x64, 0x22, 0x38, 0x0a, 0x17, 0x47,
	0x61, 0x74, 0x65, 0x4e, 0x6f, 0x64, 0x65, 0x4b, 0x69, 0x63, 0x6b, 0x43, 0x6f, 0x6e, 0x6e, 0x52,
	0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x12, 0x1d, 0x0a, 0x0a, 0x73, 0x65, 0x73, 0x73, 0x69, 0x6f,
	0x6e, 0x5f, 0x69, 0x64, 0x18, 0x01, 0x20, 0x01, 0x28, 0x04, 0x52, 0x09, 0x73, 0x65, 0x73, 0x73,
	0x69, 0x6f, 0x6e, 0x49, 0x64, 0x32, 0xc6, 0x03, 0x0a, 0x0b, 0x47, 0x61, 0x74, 0x65, 0x53, 0x65,
	0x72, 0x76, 0x69, 0x63, 0x65, 0x12, 0x2c, 0x0a, 0x0c, 0x52, 0x65, 0x67, 0x69, 0x73, 0x74, 0x65,
	0x72, 0x47, 0x61, 0x6d, 0x65, 0x12, 0x14, 0x2e, 0x52, 0x65, 0x67, 0x69, 0x73, 0x74, 0x65, 0x72,
	0x47, 0x61, 0x6d, 0x65, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x06, 0x2e, 0x45, 0x6d,
	0x70, 0x74, 0x79, 0x12, 0x30, 0x0a, 0x0e, 0x55, 0x6e, 0x52, 0x65, 0x67, 0x69, 0x73, 0x74, 0x65,
	0x72, 0x47, 0x61, 0x6d, 0x65, 0x12, 0x16, 0x2e, 0x55, 0x6e, 0x52, 0x65, 0x67, 0x69, 0x73, 0x74,
	0x65, 0x72, 0x47, 0x61, 0x6d, 0x65, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x06, 0x2e,
	0x45, 0x6d, 0x70, 0x74, 0x79, 0x12, 0x52, 0x0a, 0x0d, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x45,
	0x6e, 0x74, 0x65, 0x72, 0x47, 0x73, 0x12, 0x1f, 0x2e, 0x52, 0x65, 0x67, 0x69, 0x73, 0x74, 0x65,
	0x72, 0x53, 0x65, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x47, 0x61, 0x6d, 0x65, 0x4e, 0x6f, 0x64, 0x65,
	0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x20, 0x2e, 0x52, 0x65, 0x67, 0x69, 0x73, 0x74,
	0x65, 0x72, 0x53, 0x65, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x47, 0x61, 0x6d, 0x65, 0x4e, 0x6f, 0x64,
	0x65, 0x52, 0x65, 0x73, 0x70, 0x6f, 0x6e, 0x73, 0x65, 0x12, 0x31, 0x0a, 0x0d, 0x50, 0x6c, 0x61,
	0x79, 0x65, 0x72, 0x4d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x12, 0x18, 0x2e, 0x4e, 0x6f, 0x64,
	0x65, 0x52, 0x6f, 0x75, 0x74, 0x65, 0x4d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x52, 0x65, 0x71,
	0x75, 0x65, 0x73, 0x74, 0x1a, 0x06, 0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x12, 0x34, 0x0a, 0x10,
	0x4b, 0x69, 0x63, 0x6b, 0x43, 0x6f, 0x6e, 0x6e, 0x42, 0x79, 0x43, 0x65, 0x6e, 0x74, 0x72, 0x65,
	0x12, 0x18, 0x2e, 0x47, 0x61, 0x74, 0x65, 0x4e, 0x6f, 0x64, 0x65, 0x4b, 0x69, 0x63, 0x6b, 0x43,
	0x6f, 0x6e, 0x6e, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x06, 0x2e, 0x45, 0x6d, 0x70,
	0x74, 0x79, 0x12, 0x45, 0x0a, 0x12, 0x52, 0x6f, 0x75, 0x74, 0x65, 0x4e, 0x6f, 0x64, 0x65, 0x53,
	0x74, 0x72, 0x69, 0x6e, 0x67, 0x4d, 0x73, 0x67, 0x12, 0x16, 0x2e, 0x52, 0x6f, 0x75, 0x74, 0x65,
	0x4d, 0x73, 0x67, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74,
	0x1a, 0x17, 0x2e, 0x52, 0x6f, 0x75, 0x74, 0x65, 0x4d, 0x73, 0x67, 0x53, 0x74, 0x72, 0x69, 0x6e,
	0x67, 0x52, 0x65, 0x73, 0x70, 0x6f, 0x6e, 0x73, 0x65, 0x12, 0x53, 0x0a, 0x14, 0x52, 0x6f, 0x75,
	0x74, 0x65, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x4d, 0x73,
	0x67, 0x12, 0x1c, 0x2e, 0x52, 0x6f, 0x75, 0x74, 0x65, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x4d,
	0x73, 0x67, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a,
	0x1d, 0x2e, 0x52, 0x6f, 0x75, 0x74, 0x65, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x4d, 0x73, 0x67,
	0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x52, 0x65, 0x73, 0x70, 0x6f, 0x6e, 0x73, 0x65, 0x42, 0x0c,
	0x5a, 0x07, 0x70, 0x62, 0x2f, 0x67, 0x61, 0x6d, 0x65, 0x80, 0x01, 0x01, 0x62, 0x06, 0x70, 0x72,
	0x6f, 0x74, 0x6f, 0x33,
}

var (
	file_common_proto_gate_service_proto_rawDescOnce sync.Once
	file_common_proto_gate_service_proto_rawDescData = file_common_proto_gate_service_proto_rawDesc
)

func file_common_proto_gate_service_proto_rawDescGZIP() []byte {
	file_common_proto_gate_service_proto_rawDescOnce.Do(func() {
		file_common_proto_gate_service_proto_rawDescData = protoimpl.X.CompressGZIP(file_common_proto_gate_service_proto_rawDescData)
	})
	return file_common_proto_gate_service_proto_rawDescData
}

var file_common_proto_gate_service_proto_msgTypes = make([]protoimpl.MessageInfo, 2)
var file_common_proto_gate_service_proto_goTypes = []interface{}{
	(*GsMessageExtern)(nil),                 // 0: GsMessageExtern
	(*GateNodeKickConnRequest)(nil),         // 1: GateNodeKickConnRequest
	(*RegisterGameRequest)(nil),             // 2: RegisterGameRequest
	(*UnRegisterGameRequest)(nil),           // 3: UnRegisterGameRequest
	(*RegisterSessionGameNodeRequest)(nil),  // 4: RegisterSessionGameNodeRequest
	(*NodeRouteMessageRequest)(nil),         // 5: NodeRouteMessageRequest
	(*RouteMsgStringRequest)(nil),           // 6: RouteMsgStringRequest
	(*RoutePlayerMsgStringRequest)(nil),     // 7: RoutePlayerMsgStringRequest
	(*Empty)(nil),                           // 8: Empty
	(*RegisterSessionGameNodeResponse)(nil), // 9: RegisterSessionGameNodeResponse
	(*RouteMsgStringResponse)(nil),          // 10: RouteMsgStringResponse
	(*RoutePlayerMsgStringResponse)(nil),    // 11: RoutePlayerMsgStringResponse
}
var file_common_proto_gate_service_proto_depIdxs = []int32{
	2,  // 0: GateService.RegisterGame:input_type -> RegisterGameRequest
	3,  // 1: GateService.UnRegisterGame:input_type -> UnRegisterGameRequest
	4,  // 2: GateService.PlayerEnterGs:input_type -> RegisterSessionGameNodeRequest
	5,  // 3: GateService.PlayerMessage:input_type -> NodeRouteMessageRequest
	1,  // 4: GateService.KickConnByCentre:input_type -> GateNodeKickConnRequest
	6,  // 5: GateService.RouteNodeStringMsg:input_type -> RouteMsgStringRequest
	7,  // 6: GateService.RoutePlayerStringMsg:input_type -> RoutePlayerMsgStringRequest
	8,  // 7: GateService.RegisterGame:output_type -> Empty
	8,  // 8: GateService.UnRegisterGame:output_type -> Empty
	9,  // 9: GateService.PlayerEnterGs:output_type -> RegisterSessionGameNodeResponse
	8,  // 10: GateService.PlayerMessage:output_type -> Empty
	8,  // 11: GateService.KickConnByCentre:output_type -> Empty
	10, // 12: GateService.RouteNodeStringMsg:output_type -> RouteMsgStringResponse
	11, // 13: GateService.RoutePlayerStringMsg:output_type -> RoutePlayerMsgStringResponse
	7,  // [7:14] is the sub-list for method output_type
	0,  // [0:7] is the sub-list for method input_type
	0,  // [0:0] is the sub-list for extension type_name
	0,  // [0:0] is the sub-list for extension extendee
	0,  // [0:0] is the sub-list for field type_name
}

func init() { file_common_proto_gate_service_proto_init() }
func file_common_proto_gate_service_proto_init() {
	if File_common_proto_gate_service_proto != nil {
		return
	}
	file_common_proto_empty_proto_init()
	file_common_proto_common_proto_init()
	file_common_proto_node_common_proto_init()
	file_common_proto_common_message_proto_init()
	if !protoimpl.UnsafeEnabled {
		file_common_proto_gate_service_proto_msgTypes[0].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*GsMessageExtern); i {
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
		file_common_proto_gate_service_proto_msgTypes[1].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*GateNodeKickConnRequest); i {
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
			RawDescriptor: file_common_proto_gate_service_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   2,
			NumExtensions: 0,
			NumServices:   1,
		},
		GoTypes:           file_common_proto_gate_service_proto_goTypes,
		DependencyIndexes: file_common_proto_gate_service_proto_depIdxs,
		MessageInfos:      file_common_proto_gate_service_proto_msgTypes,
	}.Build()
	File_common_proto_gate_service_proto = out.File
	file_common_proto_gate_service_proto_rawDesc = nil
	file_common_proto_gate_service_proto_goTypes = nil
	file_common_proto_gate_service_proto_depIdxs = nil
}
