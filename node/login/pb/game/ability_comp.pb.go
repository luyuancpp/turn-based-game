// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.34.2
// 	protoc        v5.26.1
// source: logic/component/ability_comp.proto

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

type Ability struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	AbilityId uint64 `protobuf:"varint,1,opt,name=ability_id,json=abilityId,proto3" json:"ability_id,omitempty"`
	TableId   uint32 `protobuf:"varint,2,opt,name=table_id,json=tableId,proto3" json:"table_id,omitempty"`
}

func (x *Ability) Reset() {
	*x = Ability{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_component_ability_comp_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *Ability) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*Ability) ProtoMessage() {}

func (x *Ability) ProtoReflect() protoreflect.Message {
	mi := &file_logic_component_ability_comp_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use Ability.ProtoReflect.Descriptor instead.
func (*Ability) Descriptor() ([]byte, []int) {
	return file_logic_component_ability_comp_proto_rawDescGZIP(), []int{0}
}

func (x *Ability) GetAbilityId() uint64 {
	if x != nil {
		return x.AbilityId
	}
	return 0
}

func (x *Ability) GetTableId() uint32 {
	if x != nil {
		return x.TableId
	}
	return 0
}

// 被动类型的技能
type PassiveAblity struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields
}

func (x *PassiveAblity) Reset() {
	*x = PassiveAblity{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_component_ability_comp_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *PassiveAblity) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*PassiveAblity) ProtoMessage() {}

func (x *PassiveAblity) ProtoReflect() protoreflect.Message {
	mi := &file_logic_component_ability_comp_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use PassiveAblity.ProtoReflect.Descriptor instead.
func (*PassiveAblity) Descriptor() ([]byte, []int) {
	return file_logic_component_ability_comp_proto_rawDescGZIP(), []int{1}
}

// 主动施法技能（最常见的通用主动施法类技能，如普通攻击等一次性触发效果类技能
type GeneralAbility struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields
}

func (x *GeneralAbility) Reset() {
	*x = GeneralAbility{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_component_ability_comp_proto_msgTypes[2]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *GeneralAbility) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*GeneralAbility) ProtoMessage() {}

func (x *GeneralAbility) ProtoReflect() protoreflect.Message {
	mi := &file_logic_component_ability_comp_proto_msgTypes[2]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use GeneralAbility.ProtoReflect.Descriptor instead.
func (*GeneralAbility) Descriptor() ([]byte, []int) {
	return file_logic_component_ability_comp_proto_rawDescGZIP(), []int{2}
}

// 引导类持续施法技能(ChannelAbility)，如大法师暴风雪）
type ChannelAbility struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields
}

func (x *ChannelAbility) Reset() {
	*x = ChannelAbility{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_component_ability_comp_proto_msgTypes[3]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *ChannelAbility) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*ChannelAbility) ProtoMessage() {}

func (x *ChannelAbility) ProtoReflect() protoreflect.Message {
	mi := &file_logic_component_ability_comp_proto_msgTypes[3]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use ChannelAbility.ProtoReflect.Descriptor instead.
func (*ChannelAbility) Descriptor() ([]byte, []int) {
	return file_logic_component_ability_comp_proto_rawDescGZIP(), []int{3}
}

// 开关类技能（(ToggleAbility)点击技能开启/关闭效果，类似于恶魔猎手献祭）
type ToggleAbility struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields
}

func (x *ToggleAbility) Reset() {
	*x = ToggleAbility{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_component_ability_comp_proto_msgTypes[4]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *ToggleAbility) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*ToggleAbility) ProtoMessage() {}

func (x *ToggleAbility) ProtoReflect() protoreflect.Message {
	mi := &file_logic_component_ability_comp_proto_msgTypes[4]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use ToggleAbility.ProtoReflect.Descriptor instead.
func (*ToggleAbility) Descriptor() ([]byte, []int) {
	return file_logic_component_ability_comp_proto_rawDescGZIP(), []int{4}
}

// 激活类技能（(ActivateAbility)点下右键激活/停止，一般是给普通攻击附加特殊效果）
type ActivateAbility struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields
}

func (x *ActivateAbility) Reset() {
	*x = ActivateAbility{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_component_ability_comp_proto_msgTypes[5]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *ActivateAbility) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*ActivateAbility) ProtoMessage() {}

