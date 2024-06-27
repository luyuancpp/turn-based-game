// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.34.1
// 	protoc        v4.25.1
// source: event_proto/mission_event.proto

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

type AcceptMissionEvent struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Entity    uint64 `protobuf:"varint,1,opt,name=entity,proto3" json:"entity,omitempty"`
	MissionId uint32 `protobuf:"varint,2,opt,name=mission_id,json=missionId,proto3" json:"mission_id,omitempty"`
}

func (x *AcceptMissionEvent) Reset() {
	*x = AcceptMissionEvent{}
	if protoimpl.UnsafeEnabled {
		mi := &file_event_proto_mission_event_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *AcceptMissionEvent) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*AcceptMissionEvent) ProtoMessage() {}

func (x *AcceptMissionEvent) ProtoReflect() protoreflect.Message {
	mi := &file_event_proto_mission_event_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use AcceptMissionEvent.ProtoReflect.Descriptor instead.
func (*AcceptMissionEvent) Descriptor() ([]byte, []int) {
	return file_event_proto_mission_event_proto_rawDescGZIP(), []int{0}
}

func (x *AcceptMissionEvent) GetEntity() uint64 {
	if x != nil {
		return x.Entity
	}
	return 0
}

func (x *AcceptMissionEvent) GetMissionId() uint32 {
	if x != nil {
		return x.MissionId
	}
	return 0
}

type MissionConditionEvent struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Entity      uint64   `protobuf:"varint,1,opt,name=entity,proto3" json:"entity,omitempty"`
	Type        uint32   `protobuf:"varint,2,opt,name=type,proto3" json:"type,omitempty"`
	CondtionIds []uint32 `protobuf:"varint,3,rep,packed,name=condtion_ids,json=condtionIds,proto3" json:"condtion_ids,omitempty"`
	Amount      uint32   `protobuf:"varint,4,opt,name=amount,proto3" json:"amount,omitempty"`
}

func (x *MissionConditionEvent) Reset() {
	*x = MissionConditionEvent{}
	if protoimpl.UnsafeEnabled {
		mi := &file_event_proto_mission_event_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *MissionConditionEvent) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*MissionConditionEvent) ProtoMessage() {}

func (x *MissionConditionEvent) ProtoReflect() protoreflect.Message {
	mi := &file_event_proto_mission_event_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use MissionConditionEvent.ProtoReflect.Descriptor instead.
func (*MissionConditionEvent) Descriptor() ([]byte, []int) {
	return file_event_proto_mission_event_proto_rawDescGZIP(), []int{1}
}

func (x *MissionConditionEvent) GetEntity() uint64 {
	if x != nil {
		return x.Entity
	}
	return 0
}

func (x *MissionConditionEvent) GetType() uint32 {
	if x != nil {
		return x.Type
	}
	return 0
}

func (x *MissionConditionEvent) GetCondtionIds() []uint32 {
	if x != nil {
		return x.CondtionIds
	}
	return nil
}

func (x *MissionConditionEvent) GetAmount() uint32 {
	if x != nil {
		return x.Amount
	}
	return 0
}

type OnAcceptedMissionEvent struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Entity    uint64 `protobuf:"varint,1,opt,name=entity,proto3" json:"entity,omitempty"`
	MissionId uint32 `protobuf:"varint,2,opt,name=mission_id,json=missionId,proto3" json:"mission_id,omitempty"`
}

func (x *OnAcceptedMissionEvent) Reset() {
	*x = OnAcceptedMissionEvent{}
	if protoimpl.UnsafeEnabled {
		mi := &file_event_proto_mission_event_proto_msgTypes[2]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *OnAcceptedMissionEvent) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*OnAcceptedMissionEvent) ProtoMessage() {}

func (x *OnAcceptedMissionEvent) ProtoReflect() protoreflect.Message {
	mi := &file_event_proto_mission_event_proto_msgTypes[2]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use OnAcceptedMissionEvent.ProtoReflect.Descriptor instead.
func (*OnAcceptedMissionEvent) Descriptor() ([]byte, []int) {
	return file_event_proto_mission_event_proto_rawDescGZIP(), []int{2}
}

func (x *OnAcceptedMissionEvent) GetEntity() uint64 {
	if x != nil {
		return x.Entity
	}
	return 0
}

func (x *OnAcceptedMissionEvent) GetMissionId() uint32 {
	if x != nil {
		return x.MissionId
	}
	return 0
}

type OnMissionAwardEvent struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Entity    uint64 `protobuf:"varint,1,opt,name=entity,proto3" json:"entity,omitempty"`
	MissionId uint32 `protobuf:"varint,2,opt,name=mission_id,json=missionId,proto3" json:"mission_id,omitempty"`
}

