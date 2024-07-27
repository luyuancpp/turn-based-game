// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.34.1
// 	protoc        v5.26.1
// source: common/comp.proto

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

type Vector3 struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	X float64 `protobuf:"fixed64,1,opt,name=x,proto3" json:"x,omitempty"`
	Y float64 `protobuf:"fixed64,2,opt,name=y,proto3" json:"y,omitempty"`
	Z float64 `protobuf:"fixed64,3,opt,name=z,proto3" json:"z,omitempty"`
}

func (x *Vector3) Reset() {
	*x = Vector3{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_comp_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *Vector3) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*Vector3) ProtoMessage() {}

func (x *Vector3) ProtoReflect() protoreflect.Message {
	mi := &file_common_comp_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use Vector3.ProtoReflect.Descriptor instead.
func (*Vector3) Descriptor() ([]byte, []int) {
	return file_common_comp_proto_rawDescGZIP(), []int{0}
}

func (x *Vector3) GetX() float64 {
	if x != nil {
		return x.X
	}
	return 0
}

func (x *Vector3) GetY() float64 {
	if x != nil {
		return x.Y
	}
	return 0
}

func (x *Vector3) GetZ() float64 {
	if x != nil {
		return x.Z
	}
	return 0
}

type PlayerInt32Array struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Int32Valuse []int32 `protobuf:"varint,1,rep,packed,name=int32_valuse,json=int32Valuse,proto3" json:"int32_valuse,omitempty"`
}

func (x *PlayerInt32Array) Reset() {
	*x = PlayerInt32Array{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_comp_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *PlayerInt32Array) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*PlayerInt32Array) ProtoMessage() {}

func (x *PlayerInt32Array) ProtoReflect() protoreflect.Message {
	mi := &file_common_comp_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use PlayerInt32Array.ProtoReflect.Descriptor instead.
func (*PlayerInt32Array) Descriptor() ([]byte, []int) {
	return file_common_comp_proto_rawDescGZIP(), []int{1}
}

func (x *PlayerInt32Array) GetInt32Valuse() []int32 {
	if x != nil {
		return x.Int32Valuse
	}
	return nil
}

type PlayerUInt32Array struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Uint32Valuse []uint32 `protobuf:"varint,2,rep,packed,name=uint32_valuse,json=uint32Valuse,proto3" json:"uint32_valuse,omitempty"`
}

func (x *PlayerUInt32Array) Reset() {
	*x = PlayerUInt32Array{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_comp_proto_msgTypes[2]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *PlayerUInt32Array) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*PlayerUInt32Array) ProtoMessage() {}

func (x *PlayerUInt32Array) ProtoReflect() protoreflect.Message {
	mi := &file_common_comp_proto_msgTypes[2]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use PlayerUInt32Array.ProtoReflect.Descriptor instead.
func (*PlayerUInt32Array) Descriptor() ([]byte, []int) {
	return file_common_comp_proto_rawDescGZIP(), []int{2}
}

func (x *PlayerUInt32Array) GetUint32Valuse() []uint32 {
	if x != nil {
		return x.Uint32Valuse
	}
	return nil
}

type PlayerInt64Array struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields
}

func (x *PlayerInt64Array) Reset() {
	*x = PlayerInt64Array{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_comp_proto_msgTypes[3]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *PlayerInt64Array) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*PlayerInt64Array) ProtoMessage() {}

func (x *PlayerInt64Array) ProtoReflect() protoreflect.Message {
	mi := &file_common_comp_proto_msgTypes[3]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use PlayerInt64Array.ProtoReflect.Descriptor instead.
func (*PlayerInt64Array) Descriptor() ([]byte, []int) {
	return file_common_comp_proto_rawDescGZIP(), []int{3}
}

type PlayerUInt64Array struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields
}

func (x *PlayerUInt64Array) Reset() {
	*x = PlayerUInt64Array{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_comp_proto_msgTypes[4]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *PlayerUInt64Array) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*PlayerUInt64Array) ProtoMessage() {}