func (x *ActivateAbility) ProtoReflect() protoreflect.Message {
	mi := &file_logic_component_ability_comp_proto_msgTypes[5]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use ActivateAbility.ProtoReflect.Descriptor instead.
func (*ActivateAbility) Descriptor() ([]byte, []int) {
	return file_logic_component_ability_comp_proto_rawDescGZIP(), []int{5}
}

var File_logic_component_ability_comp_proto protoreflect.FileDescriptor

var file_logic_component_ability_comp_proto_rawDesc = []byte{
	0x0a, 0x22, 0x6c, 0x6f, 0x67, 0x69, 0x63, 0x2f, 0x63, 0x6f, 0x6d, 0x70, 0x6f, 0x6e, 0x65, 0x6e,
	0x74, 0x2f, 0x61, 0x62, 0x69, 0x6c, 0x69, 0x74, 0x79, 0x5f, 0x63, 0x6f, 0x6d, 0x70, 0x2e, 0x70,
	0x72, 0x6f, 0x74, 0x6f, 0x22, 0x43, 0x0a, 0x07, 0x41, 0x62, 0x69, 0x6c, 0x69, 0x74, 0x79, 0x12,
	0x1d, 0x0a, 0x0a, 0x61, 0x62, 0x69, 0x6c, 0x69, 0x74, 0x79, 0x5f, 0x69, 0x64, 0x18, 0x01, 0x20,
	0x01, 0x28, 0x04, 0x52, 0x09, 0x61, 0x62, 0x69, 0x6c, 0x69, 0x74, 0x79, 0x49, 0x64, 0x12, 0x19,
	0x0a, 0x08, 0x74, 0x61, 0x62, 0x6c, 0x65, 0x5f, 0x69, 0x64, 0x18, 0x02, 0x20, 0x01, 0x28, 0x0d,
	0x52, 0x07, 0x74, 0x61, 0x62, 0x6c, 0x65, 0x49, 0x64, 0x22, 0x0f, 0x0a, 0x0d, 0x50, 0x61, 0x73,
	0x73, 0x69, 0x76, 0x65, 0x41, 0x62, 0x6c, 0x69, 0x74, 0x79, 0x22, 0x10, 0x0a, 0x0e, 0x47, 0x65,
	0x6e, 0x65, 0x72, 0x61, 0x6c, 0x41, 0x62, 0x69, 0x6c, 0x69, 0x74, 0x79, 0x22, 0x10, 0x0a, 0x0e,
	0x43, 0x68, 0x61, 0x6e, 0x6e, 0x65, 0x6c, 0x41, 0x62, 0x69, 0x6c, 0x69, 0x74, 0x79, 0x22, 0x0f,
	0x0a, 0x0d, 0x54, 0x6f, 0x67, 0x67, 0x6c, 0x65, 0x41, 0x62, 0x69, 0x6c, 0x69, 0x74, 0x79, 0x22,
	0x11, 0x0a, 0x0f, 0x41, 0x63, 0x74, 0x69, 0x76, 0x61, 0x74, 0x65, 0x41, 0x62, 0x69, 0x6c, 0x69,
	0x74, 0x79, 0x42, 0x09, 0x5a, 0x07, 0x70, 0x62, 0x2f, 0x67, 0x61, 0x6d, 0x65, 0x62, 0x06, 0x70,
	0x72, 0x6f, 0x74, 0x6f, 0x33,
}

var (
	file_logic_component_ability_comp_proto_rawDescOnce sync.Once
	file_logic_component_ability_comp_proto_rawDescData = file_logic_component_ability_comp_proto_rawDesc
)

func file_logic_component_ability_comp_proto_rawDescGZIP() []byte {
	file_logic_component_ability_comp_proto_rawDescOnce.Do(func() {
		file_logic_component_ability_comp_proto_rawDescData = protoimpl.X.CompressGZIP(file_logic_component_ability_comp_proto_rawDescData)
	})
	return file_logic_component_ability_comp_proto_rawDescData
}

var file_logic_component_ability_comp_proto_msgTypes = make([]protoimpl.MessageInfo, 6)
var file_logic_component_ability_comp_proto_goTypes = []any{
	(*Ability)(nil),         // 0: Ability
	(*PassiveAblity)(nil),   // 1: PassiveAblity
	(*GeneralAbility)(nil),  // 2: GeneralAbility
	(*ChannelAbility)(nil),  // 3: ChannelAbility
	(*ToggleAbility)(nil),   // 4: ToggleAbility
	(*ActivateAbility)(nil), // 5: ActivateAbility
}
var file_logic_component_ability_comp_proto_depIdxs = []int32{
	0, // [0:0] is the sub-list for method output_type
	0, // [0:0] is the sub-list for method input_type
	0, // [0:0] is the sub-list for extension type_name
	0, // [0:0] is the sub-list for extension extendee
	0, // [0:0] is the sub-list for field type_name
}

func init() { file_logic_component_ability_comp_proto_init() }
func file_logic_component_ability_comp_proto_init() {
	if File_logic_component_ability_comp_proto != nil {
		return
	}
	if !protoimpl.UnsafeEnabled {
		file_logic_component_ability_comp_proto_msgTypes[0].Exporter = func(v any, i int) any {
			switch v := v.(*Ability); i {
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
		file_logic_component_ability_comp_proto_msgTypes[1].Exporter = func(v any, i int) any {
			switch v := v.(*PassiveAblity); i {
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
		file_logic_component_ability_comp_proto_msgTypes[2].Exporter = func(v any, i int) any {
			switch v := v.(*GeneralAbility); i {
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
		file_logic_component_ability_comp_proto_msgTypes[3].Exporter = func(v any, i int) any {
			switch v := v.(*ChannelAbility); i {
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
		file_logic_component_ability_comp_proto_msgTypes[4].Exporter = func(v any, i int) any {
			switch v := v.(*ToggleAbility); i {
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
		file_logic_component_ability_comp_proto_msgTypes[5].Exporter = func(v any, i int) any {
			switch v := v.(*ActivateAbility); i {
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
			RawDescriptor: file_logic_component_ability_comp_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   6,
			NumExtensions: 0,
			NumServices:   0,
		},
		GoTypes:           file_logic_component_ability_comp_proto_goTypes,
		DependencyIndexes: file_logic_component_ability_comp_proto_depIdxs,
		MessageInfos:      file_logic_component_ability_comp_proto_msgTypes,
	}.Build()
	File_logic_component_ability_comp_proto = out.File
	file_logic_component_ability_comp_proto_rawDesc = nil
	file_logic_component_ability_comp_proto_goTypes = nil
	file_logic_component_ability_comp_proto_depIdxs = nil
}
