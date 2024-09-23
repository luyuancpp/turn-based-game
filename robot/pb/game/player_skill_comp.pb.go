// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.34.2
// 	protoc        v5.26.1
// source: logic/component/player_skill_comp.proto

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

type PlayerSkillPBComp struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Id           uint64 `protobuf:"varint,1,opt,name=id,proto3" json:"id,omitempty"`
	SkillTableId uint32 `protobuf:"varint,2,opt,name=skill_table_id,json=skillTableId,proto3" json:"skill_table_id,omitempty"`
}

func (x *PlayerSkillPBComp) Reset() {
	*x = PlayerSkillPBComp{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_component_player_skill_comp_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *PlayerSkillPBComp) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*PlayerSkillPBComp) ProtoMessage() {}

func (x *PlayerSkillPBComp) ProtoReflect() protoreflect.Message {
	mi := &file_logic_component_player_skill_comp_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use PlayerSkillPBComp.ProtoReflect.Descriptor instead.
func (*PlayerSkillPBComp) Descriptor() ([]byte, []int) {
	return file_logic_component_player_skill_comp_proto_rawDescGZIP(), []int{0}
}

func (x *PlayerSkillPBComp) GetId() uint64 {
	if x != nil {
		return x.Id
	}
	return 0
}

func (x *PlayerSkillPBComp) GetSkillTableId() uint32 {
	if x != nil {
		return x.SkillTableId
	}
	return 0
}

type PlayerSkillListPBComp struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	SkillList []*PlayerSkillPBComp `protobuf:"bytes,1,rep,name=skill_list,json=skillList,proto3" json:"skill_list,omitempty"`
}

func (x *PlayerSkillListPBComp) Reset() {
	*x = PlayerSkillListPBComp{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_component_player_skill_comp_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *PlayerSkillListPBComp) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*PlayerSkillListPBComp) ProtoMessage() {}