func (x *OnMissionAwardEvent) Reset() {
	*x = OnMissionAwardEvent{}
	if protoimpl.UnsafeEnabled {
		mi := &file_event_proto_mission_event_proto_msgTypes[3]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *OnMissionAwardEvent) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*OnMissionAwardEvent) ProtoMessage() {}

func (x *OnMissionAwardEvent) ProtoReflect() protoreflect.Message {
	mi := &file_event_proto_mission_event_proto_msgTypes[3]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use OnMissionAwardEvent.ProtoReflect.Descriptor instead.
func (*OnMissionAwardEvent) Descriptor() ([]byte, []int) {
	return file_event_proto_mission_event_proto_rawDescGZIP(), []int{3}
}

func (x *OnMissionAwardEvent) GetEntity() uint64 {
	if x != nil {
		return x.Entity
	}
	return 0
}

func (x *OnMissionAwardEvent) GetMissionId() uint32 {
	if x != nil {
		return x.MissionId
	}
	return 0
}

var File_event_proto_mission_event_proto protoreflect.FileDescriptor

var file_event_proto_mission_event_proto_rawDesc = []byte{
	0x0a, 0x1f, 0x65, 0x76, 0x65, 0x6e, 0x74, 0x5f, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x2f, 0x6d, 0x69,
	0x73, 0x73, 0x69, 0x6f, 0x6e, 0x5f, 0x65, 0x76, 0x65, 0x6e, 0x74, 0x2e, 0x70, 0x72, 0x6f, 0x74,
	0x6f, 0x22, 0x4b, 0x0a, 0x12, 0x41, 0x63, 0x63, 0x65, 0x70, 0x74, 0x4d, 0x69, 0x73, 0x73, 0x69,
	0x6f, 0x6e, 0x45, 0x76, 0x65, 0x6e, 0x74, 0x12, 0x16, 0x0a, 0x06, 0x65, 0x6e, 0x74, 0x69, 0x74,
	0x79, 0x18, 0x01, 0x20, 0x01, 0x28, 0x04, 0x52, 0x06, 0x65, 0x6e, 0x74, 0x69, 0x74, 0x79, 0x12,
	0x1d, 0x0a, 0x0a, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x5f, 0x69, 0x64, 0x18, 0x02, 0x20,
	0x01, 0x28, 0x0d, 0x52, 0x09, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x49, 0x64, 0x22, 0x7e,
	0x0a, 0x15, 0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x43, 0x6f, 0x6e, 0x64, 0x69, 0x74, 0x69,
	0x6f, 0x6e, 0x45, 0x76, 0x65, 0x6e, 0x74, 0x12, 0x16, 0x0a, 0x06, 0x65, 0x6e, 0x74, 0x69, 0x74,
	0x79, 0x18, 0x01, 0x20, 0x01, 0x28, 0x04, 0x52, 0x06, 0x65, 0x6e, 0x74, 0x69, 0x74, 0x79, 0x12,
	0x12, 0x0a, 0x04, 0x74, 0x79, 0x70, 0x65, 0x18, 0x02, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x04, 0x74,
	0x79, 0x70, 0x65, 0x12, 0x21, 0x0a, 0x0c, 0x63, 0x6f, 0x6e, 0x64, 0x74, 0x69, 0x6f, 0x6e, 0x5f,
	0x69, 0x64, 0x73, 0x18, 0x03, 0x20, 0x03, 0x28, 0x0d, 0x52, 0x0b, 0x63, 0x6f, 0x6e, 0x64, 0x74,
	0x69, 0x6f, 0x6e, 0x49, 0x64, 0x73, 0x12, 0x16, 0x0a, 0x06, 0x61, 0x6d, 0x6f, 0x75, 0x6e, 0x74,
	0x18, 0x04, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x06, 0x61, 0x6d, 0x6f, 0x75, 0x6e, 0x74, 0x22, 0x4f,
	0x0a, 0x16, 0x4f, 0x6e, 0x41, 0x63, 0x63, 0x65, 0x70, 0x74, 0x65, 0x64, 0x4d, 0x69, 0x73, 0x73,
	0x69, 0x6f, 0x6e, 0x45, 0x76, 0x65, 0x6e, 0x74, 0x12, 0x16, 0x0a, 0x06, 0x65, 0x6e, 0x74, 0x69,
	0x74, 0x79, 0x18, 0x01, 0x20, 0x01, 0x28, 0x04, 0x52, 0x06, 0x65, 0x6e, 0x74, 0x69, 0x74, 0x79,
	0x12, 0x1d, 0x0a, 0x0a, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x5f, 0x69, 0x64, 0x18, 0x02,
	0x20, 0x01, 0x28, 0x0d, 0x52, 0x09, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x49, 0x64, 0x22,
	0x4c, 0x0a, 0x13, 0x4f, 0x6e, 0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x41, 0x77, 0x61, 0x72,
	0x64, 0x45, 0x76, 0x65, 0x6e, 0x74, 0x12, 0x16, 0x0a, 0x06, 0x65, 0x6e, 0x74, 0x69, 0x74, 0x79,
	0x18, 0x01, 0x20, 0x01, 0x28, 0x04, 0x52, 0x06, 0x65, 0x6e, 0x74, 0x69, 0x74, 0x79, 0x12, 0x1d,
	0x0a, 0x0a, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x5f, 0x69, 0x64, 0x18, 0x02, 0x20, 0x01,
	0x28, 0x0d, 0x52, 0x09, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x49, 0x64, 0x42, 0x09, 0x5a,
	0x07, 0x70, 0x62, 0x2f, 0x67, 0x61, 0x6d, 0x65, 0x62, 0x06, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x33,
}

var (
	file_event_proto_mission_event_proto_rawDescOnce sync.Once
	file_event_proto_mission_event_proto_rawDescData = file_event_proto_mission_event_proto_rawDesc
)

func file_event_proto_mission_event_proto_rawDescGZIP() []byte {
	file_event_proto_mission_event_proto_rawDescOnce.Do(func() {
		file_event_proto_mission_event_proto_rawDescData = protoimpl.X.CompressGZIP(file_event_proto_mission_event_proto_rawDescData)
	})
	return file_event_proto_mission_event_proto_rawDescData
}

var file_event_proto_mission_event_proto_msgTypes = make([]protoimpl.MessageInfo, 4)
var file_event_proto_mission_event_proto_goTypes = []interface{}{
	(*AcceptMissionEvent)(nil),     // 0: AcceptMissionEvent
	(*MissionConditionEvent)(nil),  // 1: MissionConditionEvent
	(*OnAcceptedMissionEvent)(nil), // 2: OnAcceptedMissionEvent
	(*OnMissionAwardEvent)(nil),    // 3: OnMissionAwardEvent
}
var file_event_proto_mission_event_proto_depIdxs = []int32{
	0, // [0:0] is the sub-list for method output_type
	0, // [0:0] is the sub-list for method input_type
	0, // [0:0] is the sub-list for extension type_name
	0, // [0:0] is the sub-list for extension extendee
	0, // [0:0] is the sub-list for field type_name
}

func init() { file_event_proto_mission_event_proto_init() }
func file_event_proto_mission_event_proto_init() {
	if File_event_proto_mission_event_proto != nil {
		return
	}
	if !protoimpl.UnsafeEnabled {
		file_event_proto_mission_event_proto_msgTypes[0].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*AcceptMissionEvent); i {
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
		file_event_proto_mission_event_proto_msgTypes[1].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*MissionConditionEvent); i {
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
		file_event_proto_mission_event_proto_msgTypes[2].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*OnAcceptedMissionEvent); i {
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
		file_event_proto_mission_event_proto_msgTypes[3].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*OnMissionAwardEvent); i {
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
			RawDescriptor: file_event_proto_mission_event_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   4,
			NumExtensions: 0,
			NumServices:   0,
		},
		GoTypes:           file_event_proto_mission_event_proto_goTypes,
		DependencyIndexes: file_event_proto_mission_event_proto_depIdxs,
		MessageInfos:      file_event_proto_mission_event_proto_msgTypes,
	}.Build()
	File_event_proto_mission_event_proto = out.File
	file_event_proto_mission_event_proto_rawDesc = nil
	file_event_proto_mission_event_proto_goTypes = nil
	file_event_proto_mission_event_proto_depIdxs = nil
}
