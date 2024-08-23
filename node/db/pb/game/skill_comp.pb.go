// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.34.2
// 	protoc        v5.26.1
// source: logic/component/skill_comp.proto

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

type SkillPBComp struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	SkillTableId uint64 `protobuf:"varint,1,opt,name=skill_table_id,json=skillTableId,proto3" json:"skill_table_id,omitempty"`
}

func (x *SkillPBComp) Reset() {
	*x = SkillPBComp{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_component_skill_comp_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *SkillPBComp) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*SkillPBComp) ProtoMessage() {}

func (x *SkillPBComp) ProtoReflect() protoreflect.Message {
	mi := &file_logic_component_skill_comp_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use SkillPBComp.ProtoReflect.Descriptor instead.
func (*SkillPBComp) Descriptor() ([]byte, []int) {
	return file_logic_component_skill_comp_proto_rawDescGZIP(), []int{0}
}

func (x *SkillPBComp) GetSkillTableId() uint64 {
	if x != nil {
		return x.SkillTableId
	}
	return 0
}

type SkillContextPBComp struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Caster         uint64            `protobuf:"varint,1,opt,name=caster,proto3" json:"caster,omitempty"`                                                                                                         // 施法者
	Target         uint64            `protobuf:"varint,2,opt,name=target,proto3" json:"target,omitempty"`                                                                                                         // 目标（如果有）
	SkillId        uint32            `protobuf:"varint,3,opt,name=SkillId,proto3" json:"SkillId,omitempty"`                                                                                                       // 技能唯一id
	SkillTableId   uint32            `protobuf:"varint,4,opt,name=skillTableId,proto3" json:"skillTableId,omitempty"`                                                                                             //技能表id
	CastPosition   *Transform        `protobuf:"bytes,5,opt,name=castPosition,proto3" json:"castPosition,omitempty"`                                                                                              //施法位置
	CastTime       uint64            `protobuf:"varint,6,opt,name=castTime,proto3" json:"castTime,omitempty"`                                                                                                     // 施法时间
	State          string            `protobuf:"bytes,7,opt,name=state,proto3" json:"state,omitempty"`                                                                                                            // 当前状态
	AdditionalData map[string]uint32 `protobuf:"bytes,8,rep,name=additionalData,proto3" json:"additionalData,omitempty" protobuf_key:"bytes,1,opt,name=key,proto3" protobuf_val:"varint,2,opt,name=value,proto3"` // 附加数据
}

func (x *SkillContextPBComp) Reset() {
	*x = SkillContextPBComp{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_component_skill_comp_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *SkillContextPBComp) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*SkillContextPBComp) ProtoMessage() {}

