// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.34.2
// 	protoc        v5.26.1
// source: logic/server_player/centre_server_player_scene.proto

package game

import (
	protoreflect "google.golang.org/protobuf/reflect/protoreflect"
	protoimpl "google.golang.org/protobuf/runtime/protoimpl"
	emptypb "google.golang.org/protobuf/types/known/emptypb"
	reflect "reflect"
	sync "sync"
)

const (
	// Verify that this generated code is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(20 - protoimpl.MinVersion)
	// Verify that runtime/protoimpl is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(protoimpl.MaxVersion - 20)
)

type CentreEnterSceneRequest struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	SceneInfo *SceneInfo `protobuf:"bytes,1,opt,name=scene_info,json=sceneInfo,proto3" json:"scene_info,omitempty"`
}

func (x *CentreEnterSceneRequest) Reset() {
	*x = CentreEnterSceneRequest{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_server_player_centre_server_player_scene_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *CentreEnterSceneRequest) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*CentreEnterSceneRequest) ProtoMessage() {}

func (x *CentreEnterSceneRequest) ProtoReflect() protoreflect.Message {
	mi := &file_logic_server_player_centre_server_player_scene_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use CentreEnterSceneRequest.ProtoReflect.Descriptor instead.
func (*CentreEnterSceneRequest) Descriptor() ([]byte, []int) {
	return file_logic_server_player_centre_server_player_scene_proto_rawDescGZIP(), []int{0}
}

func (x *CentreEnterSceneRequest) GetSceneInfo() *SceneInfo {
	if x != nil {
		return x.SceneInfo
	}
	return nil
}

type CentreLeaveSceneRequest struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields
}

func (x *CentreLeaveSceneRequest) Reset() {
	*x = CentreLeaveSceneRequest{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_server_player_centre_server_player_scene_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *CentreLeaveSceneRequest) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*CentreLeaveSceneRequest) ProtoMessage() {}

func (x *CentreLeaveSceneRequest) ProtoReflect() protoreflect.Message {
	mi := &file_logic_server_player_centre_server_player_scene_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use CentreLeaveSceneRequest.ProtoReflect.Descriptor instead.
func (*CentreLeaveSceneRequest) Descriptor() ([]byte, []int) {
	return file_logic_server_player_centre_server_player_scene_proto_rawDescGZIP(), []int{1}
}

type CentreLeaveSceneAsyncSavePlayerCompleteRequest struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields
}

func (x *CentreLeaveSceneAsyncSavePlayerCompleteRequest) Reset() {
	*x = CentreLeaveSceneAsyncSavePlayerCompleteRequest{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_server_player_centre_server_player_scene_proto_msgTypes[2]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *CentreLeaveSceneAsyncSavePlayerCompleteRequest) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*CentreLeaveSceneAsyncSavePlayerCompleteRequest) ProtoMessage() {}