func (x *PlayerUInt64Array) ProtoReflect() protoreflect.Message {
	mi := &file_common_comp_proto_msgTypes[4]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use PlayerUInt64Array.ProtoReflect.Descriptor instead.
func (*PlayerUInt64Array) Descriptor() ([]byte, []int) {
	return file_common_comp_proto_rawDescGZIP(), []int{4}
}

var File_common_comp_proto protoreflect.FileDescriptor

var file_common_comp_proto_rawDesc = []byte{
	0x0a, 0x11, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2f, 0x63, 0x6f, 0x6d, 0x70, 0x2e, 0x70, 0x72,
	0x6f, 0x74, 0x6f, 0x22, 0x33, 0x0a, 0x07, 0x56, 0x65, 0x63, 0x74, 0x6f, 0x72, 0x33, 0x12, 0x0c,
	0x0a, 0x01, 0x78, 0x18, 0x01, 0x20, 0x01, 0x28, 0x01, 0x52, 0x01, 0x78, 0x12, 0x0c, 0x0a, 0x01,
	0x79, 0x18, 0x02, 0x20, 0x01, 0x28, 0x01, 0x52, 0x01, 0x79, 0x12, 0x0c, 0x0a, 0x01, 0x7a, 0x18,
	0x03, 0x20, 0x01, 0x28, 0x01, 0x52, 0x01, 0x7a, 0x22, 0x35, 0x0a, 0x10, 0x50, 0x6c, 0x61, 0x79,
	0x65, 0x72, 0x49, 0x6e, 0x74, 0x33, 0x32, 0x41, 0x72, 0x72, 0x61, 0x79, 0x12, 0x21, 0x0a, 0x0c,
	0x69, 0x6e, 0x74, 0x33, 0x32, 0x5f, 0x76, 0x61, 0x6c, 0x75, 0x73, 0x65, 0x18, 0x01, 0x20, 0x03,
	0x28, 0x05, 0x52, 0x0b, 0x69, 0x6e, 0x74, 0x33, 0x32, 0x56, 0x61, 0x6c, 0x75, 0x73, 0x65, 0x22,
	0x38, 0x0a, 0x11, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x55, 0x49, 0x6e, 0x74, 0x33, 0x32, 0x41,
	0x72, 0x72, 0x61, 0x79, 0x12, 0x23, 0x0a, 0x0d, 0x75, 0x69, 0x6e, 0x74, 0x33, 0x32, 0x5f, 0x76,
	0x61, 0x6c, 0x75, 0x73, 0x65, 0x18, 0x02, 0x20, 0x03, 0x28, 0x0d, 0x52, 0x0c, 0x75, 0x69, 0x6e,
	0x74, 0x33, 0x32, 0x56, 0x61, 0x6c, 0x75, 0x73, 0x65, 0x22, 0x12, 0x0a, 0x10, 0x50, 0x6c, 0x61,
	0x79, 0x65, 0x72, 0x49, 0x6e, 0x74, 0x36, 0x34, 0x41, 0x72, 0x72, 0x61, 0x79, 0x22, 0x13, 0x0a,
	0x11, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x55, 0x49, 0x6e, 0x74, 0x36, 0x34, 0x41, 0x72, 0x72,
	0x61, 0x79, 0x42, 0x09, 0x5a, 0x07, 0x70, 0x62, 0x2f, 0x67, 0x61, 0x6d, 0x65, 0x62, 0x06, 0x70,
	0x72, 0x6f, 0x74, 0x6f, 0x33,
}

var (
	file_common_comp_proto_rawDescOnce sync.Once
	file_common_comp_proto_rawDescData = file_common_comp_proto_rawDesc
)

func file_common_comp_proto_rawDescGZIP() []byte {
	file_common_comp_proto_rawDescOnce.Do(func() {
		file_common_comp_proto_rawDescData = protoimpl.X.CompressGZIP(file_common_comp_proto_rawDescData)
	})
	return file_common_comp_proto_rawDescData
}

var file_common_comp_proto_msgTypes = make([]protoimpl.MessageInfo, 5)
var file_common_comp_proto_goTypes = []interface{}{
	(*Vector3)(nil),           // 0: Vector3
	(*PlayerInt32Array)(nil),  // 1: PlayerInt32Array
	(*PlayerUInt32Array)(nil), // 2: PlayerUInt32Array
	(*PlayerInt64Array)(nil),  // 3: PlayerInt64Array
	(*PlayerUInt64Array)(nil), // 4: PlayerUInt64Array
}
var file_common_comp_proto_depIdxs = []int32{
	0, // [0:0] is the sub-list for method output_type
	0, // [0:0] is the sub-list for method input_type
	0, // [0:0] is the sub-list for extension type_name
	0, // [0:0] is the sub-list for extension extendee
	0, // [0:0] is the sub-list for field type_name
}

func init() { file_common_comp_proto_init() }
func file_common_comp_proto_init() {
	if File_common_comp_proto != nil {
		return
	}
	if !protoimpl.UnsafeEnabled {
		file_common_comp_proto_msgTypes[0].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*Vector3); i {
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
		file_common_comp_proto_msgTypes[1].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*PlayerInt32Array); i {
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
		file_common_comp_proto_msgTypes[2].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*PlayerUInt32Array); i {
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
		file_common_comp_proto_msgTypes[3].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*PlayerInt64Array); i {
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
		file_common_comp_proto_msgTypes[4].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*PlayerUInt64Array); i {
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
			RawDescriptor: file_common_comp_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   5,
			NumExtensions: 0,
			NumServices:   0,
		},
		GoTypes:           file_common_comp_proto_goTypes,
		DependencyIndexes: file_common_comp_proto_depIdxs,
		MessageInfos:      file_common_comp_proto_msgTypes,
	}.Build()
	File_common_comp_proto = out.File
	file_common_comp_proto_rawDesc = nil
	file_common_comp_proto_goTypes = nil
	file_common_comp_proto_depIdxs = nil
}
