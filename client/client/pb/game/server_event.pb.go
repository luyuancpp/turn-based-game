// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.34.1
// 	protoc        v5.26.1
// source: logic/event/server_event.proto

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

type OnConnect2Centre struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Entity uint64 `protobuf:"varint,1,opt,name=entity,proto3" json:"entity,omitempty"`
}

func (x *OnConnect2Centre) Reset() {
	*x = OnConnect2Centre{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_event_server_event_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *OnConnect2Centre) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*OnConnect2Centre) ProtoMessage() {}

func (x *OnConnect2Centre) ProtoReflect() protoreflect.Message {
	mi := &file_logic_event_server_event_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use OnConnect2Centre.ProtoReflect.Descriptor instead.
func (*OnConnect2Centre) Descriptor() ([]byte, []int) {
	return file_logic_event_server_event_proto_rawDescGZIP(), []int{0}
}

func (x *OnConnect2Centre) GetEntity() uint64 {
	if x != nil {
		return x.Entity
	}
	return 0
}

type OnConnect2Game struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Entity uint64 `protobuf:"varint,1,opt,name=entity,proto3" json:"entity,omitempty"`
}

func (x *OnConnect2Game) Reset() {
	*x = OnConnect2Game{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_event_server_event_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *OnConnect2Game) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*OnConnect2Game) ProtoMessage() {}

func (x *OnConnect2Game) ProtoReflect() protoreflect.Message {
	mi := &file_logic_event_server_event_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use OnConnect2Game.ProtoReflect.Descriptor instead.
func (*OnConnect2Game) Descriptor() ([]byte, []int) {
	return file_logic_event_server_event_proto_rawDescGZIP(), []int{1}
}

func (x *OnConnect2Game) GetEntity() uint64 {
	if x != nil {
		return x.Entity
	}
	return 0
}

type OnConnect2Gate struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Entity uint64 `protobuf:"varint,1,opt,name=entity,proto3" json:"entity,omitempty"`
}

func (x *OnConnect2Gate) Reset() {
	*x = OnConnect2Gate{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_event_server_event_proto_msgTypes[2]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *OnConnect2Gate) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*OnConnect2Gate) ProtoMessage() {}

func (x *OnConnect2Gate) ProtoReflect() protoreflect.Message {
	mi := &file_logic_event_server_event_proto_msgTypes[2]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use OnConnect2Gate.ProtoReflect.Descriptor instead.
func (*OnConnect2Gate) Descriptor() ([]byte, []int) {
	return file_logic_event_server_event_proto_rawDescGZIP(), []int{2}
}

func (x *OnConnect2Gate) GetEntity() uint64 {
	if x != nil {
		return x.Entity
	}
	return 0
}

type OnConnect2Login struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Entity uint64 `protobuf:"varint,1,opt,name=entity,proto3" json:"entity,omitempty"`
}

func (x *OnConnect2Login) Reset() {
	*x = OnConnect2Login{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_event_server_event_proto_msgTypes[3]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *OnConnect2Login) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*OnConnect2Login) ProtoMessage() {}

func (x *OnConnect2Login) ProtoReflect() protoreflect.Message {
	mi := &file_logic_event_server_event_proto_msgTypes[3]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use OnConnect2Login.ProtoReflect.Descriptor instead.
func (*OnConnect2Login) Descriptor() ([]byte, []int) {
	return file_logic_event_server_event_proto_rawDescGZIP(), []int{3}
}

func (x *OnConnect2Login) GetEntity() uint64 {
	if x != nil {
		return x.Entity
	}
	return 0
}

type OnServerStart struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields
}

func (x *OnServerStart) Reset() {
	*x = OnServerStart{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_event_server_event_proto_msgTypes[4]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *OnServerStart) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*OnServerStart) ProtoMessage() {}

