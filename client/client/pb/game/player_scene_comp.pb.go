// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.34.1
// 	protoc        v5.26.1
// source: logic/component/player_scene_comp.proto

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

type PlayerSceneInfo struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	SceneConfid uint32 `protobuf:"varint,1,opt,name=scene_confid,json=sceneConfid,proto3" json:"scene_confid,omitempty"`
	Guid        uint32 `protobuf:"varint,2,opt,name=guid,proto3" json:"guid,omitempty"`
}

func (x *PlayerSceneInfo) Reset() {
	*x = PlayerSceneInfo{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_component_player_scene_comp_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *PlayerSceneInfo) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*PlayerSceneInfo) ProtoMessage() {}

func (x *PlayerSceneInfo) ProtoReflect() protoreflect.Message {
	mi := &file_logic_component_player_scene_comp_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use PlayerSceneInfo.ProtoReflect.Descriptor instead.
func (*PlayerSceneInfo) Descriptor() ([]byte, []int) {
	return file_logic_component_player_scene_comp_proto_rawDescGZIP(), []int{0}
}

func (x *PlayerSceneInfo) GetSceneConfid() uint32 {
	if x != nil {
		return x.SceneConfid
	}
	return 0
}

func (x *PlayerSceneInfo) GetGuid() uint32 {
	if x != nil {
		return x.Guid
	}
	return 0
}

type PlayerSceneInfoComp struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	SceneInfo         *PlayerSceneInfo `protobuf:"bytes,1,opt,name=scene_info,json=sceneInfo,proto3" json:"scene_info,omitempty"`
	SceneInfoLastTime *PlayerSceneInfo `protobuf:"bytes,2,opt,name=scene_info_last_time,json=sceneInfoLastTime,proto3" json:"scene_info_last_time,omitempty"`
}

func (x *PlayerSceneInfoComp) Reset() {
	*x = PlayerSceneInfoComp{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_component_player_scene_comp_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *PlayerSceneInfoComp) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*PlayerSceneInfoComp) ProtoMessage() {}