func (x *PlayerSkillListPBComp) ProtoReflect() protoreflect.Message {
	mi := &file_logic_component_player_skill_comp_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use PlayerSkillListPBComp.ProtoReflect.Descriptor instead.
func (*PlayerSkillListPBComp) Descriptor() ([]byte, []int) {
	return file_logic_component_player_skill_comp_proto_rawDescGZIP(), []int{1}
}

func (x *PlayerSkillListPBComp) GetSkillList() []*PlayerSkillPBComp {
	if x != nil {
		return x.SkillList
	}
	return nil
}

var File_logic_component_player_skill_comp_proto protoreflect.FileDescriptor

var file_logic_component_player_skill_comp_proto_rawDesc = []byte{
	0x0a, 0x27, 0x6c, 0x6f, 0x67, 0x69, 0x63, 0x2f, 0x63, 0x6f, 0x6d, 0x70, 0x6f, 0x6e, 0x65, 0x6e,
	0x74, 0x2f, 0x70, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x5f, 0x73, 0x6b, 0x69, 0x6c, 0x6c, 0x5f, 0x63,
	0x6f, 0x6d, 0x70, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x22, 0x49, 0x0a, 0x11, 0x50, 0x6c, 0x61,
	0x79, 0x65, 0x72, 0x53, 0x6b, 0x69, 0x6c, 0x6c, 0x50, 0x42, 0x43, 0x6f, 0x6d, 0x70, 0x12, 0x0e,
	0x0a, 0x02, 0x69, 0x64, 0x18, 0x01, 0x20, 0x01, 0x28, 0x04, 0x52, 0x02, 0x69, 0x64, 0x12, 0x24,
	0x0a, 0x0e, 0x73, 0x6b, 0x69, 0x6c, 0x6c, 0x5f, 0x74, 0x61, 0x62, 0x6c, 0x65, 0x5f, 0x69, 0x64,
	0x18, 0x02, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x0c, 0x73, 0x6b, 0x69, 0x6c, 0x6c, 0x54, 0x61, 0x62,
	0x6c, 0x65, 0x49, 0x64, 0x22, 0x4a, 0x0a, 0x15, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x53, 0x6b,
	0x69, 0x6c, 0x6c, 0x4c, 0x69, 0x73, 0x74, 0x50, 0x42, 0x43, 0x6f, 0x6d, 0x70, 0x12, 0x31, 0x0a,
	0x0a, 0x73, 0x6b, 0x69, 0x6c, 0x6c, 0x5f, 0x6c, 0x69, 0x73, 0x74, 0x18, 0x01, 0x20, 0x03, 0x28,
	0x0b, 0x32, 0x12, 0x2e, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x53, 0x6b, 0x69, 0x6c, 0x6c, 0x50,
	0x42, 0x43, 0x6f, 0x6d, 0x70, 0x52, 0x09, 0x73, 0x6b, 0x69, 0x6c, 0x6c, 0x4c, 0x69, 0x73, 0x74,
	0x42, 0x09, 0x5a, 0x07, 0x70, 0x62, 0x2f, 0x67, 0x61, 0x6d, 0x65, 0x62, 0x06, 0x70, 0x72, 0x6f,
	0x74, 0x6f, 0x33,
}

var (
	file_logic_component_player_skill_comp_proto_rawDescOnce sync.Once
	file_logic_component_player_skill_comp_proto_rawDescData = file_logic_component_player_skill_comp_proto_rawDesc
)

func file_logic_component_player_skill_comp_proto_rawDescGZIP() []byte {
	file_logic_component_player_skill_comp_proto_rawDescOnce.Do(func() {
		file_logic_component_player_skill_comp_proto_rawDescData = protoimpl.X.CompressGZIP(file_logic_component_player_skill_comp_proto_rawDescData)
	})
	return file_logic_component_player_skill_comp_proto_rawDescData
}

var file_logic_component_player_skill_comp_proto_msgTypes = make([]protoimpl.MessageInfo, 2)
var file_logic_component_player_skill_comp_proto_goTypes = []any{
	(*PlayerSkillPBComp)(nil),     // 0: PlayerSkillPBComp
	(*PlayerSkillListPBComp)(nil), // 1: PlayerSkillListPBComp
}
var file_logic_component_player_skill_comp_proto_depIdxs = []int32{
	0, // 0: PlayerSkillListPBComp.skill_list:type_name -> PlayerSkillPBComp
	1, // [1:1] is the sub-list for method output_type
	1, // [1:1] is the sub-list for method input_type
	1, // [1:1] is the sub-list for extension type_name
	1, // [1:1] is the sub-list for extension extendee
	0, // [0:1] is the sub-list for field type_name
}

func init() { file_logic_component_player_skill_comp_proto_init() }
func file_logic_component_player_skill_comp_proto_init() {
	if File_logic_component_player_skill_comp_proto != nil {
		return
	}
	if !protoimpl.UnsafeEnabled {
		file_logic_component_player_skill_comp_proto_msgTypes[0].Exporter = func(v any, i int) any {
			switch v := v.(*PlayerSkillPBComp); i {
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
		file_logic_component_player_skill_comp_proto_msgTypes[1].Exporter = func(v any, i int) any {
			switch v := v.(*PlayerSkillListPBComp); i {
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
			RawDescriptor: file_logic_component_player_skill_comp_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   2,
			NumExtensions: 0,
			NumServices:   0,
		},
		GoTypes:           file_logic_component_player_skill_comp_proto_goTypes,
		DependencyIndexes: file_logic_component_player_skill_comp_proto_depIdxs,
		MessageInfos:      file_logic_component_player_skill_comp_proto_msgTypes,
	}.Build()
	File_logic_component_player_skill_comp_proto = out.File
	file_logic_component_player_skill_comp_proto_rawDesc = nil
	file_logic_component_player_skill_comp_proto_goTypes = nil
	file_logic_component_player_skill_comp_proto_depIdxs = nil
}