func (x *CentreLeaveSceneAsyncSavePlayerCompleteRequest) ProtoReflect() protoreflect.Message {
	mi := &file_logic_server_player_centre_server_player_scene_proto_msgTypes[2]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use CentreLeaveSceneAsyncSavePlayerCompleteRequest.ProtoReflect.Descriptor instead.
func (*CentreLeaveSceneAsyncSavePlayerCompleteRequest) Descriptor() ([]byte, []int) {
	return file_logic_server_player_centre_server_player_scene_proto_rawDescGZIP(), []int{2}
}

var File_logic_server_player_centre_server_player_scene_proto protoreflect.FileDescriptor

var file_logic_server_player_centre_server_player_scene_proto_rawDesc = []byte{
	0x0a, 0x34, 0x6c, 0x6f, 0x67, 0x69, 0x63, 0x2f, 0x73, 0x65, 0x72, 0x76, 0x65, 0x72, 0x5f, 0x70,
	0x6c, 0x61, 0x79, 0x65, 0x72, 0x2f, 0x63, 0x65, 0x6e, 0x74, 0x72, 0x65, 0x5f, 0x73, 0x65, 0x72,
	0x76, 0x65, 0x72, 0x5f, 0x70, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x5f, 0x73, 0x63, 0x65, 0x6e, 0x65,
	0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x1a, 0x1b, 0x67, 0x6f, 0x6f, 0x67, 0x6c, 0x65, 0x2f, 0x70,
	0x72, 0x6f, 0x74, 0x6f, 0x62, 0x75, 0x66, 0x2f, 0x65, 0x6d, 0x70, 0x74, 0x79, 0x2e, 0x70, 0x72,
	0x6f, 0x74, 0x6f, 0x1a, 0x20, 0x6c, 0x6f, 0x67, 0x69, 0x63, 0x2f, 0x63, 0x6f, 0x6d, 0x70, 0x6f,
	0x6e, 0x65, 0x6e, 0x74, 0x2f, 0x73, 0x63, 0x65, 0x6e, 0x65, 0x5f, 0x63, 0x6f, 0x6d, 0x70, 0x2e,
	0x70, 0x72, 0x6f, 0x74, 0x6f, 0x1a, 0x26, 0x6c, 0x6f, 0x67, 0x69, 0x63, 0x2f, 0x63, 0x6c, 0x69,
	0x65, 0x6e, 0x74, 0x5f, 0x70, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x2f, 0x70, 0x6c, 0x61, 0x79, 0x65,
	0x72, 0x5f, 0x73, 0x63, 0x65, 0x6e, 0x65, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x22, 0x44, 0x0a,
	0x17, 0x43, 0x65, 0x6e, 0x74, 0x72, 0x65, 0x45, 0x6e, 0x74, 0x65, 0x72, 0x53, 0x63, 0x65, 0x6e,
	0x65, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x12, 0x29, 0x0a, 0x0a, 0x73, 0x63, 0x65, 0x6e,
	0x65, 0x5f, 0x69, 0x6e, 0x66, 0x6f, 0x18, 0x01, 0x20, 0x01, 0x28, 0x0b, 0x32, 0x0a, 0x2e, 0x53,
	0x63, 0x65, 0x6e, 0x65, 0x49, 0x6e, 0x66, 0x6f, 0x52, 0x09, 0x73, 0x63, 0x65, 0x6e, 0x65, 0x49,
	0x6e, 0x66, 0x6f, 0x22, 0x19, 0x0a, 0x17, 0x43, 0x65, 0x6e, 0x74, 0x72, 0x65, 0x4c, 0x65, 0x61,
	0x76, 0x65, 0x53, 0x63, 0x65, 0x6e, 0x65, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x22, 0x30,
	0x0a, 0x2e, 0x43, 0x65, 0x6e, 0x74, 0x72, 0x65, 0x4c, 0x65, 0x61, 0x76, 0x65, 0x53, 0x63, 0x65,
	0x6e, 0x65, 0x41, 0x73, 0x79, 0x6e, 0x63, 0x53, 0x61, 0x76, 0x65, 0x50, 0x6c, 0x61, 0x79, 0x65,
	0x72, 0x43, 0x6f, 0x6d, 0x70, 0x6c, 0x65, 0x74, 0x65, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74,
	0x32, 0xc3, 0x02, 0x0a, 0x18, 0x43, 0x65, 0x6e, 0x74, 0x72, 0x65, 0x50, 0x6c, 0x61, 0x79, 0x65,
	0x72, 0x53, 0x63, 0x65, 0x6e, 0x65, 0x53, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x12, 0x3e, 0x0a,
	0x0a, 0x45, 0x6e, 0x74, 0x65, 0x72, 0x53, 0x63, 0x65, 0x6e, 0x65, 0x12, 0x18, 0x2e, 0x43, 0x65,
	0x6e, 0x74, 0x72, 0x65, 0x45, 0x6e, 0x74, 0x65, 0x72, 0x53, 0x63, 0x65, 0x6e, 0x65, 0x52, 0x65,
	0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x16, 0x2e, 0x67, 0x6f, 0x6f, 0x67, 0x6c, 0x65, 0x2e, 0x70,
	0x72, 0x6f, 0x74, 0x6f, 0x62, 0x75, 0x66, 0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x12, 0x3e, 0x0a,
	0x0a, 0x4c, 0x65, 0x61, 0x76, 0x65, 0x53, 0x63, 0x65, 0x6e, 0x65, 0x12, 0x18, 0x2e, 0x43, 0x65,
	0x6e, 0x74, 0x72, 0x65, 0x4c, 0x65, 0x61, 0x76, 0x65, 0x53, 0x63, 0x65, 0x6e, 0x65, 0x52, 0x65,
	0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x16, 0x2e, 0x67, 0x6f, 0x6f, 0x67, 0x6c, 0x65, 0x2e, 0x70,
	0x72, 0x6f, 0x74, 0x6f, 0x62, 0x75, 0x66, 0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x12, 0x6c, 0x0a,
	0x21, 0x4c, 0x65, 0x61, 0x76, 0x65, 0x53, 0x63, 0x65, 0x6e, 0x65, 0x41, 0x73, 0x79, 0x6e, 0x63,
	0x53, 0x61, 0x76, 0x65, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x43, 0x6f, 0x6d, 0x70, 0x6c, 0x65,
	0x74, 0x65, 0x12, 0x2f, 0x2e, 0x43, 0x65, 0x6e, 0x74, 0x72, 0x65, 0x4c, 0x65, 0x61, 0x76, 0x65,
	0x53, 0x63, 0x65, 0x6e, 0x65, 0x41, 0x73, 0x79, 0x6e, 0x63, 0x53, 0x61, 0x76, 0x65, 0x50, 0x6c,
	0x61, 0x79, 0x65, 0x72, 0x43, 0x6f, 0x6d, 0x70, 0x6c, 0x65, 0x74, 0x65, 0x52, 0x65, 0x71, 0x75,
	0x65, 0x73, 0x74, 0x1a, 0x16, 0x2e, 0x67, 0x6f, 0x6f, 0x67, 0x6c, 0x65, 0x2e, 0x70, 0x72, 0x6f,
	0x74, 0x6f, 0x62, 0x75, 0x66, 0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x12, 0x39, 0x0a, 0x0c, 0x53,
	0x63, 0x65, 0x6e, 0x65, 0x49, 0x6e, 0x66, 0x6f, 0x43, 0x32, 0x53, 0x12, 0x11, 0x2e, 0x53, 0x63,
	0x65, 0x6e, 0x65, 0x49, 0x6e, 0x66, 0x6f, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x16,
	0x2e, 0x67, 0x6f, 0x6f, 0x67, 0x6c, 0x65, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x62, 0x75, 0x66,
	0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x42, 0x0c, 0x5a, 0x07, 0x70, 0x62, 0x2f, 0x67, 0x61, 0x6d,
	0x65, 0x80, 0x01, 0x01, 0x62, 0x06, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x33,
}

var (
	file_logic_server_player_centre_server_player_scene_proto_rawDescOnce sync.Once
	file_logic_server_player_centre_server_player_scene_proto_rawDescData = file_logic_server_player_centre_server_player_scene_proto_rawDesc
)

func file_logic_server_player_centre_server_player_scene_proto_rawDescGZIP() []byte {
	file_logic_server_player_centre_server_player_scene_proto_rawDescOnce.Do(func() {
		file_logic_server_player_centre_server_player_scene_proto_rawDescData = protoimpl.X.CompressGZIP(file_logic_server_player_centre_server_player_scene_proto_rawDescData)
	})
	return file_logic_server_player_centre_server_player_scene_proto_rawDescData
}

var file_logic_server_player_centre_server_player_scene_proto_msgTypes = make([]protoimpl.MessageInfo, 3)
var file_logic_server_player_centre_server_player_scene_proto_goTypes = []any{
	(*CentreEnterSceneRequest)(nil),                        // 0: CentreEnterSceneRequest
	(*CentreLeaveSceneRequest)(nil),                        // 1: CentreLeaveSceneRequest
	(*CentreLeaveSceneAsyncSavePlayerCompleteRequest)(nil), // 2: CentreLeaveSceneAsyncSavePlayerCompleteRequest
	(*SceneInfo)(nil),                                      // 3: SceneInfo
	(*SceneInfoRequest)(nil),                               // 4: SceneInfoRequest
	(*emptypb.Empty)(nil),                                  // 5: google.protobuf.Empty
}
var file_logic_server_player_centre_server_player_scene_proto_depIdxs = []int32{
	3, // 0: CentreEnterSceneRequest.scene_info:type_name -> SceneInfo
	0, // 1: CentrePlayerSceneService.EnterScene:input_type -> CentreEnterSceneRequest
	1, // 2: CentrePlayerSceneService.LeaveScene:input_type -> CentreLeaveSceneRequest
	2, // 3: CentrePlayerSceneService.LeaveSceneAsyncSavePlayerComplete:input_type -> CentreLeaveSceneAsyncSavePlayerCompleteRequest
	4, // 4: CentrePlayerSceneService.SceneInfoC2S:input_type -> SceneInfoRequest
	5, // 5: CentrePlayerSceneService.EnterScene:output_type -> google.protobuf.Empty
	5, // 6: CentrePlayerSceneService.LeaveScene:output_type -> google.protobuf.Empty
	5, // 7: CentrePlayerSceneService.LeaveSceneAsyncSavePlayerComplete:output_type -> google.protobuf.Empty
	5, // 8: CentrePlayerSceneService.SceneInfoC2S:output_type -> google.protobuf.Empty
	5, // [5:9] is the sub-list for method output_type
	1, // [1:5] is the sub-list for method input_type
	1, // [1:1] is the sub-list for extension type_name
	1, // [1:1] is the sub-list for extension extendee
	0, // [0:1] is the sub-list for field type_name
}

func init() { file_logic_server_player_centre_server_player_scene_proto_init() }
func file_logic_server_player_centre_server_player_scene_proto_init() {
	if File_logic_server_player_centre_server_player_scene_proto != nil {
		return
	}
	file_logic_component_scene_comp_proto_init()
	file_logic_client_player_player_scene_proto_init()
	if !protoimpl.UnsafeEnabled {
		file_logic_server_player_centre_server_player_scene_proto_msgTypes[0].Exporter = func(v any, i int) any {
			switch v := v.(*CentreEnterSceneRequest); i {
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
		file_logic_server_player_centre_server_player_scene_proto_msgTypes[1].Exporter = func(v any, i int) any {
			switch v := v.(*CentreLeaveSceneRequest); i {
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
		file_logic_server_player_centre_server_player_scene_proto_msgTypes[2].Exporter = func(v any, i int) any {
			switch v := v.(*CentreLeaveSceneAsyncSavePlayerCompleteRequest); i {
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
			RawDescriptor: file_logic_server_player_centre_server_player_scene_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   3,
			NumExtensions: 0,
			NumServices:   1,
		},
		GoTypes:           file_logic_server_player_centre_server_player_scene_proto_goTypes,
		DependencyIndexes: file_logic_server_player_centre_server_player_scene_proto_depIdxs,
		MessageInfos:      file_logic_server_player_centre_server_player_scene_proto_msgTypes,
	}.Build()
	File_logic_server_player_centre_server_player_scene_proto = out.File
	file_logic_server_player_centre_server_player_scene_proto_rawDesc = nil
	file_logic_server_player_centre_server_player_scene_proto_goTypes = nil
	file_logic_server_player_centre_server_player_scene_proto_depIdxs = nil
}