func (x *PlayerSceneInfoComp) ProtoReflect() protoreflect.Message {
	mi := &file_logic_component_player_scene_comp_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use PlayerSceneInfoComp.ProtoReflect.Descriptor instead.
func (*PlayerSceneInfoComp) Descriptor() ([]byte, []int) {
	return file_logic_component_player_scene_comp_proto_rawDescGZIP(), []int{1}
}

func (x *PlayerSceneInfoComp) GetSceneInfo() *PlayerSceneInfo {
	if x != nil {
		return x.SceneInfo
	}
	return nil
}

func (x *PlayerSceneInfoComp) GetSceneInfoLastTime() *PlayerSceneInfo {
	if x != nil {
		return x.SceneInfoLastTime
	}
	return nil
}

var File_logic_component_player_scene_comp_proto protoreflect.FileDescriptor

var file_logic_component_player_scene_comp_proto_rawDesc = []byte{
	0x0a, 0x27, 0x6c, 0x6f, 0x67, 0x69, 0x63, 0x2f, 0x63, 0x6f, 0x6d, 0x70, 0x6f, 0x6e, 0x65, 0x6e,
	0x74, 0x2f, 0x70, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x5f, 0x73, 0x63, 0x65, 0x6e, 0x65, 0x5f, 0x63,
	0x6f, 0x6d, 0x70, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x22, 0x48, 0x0a, 0x0f, 0x50, 0x6c, 0x61,
	0x79, 0x65, 0x72, 0x53, 0x63, 0x65, 0x6e, 0x65, 0x49, 0x6e, 0x66, 0x6f, 0x12, 0x21, 0x0a, 0x0c,
	0x73, 0x63, 0x65, 0x6e, 0x65, 0x5f, 0x63, 0x6f, 0x6e, 0x66, 0x69, 0x64, 0x18, 0x01, 0x20, 0x01,
	0x28, 0x0d, 0x52, 0x0b, 0x73, 0x63, 0x65, 0x6e, 0x65, 0x43, 0x6f, 0x6e, 0x66, 0x69, 0x64, 0x12,
	0x12, 0x0a, 0x04, 0x67, 0x75, 0x69, 0x64, 0x18, 0x02, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x04, 0x67,
	0x75, 0x69, 0x64, 0x22, 0x89, 0x01, 0x0a, 0x13, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x53, 0x63,
	0x65, 0x6e, 0x65, 0x49, 0x6e, 0x66, 0x6f, 0x43, 0x6f, 0x6d, 0x70, 0x12, 0x2f, 0x0a, 0x0a, 0x73,
	0x63, 0x65, 0x6e, 0x65, 0x5f, 0x69, 0x6e, 0x66, 0x6f, 0x18, 0x01, 0x20, 0x01, 0x28, 0x0b, 0x32,
	0x10, 0x2e, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x53, 0x63, 0x65, 0x6e, 0x65, 0x49, 0x6e, 0x66,
	0x6f, 0x52, 0x09, 0x73, 0x63, 0x65, 0x6e, 0x65, 0x49, 0x6e, 0x66, 0x6f, 0x12, 0x41, 0x0a, 0x14,
	0x73, 0x63, 0x65, 0x6e, 0x65, 0x5f, 0x69, 0x6e, 0x66, 0x6f, 0x5f, 0x6c, 0x61, 0x73, 0x74, 0x5f,
	0x74, 0x69, 0x6d, 0x65, 0x18, 0x02, 0x20, 0x01, 0x28, 0x0b, 0x32, 0x10, 0x2e, 0x50, 0x6c, 0x61,
	0x79, 0x65, 0x72, 0x53, 0x63, 0x65, 0x6e, 0x65, 0x49, 0x6e, 0x66, 0x6f, 0x52, 0x11, 0x73, 0x63,
	0x65, 0x6e, 0x65, 0x49, 0x6e, 0x66, 0x6f, 0x4c, 0x61, 0x73, 0x74, 0x54, 0x69, 0x6d, 0x65, 0x42,
	0x09, 0x5a, 0x07, 0x70, 0x62, 0x2f, 0x67, 0x61, 0x6d, 0x65, 0x62, 0x06, 0x70, 0x72, 0x6f, 0x74,
	0x6f, 0x33,
}

var (
	file_logic_component_player_scene_comp_proto_rawDescOnce sync.Once
	file_logic_component_player_scene_comp_proto_rawDescData = file_logic_component_player_scene_comp_proto_rawDesc
)

func file_logic_component_player_scene_comp_proto_rawDescGZIP() []byte {
	file_logic_component_player_scene_comp_proto_rawDescOnce.Do(func() {
		file_logic_component_player_scene_comp_proto_rawDescData = protoimpl.X.CompressGZIP(file_logic_component_player_scene_comp_proto_rawDescData)
	})
	return file_logic_component_player_scene_comp_proto_rawDescData
}

var file_logic_component_player_scene_comp_proto_msgTypes = make([]protoimpl.MessageInfo, 2)
var file_logic_component_player_scene_comp_proto_goTypes = []interface{}{
	(*PlayerSceneInfo)(nil),     // 0: PlayerSceneInfo
	(*PlayerSceneInfoComp)(nil), // 1: PlayerSceneInfoComp
}
var file_logic_component_player_scene_comp_proto_depIdxs = []int32{
	0, // 0: PlayerSceneInfoComp.scene_info:type_name -> PlayerSceneInfo
	0, // 1: PlayerSceneInfoComp.scene_info_last_time:type_name -> PlayerSceneInfo
	2, // [2:2] is the sub-list for method output_type
	2, // [2:2] is the sub-list for method input_type
	2, // [2:2] is the sub-list for extension type_name
	2, // [2:2] is the sub-list for extension extendee
	0, // [0:2] is the sub-list for field type_name
}

func init() { file_logic_component_player_scene_comp_proto_init() }
func file_logic_component_player_scene_comp_proto_init() {
	if File_logic_component_player_scene_comp_proto != nil {
		return
	}
	if !protoimpl.UnsafeEnabled {
		file_logic_component_player_scene_comp_proto_msgTypes[0].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*PlayerSceneInfo); i {
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
		file_logic_component_player_scene_comp_proto_msgTypes[1].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*PlayerSceneInfoComp); i {
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
			RawDescriptor: file_logic_component_player_scene_comp_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   2,
			NumExtensions: 0,
			NumServices:   0,
		},
		GoTypes:           file_logic_component_player_scene_comp_proto_goTypes,
		DependencyIndexes: file_logic_component_player_scene_comp_proto_depIdxs,
		MessageInfos:      file_logic_component_player_scene_comp_proto_msgTypes,
	}.Build()
	File_logic_component_player_scene_comp_proto = out.File
	file_logic_component_player_scene_comp_proto_rawDesc = nil
	file_logic_component_player_scene_comp_proto_goTypes = nil
	file_logic_component_player_scene_comp_proto_depIdxs = nil
}