func (x *SkillContextPBComp) ProtoReflect() protoreflect.Message {
	mi := &file_logic_component_skill_comp_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use SkillContextPBComp.ProtoReflect.Descriptor instead.
func (*SkillContextPBComp) Descriptor() ([]byte, []int) {
	return file_logic_component_skill_comp_proto_rawDescGZIP(), []int{1}
}

func (x *SkillContextPBComp) GetCaster() uint64 {
	if x != nil {
		return x.Caster
	}
	return 0
}

func (x *SkillContextPBComp) GetTarget() uint64 {
	if x != nil {
		return x.Target
	}
	return 0
}

func (x *SkillContextPBComp) GetSkillId() uint32 {
	if x != nil {
		return x.SkillId
	}
	return 0
}

func (x *SkillContextPBComp) GetSkillTableId() uint32 {
	if x != nil {
		return x.SkillTableId
	}
	return 0
}

func (x *SkillContextPBComp) GetCastPosition() *Transform {
	if x != nil {
		return x.CastPosition
	}
	return nil
}

func (x *SkillContextPBComp) GetCastTime() uint64 {
	if x != nil {
		return x.CastTime
	}
	return 0
}

func (x *SkillContextPBComp) GetState() string {
	if x != nil {
		return x.State
	}
	return ""
}

func (x *SkillContextPBComp) GetAdditionalData() map[string]uint32 {
	if x != nil {
		return x.AdditionalData
	}
	return nil
}

var File_logic_component_skill_comp_proto protoreflect.FileDescriptor

var file_logic_component_skill_comp_proto_rawDesc = []byte{
	0x0a, 0x20, 0x6c, 0x6f, 0x67, 0x69, 0x63, 0x2f, 0x63, 0x6f, 0x6d, 0x70, 0x6f, 0x6e, 0x65, 0x6e,
	0x74, 0x2f, 0x73, 0x6b, 0x69, 0x6c, 0x6c, 0x5f, 0x63, 0x6f, 0x6d, 0x70, 0x2e, 0x70, 0x72, 0x6f,
	0x74, 0x6f, 0x1a, 0x20, 0x6c, 0x6f, 0x67, 0x69, 0x63, 0x2f, 0x63, 0x6f, 0x6d, 0x70, 0x6f, 0x6e,
	0x65, 0x6e, 0x74, 0x2f, 0x61, 0x63, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x6f, 0x6d, 0x70, 0x2e, 0x70,
	0x72, 0x6f, 0x74, 0x6f, 0x22, 0x33, 0x0a, 0x0b, 0x53, 0x6b, 0x69, 0x6c, 0x6c, 0x50, 0x42, 0x43,
	0x6f, 0x6d, 0x70, 0x12, 0x24, 0x0a, 0x0e, 0x73, 0x6b, 0x69, 0x6c, 0x6c, 0x5f, 0x74, 0x61, 0x62,
	0x6c, 0x65, 0x5f, 0x69, 0x64, 0x18, 0x01, 0x20, 0x01, 0x28, 0x04, 0x52, 0x0c, 0x73, 0x6b, 0x69,
	0x6c, 0x6c, 0x54, 0x61, 0x62, 0x6c, 0x65, 0x49, 0x64, 0x22, 0xf8, 0x02, 0x0a, 0x12, 0x53, 0x6b,
	0x69, 0x6c, 0x6c, 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x78, 0x74, 0x50, 0x42, 0x43, 0x6f, 0x6d, 0x70,
	0x12, 0x16, 0x0a, 0x06, 0x63, 0x61, 0x73, 0x74, 0x65, 0x72, 0x18, 0x01, 0x20, 0x01, 0x28, 0x04,
	0x52, 0x06, 0x63, 0x61, 0x73, 0x74, 0x65, 0x72, 0x12, 0x16, 0x0a, 0x06, 0x74, 0x61, 0x72, 0x67,
	0x65, 0x74, 0x18, 0x02, 0x20, 0x01, 0x28, 0x04, 0x52, 0x06, 0x74, 0x61, 0x72, 0x67, 0x65, 0x74,
	0x12, 0x18, 0x0a, 0x07, 0x53, 0x6b, 0x69, 0x6c, 0x6c, 0x49, 0x64, 0x18, 0x03, 0x20, 0x01, 0x28,
	0x0d, 0x52, 0x07, 0x53, 0x6b, 0x69, 0x6c, 0x6c, 0x49, 0x64, 0x12, 0x22, 0x0a, 0x0c, 0x73, 0x6b,
	0x69, 0x6c, 0x6c, 0x54, 0x61, 0x62, 0x6c, 0x65, 0x49, 0x64, 0x18, 0x04, 0x20, 0x01, 0x28, 0x0d,
	0x52, 0x0c, 0x73, 0x6b, 0x69, 0x6c, 0x6c, 0x54, 0x61, 0x62, 0x6c, 0x65, 0x49, 0x64, 0x12, 0x2e,
	0x0a, 0x0c, 0x63, 0x61, 0x73, 0x74, 0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x18, 0x05,
	0x20, 0x01, 0x28, 0x0b, 0x32, 0x0a, 0x2e, 0x54, 0x72, 0x61, 0x6e, 0x73, 0x66, 0x6f, 0x72, 0x6d,
	0x52, 0x0c, 0x63, 0x61, 0x73, 0x74, 0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x12, 0x1a,
	0x0a, 0x08, 0x63, 0x61, 0x73, 0x74, 0x54, 0x69, 0x6d, 0x65, 0x18, 0x06, 0x20, 0x01, 0x28, 0x04,
	0x52, 0x08, 0x63, 0x61, 0x73, 0x74, 0x54, 0x69, 0x6d, 0x65, 0x12, 0x14, 0x0a, 0x05, 0x73, 0x74,
	0x61, 0x74, 0x65, 0x18, 0x07, 0x20, 0x01, 0x28, 0x09, 0x52, 0x05, 0x73, 0x74, 0x61, 0x74, 0x65,
	0x12, 0x4f, 0x0a, 0x0e, 0x61, 0x64, 0x64, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x61, 0x6c, 0x44, 0x61,
	0x74, 0x61, 0x18, 0x08, 0x20, 0x03, 0x28, 0x0b, 0x32, 0x27, 0x2e, 0x53, 0x6b, 0x69, 0x6c, 0x6c,
	0x43, 0x6f, 0x6e, 0x74, 0x65, 0x78, 0x74, 0x50, 0x42, 0x43, 0x6f, 0x6d, 0x70, 0x2e, 0x41, 0x64,
	0x64, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x61, 0x6c, 0x44, 0x61, 0x74, 0x61, 0x45, 0x6e, 0x74, 0x72,
	0x79, 0x52, 0x0e, 0x61, 0x64, 0x64, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x61, 0x6c, 0x44, 0x61, 0x74,
	0x61, 0x1a, 0x41, 0x0a, 0x13, 0x41, 0x64, 0x64, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x61, 0x6c, 0x44,
	0x61, 0x74, 0x61, 0x45, 0x6e, 0x74, 0x72, 0x79, 0x12, 0x10, 0x0a, 0x03, 0x6b, 0x65, 0x79, 0x18,
	0x01, 0x20, 0x01, 0x28, 0x09, 0x52, 0x03, 0x6b, 0x65, 0x79, 0x12, 0x14, 0x0a, 0x05, 0x76, 0x61,
	0x6c, 0x75, 0x65, 0x18, 0x02, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x05, 0x76, 0x61, 0x6c, 0x75, 0x65,
	0x3a, 0x02, 0x38, 0x01, 0x42, 0x09, 0x5a, 0x07, 0x70, 0x62, 0x2f, 0x67, 0x61, 0x6d, 0x65, 0x62,
	0x06, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x33,
}

var (
	file_logic_component_skill_comp_proto_rawDescOnce sync.Once
	file_logic_component_skill_comp_proto_rawDescData = file_logic_component_skill_comp_proto_rawDesc
)

func file_logic_component_skill_comp_proto_rawDescGZIP() []byte {
	file_logic_component_skill_comp_proto_rawDescOnce.Do(func() {
		file_logic_component_skill_comp_proto_rawDescData = protoimpl.X.CompressGZIP(file_logic_component_skill_comp_proto_rawDescData)
	})
	return file_logic_component_skill_comp_proto_rawDescData
}

var file_logic_component_skill_comp_proto_msgTypes = make([]protoimpl.MessageInfo, 3)
var file_logic_component_skill_comp_proto_goTypes = []any{
	(*SkillPBComp)(nil),        // 0: SkillPBComp
	(*SkillContextPBComp)(nil), // 1: SkillContextPBComp
	nil,                        // 2: SkillContextPBComp.AdditionalDataEntry
	(*Transform)(nil),          // 3: Transform
}
var file_logic_component_skill_comp_proto_depIdxs = []int32{
	3, // 0: SkillContextPBComp.castPosition:type_name -> Transform
	2, // 1: SkillContextPBComp.additionalData:type_name -> SkillContextPBComp.AdditionalDataEntry
	2, // [2:2] is the sub-list for method output_type
	2, // [2:2] is the sub-list for method input_type
	2, // [2:2] is the sub-list for extension type_name
	2, // [2:2] is the sub-list for extension extendee
	0, // [0:2] is the sub-list for field type_name
}

func init() { file_logic_component_skill_comp_proto_init() }
func file_logic_component_skill_comp_proto_init() {
	if File_logic_component_skill_comp_proto != nil {
		return
	}
	file_logic_component_actor_comp_proto_init()
	if !protoimpl.UnsafeEnabled {
		file_logic_component_skill_comp_proto_msgTypes[0].Exporter = func(v any, i int) any {
			switch v := v.(*SkillPBComp); i {
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
		file_logic_component_skill_comp_proto_msgTypes[1].Exporter = func(v any, i int) any {
			switch v := v.(*SkillContextPBComp); i {
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
			RawDescriptor: file_logic_component_skill_comp_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   3,
			NumExtensions: 0,
			NumServices:   0,
		},
		GoTypes:           file_logic_component_skill_comp_proto_goTypes,
		DependencyIndexes: file_logic_component_skill_comp_proto_depIdxs,
		MessageInfos:      file_logic_component_skill_comp_proto_msgTypes,
	}.Build()
	File_logic_component_skill_comp_proto = out.File
	file_logic_component_skill_comp_proto_rawDesc = nil
	file_logic_component_skill_comp_proto_goTypes = nil
	file_logic_component_skill_comp_proto_depIdxs = nil
}