func (x *OnServerStart) ProtoReflect() protoreflect.Message {
	mi := &file_logic_event_server_event_proto_msgTypes[4]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use OnServerStart.ProtoReflect.Descriptor instead.
func (*OnServerStart) Descriptor() ([]byte, []int) {
	return file_logic_event_server_event_proto_rawDescGZIP(), []int{4}
}

var File_logic_event_server_event_proto protoreflect.FileDescriptor

var file_logic_event_server_event_proto_rawDesc = []byte{
	0x0a, 0x1e, 0x6c, 0x6f, 0x67, 0x69, 0x63, 0x2f, 0x65, 0x76, 0x65, 0x6e, 0x74, 0x2f, 0x73, 0x65,
	0x72, 0x76, 0x65, 0x72, 0x5f, 0x65, 0x76, 0x65, 0x6e, 0x74, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f,
	0x22, 0x2a, 0x0a, 0x10, 0x4f, 0x6e, 0x43, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x32, 0x43, 0x65,
	0x6e, 0x74, 0x72, 0x65, 0x12, 0x16, 0x0a, 0x06, 0x65, 0x6e, 0x74, 0x69, 0x74, 0x79, 0x18, 0x01,
	0x20, 0x01, 0x28, 0x04, 0x52, 0x06, 0x65, 0x6e, 0x74, 0x69, 0x74, 0x79, 0x22, 0x28, 0x0a, 0x0e,
	0x4f, 0x6e, 0x43, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x32, 0x47, 0x61, 0x6d, 0x65, 0x12, 0x16,
	0x0a, 0x06, 0x65, 0x6e, 0x74, 0x69, 0x74, 0x79, 0x18, 0x01, 0x20, 0x01, 0x28, 0x04, 0x52, 0x06,
	0x65, 0x6e, 0x74, 0x69, 0x74, 0x79, 0x22, 0x28, 0x0a, 0x0e, 0x4f, 0x6e, 0x43, 0x6f, 0x6e, 0x6e,
	0x65, 0x63, 0x74, 0x32, 0x47, 0x61, 0x74, 0x65, 0x12, 0x16, 0x0a, 0x06, 0x65, 0x6e, 0x74, 0x69,
	0x74, 0x79, 0x18, 0x01, 0x20, 0x01, 0x28, 0x04, 0x52, 0x06, 0x65, 0x6e, 0x74, 0x69, 0x74, 0x79,
	0x22, 0x29, 0x0a, 0x0f, 0x4f, 0x6e, 0x43, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x32, 0x4c, 0x6f,
	0x67, 0x69, 0x6e, 0x12, 0x16, 0x0a, 0x06, 0x65, 0x6e, 0x74, 0x69, 0x74, 0x79, 0x18, 0x01, 0x20,
	0x01, 0x28, 0x04, 0x52, 0x06, 0x65, 0x6e, 0x74, 0x69, 0x74, 0x79, 0x22, 0x0f, 0x0a, 0x0d, 0x4f,
	0x6e, 0x53, 0x65, 0x72, 0x76, 0x65, 0x72, 0x53, 0x74, 0x61, 0x72, 0x74, 0x42, 0x09, 0x5a, 0x07,
	0x70, 0x62, 0x2f, 0x67, 0x61, 0x6d, 0x65, 0x62, 0x06, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x33,
}

var (
	file_logic_event_server_event_proto_rawDescOnce sync.Once
	file_logic_event_server_event_proto_rawDescData = file_logic_event_server_event_proto_rawDesc
)

func file_logic_event_server_event_proto_rawDescGZIP() []byte {
	file_logic_event_server_event_proto_rawDescOnce.Do(func() {
		file_logic_event_server_event_proto_rawDescData = protoimpl.X.CompressGZIP(file_logic_event_server_event_proto_rawDescData)
	})
	return file_logic_event_server_event_proto_rawDescData
}

var file_logic_event_server_event_proto_msgTypes = make([]protoimpl.MessageInfo, 5)
var file_logic_event_server_event_proto_goTypes = []interface{}{
	(*OnConnect2Centre)(nil), // 0: OnConnect2Centre
	(*OnConnect2Game)(nil),   // 1: OnConnect2Game
	(*OnConnect2Gate)(nil),   // 2: OnConnect2Gate
	(*OnConnect2Login)(nil),  // 3: OnConnect2Login
	(*OnServerStart)(nil),    // 4: OnServerStart
}
var file_logic_event_server_event_proto_depIdxs = []int32{
	0, // [0:0] is the sub-list for method output_type
	0, // [0:0] is the sub-list for method input_type
	0, // [0:0] is the sub-list for extension type_name
	0, // [0:0] is the sub-list for extension extendee
	0, // [0:0] is the sub-list for field type_name
}

func init() { file_logic_event_server_event_proto_init() }
func file_logic_event_server_event_proto_init() {
	if File_logic_event_server_event_proto != nil {
		return
	}
	if !protoimpl.UnsafeEnabled {
		file_logic_event_server_event_proto_msgTypes[0].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*OnConnect2Centre); i {
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
		file_logic_event_server_event_proto_msgTypes[1].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*OnConnect2Game); i {
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
		file_logic_event_server_event_proto_msgTypes[2].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*OnConnect2Gate); i {
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
		file_logic_event_server_event_proto_msgTypes[3].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*OnConnect2Login); i {
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
		file_logic_event_server_event_proto_msgTypes[4].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*OnServerStart); i {
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
			RawDescriptor: file_logic_event_server_event_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   5,
			NumExtensions: 0,
			NumServices:   0,
		},
		GoTypes:           file_logic_event_server_event_proto_goTypes,
		DependencyIndexes: file_logic_event_server_event_proto_depIdxs,
		MessageInfos:      file_logic_event_server_event_proto_msgTypes,
	}.Build()
	File_logic_event_server_event_proto = out.File
	file_logic_event_server_event_proto_rawDesc = nil
	file_logic_event_server_event_proto_goTypes = nil
	file_logic_event_server_event_proto_depIdxs = nil
}
