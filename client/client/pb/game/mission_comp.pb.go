// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.34.1
// 	protoc        v4.25.1
// source: logic/component/mission_comp.proto

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

type MissionPbCompEMissionStatus int32

const (
	MissionPbComp_E_MISSION_NORMAL      MissionPbCompEMissionStatus = 0
	MissionPbComp_E_MISSION_ACHIEVEMENT MissionPbCompEMissionStatus = 1
	MissionPbComp_E_MISSION_COMPLETE    MissionPbCompEMissionStatus = 2
	MissionPbComp_E_MISSION_TIME_OUT    MissionPbCompEMissionStatus = 3
	MissionPbComp_E_MISSION_FAILD       MissionPbCompEMissionStatus = 4
)

// Enum value maps for MissionPbCompEMissionStatus.
var (
	MissionPbCompEMissionStatus_name = map[int32]string{
		0: "E_MISSION_NORMAL",
		1: "E_MISSION_ACHIEVEMENT",
		2: "E_MISSION_COMPLETE",
		3: "E_MISSION_TIME_OUT",
		4: "E_MISSION_FAILD",
	}
	MissionPbCompEMissionStatus_value = map[string]int32{
		"E_MISSION_NORMAL":      0,
		"E_MISSION_ACHIEVEMENT": 1,
		"E_MISSION_COMPLETE":    2,
		"E_MISSION_TIME_OUT":    3,
		"E_MISSION_FAILD":       4,
	}
)

func (x MissionPbCompEMissionStatus) Enum() *MissionPbCompEMissionStatus {
	p := new(MissionPbCompEMissionStatus)
	*p = x
	return p
}

func (x MissionPbCompEMissionStatus) String() string {
	return protoimpl.X.EnumStringOf(x.Descriptor(), protoreflect.EnumNumber(x))
}

func (MissionPbCompEMissionStatus) Descriptor() protoreflect.EnumDescriptor {
	return file_logic_component_mission_comp_proto_enumTypes[0].Descriptor()
}

func (MissionPbCompEMissionStatus) Type() protoreflect.EnumType {
	return &file_logic_component_mission_comp_proto_enumTypes[0]
}

func (x MissionPbCompEMissionStatus) Number() protoreflect.EnumNumber {
	return protoreflect.EnumNumber(x)
}

// Deprecated: Use MissionPbCompEMissionStatus.Descriptor instead.
func (MissionPbCompEMissionStatus) EnumDescriptor() ([]byte, []int) {
	return file_logic_component_mission_comp_proto_rawDescGZIP(), []int{0, 0}
}

type MissionsPbCompEMissionType int32

const (
	MissionsPbComp_kPlayerMission       MissionsPbCompEMissionType = 0 //普通任务
	MissionsPbComp_kPlayerAchievment    MissionsPbCompEMissionType = 1 //成就
	MissionsPbComp_kPlayerDailyActivity MissionsPbCompEMissionType = 2 //每日活动
	MissionsPbComp_kPlayerMissionSize   MissionsPbCompEMissionType = 3 //最大值
)

// Enum value maps for MissionsPbCompEMissionType.
var (
	MissionsPbCompEMissionType_name = map[int32]string{
		0: "kPlayerMission",
		1: "kPlayerAchievment",
		2: "kPlayerDailyActivity",
		3: "kPlayerMissionSize",
	}
	MissionsPbCompEMissionType_value = map[string]int32{
		"kPlayerMission":       0,
		"kPlayerAchievment":    1,
		"kPlayerDailyActivity": 2,
		"kPlayerMissionSize":   3,
	}
)

func (x MissionsPbCompEMissionType) Enum() *MissionsPbCompEMissionType {
	p := new(MissionsPbCompEMissionType)
	*p = x
	return p
}

func (x MissionsPbCompEMissionType) String() string {
	return protoimpl.X.EnumStringOf(x.Descriptor(), protoreflect.EnumNumber(x))
}

func (MissionsPbCompEMissionType) Descriptor() protoreflect.EnumDescriptor {
	return file_logic_component_mission_comp_proto_enumTypes[1].Descriptor()
}

func (MissionsPbCompEMissionType) Type() protoreflect.EnumType {
	return &file_logic_component_mission_comp_proto_enumTypes[1]
}

func (x MissionsPbCompEMissionType) Number() protoreflect.EnumNumber {
	return protoreflect.EnumNumber(x)
}

// Deprecated: Use MissionsPbCompEMissionType.Descriptor instead.
func (MissionsPbCompEMissionType) EnumDescriptor() ([]byte, []int) {
	return file_logic_component_mission_comp_proto_rawDescGZIP(), []int{1, 0}
}

type MissionPbComp struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Id       uint32   `protobuf:"varint,1,opt,name=id,proto3" json:"id,omitempty"`
	Status   uint32   `protobuf:"varint,2,opt,name=status,proto3" json:"status,omitempty"`
	Progress []uint32 `protobuf:"varint,3,rep,packed,name=progress,proto3" json:"progress,omitempty"`
}

func (x *MissionPbComp) Reset() {
	*x = MissionPbComp{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_component_mission_comp_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *MissionPbComp) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*MissionPbComp) ProtoMessage() {}

func (x *MissionPbComp) ProtoReflect() protoreflect.Message {
	mi := &file_logic_component_mission_comp_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use MissionPbComp.ProtoReflect.Descriptor instead.
func (*MissionPbComp) Descriptor() ([]byte, []int) {
	return file_logic_component_mission_comp_proto_rawDescGZIP(), []int{0}
}

func (x *MissionPbComp) GetId() uint32 {
	if x != nil {
		return x.Id
	}
	return 0
}

func (x *MissionPbComp) GetStatus() uint32 {
	if x != nil {
		return x.Status
	}
	return 0
}

func (x *MissionPbComp) GetProgress() []uint32 {
	if x != nil {
		return x.Progress
	}
	return nil
}

type MissionsPbComp struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Missions         map[uint32]*MissionPbComp `protobuf:"bytes,1,rep,name=missions,proto3" json:"missions,omitempty" protobuf_key:"varint,1,opt,name=key,proto3" protobuf_val:"bytes,2,opt,name=value,proto3"`
	CompleteMissions map[uint32]bool           `protobuf:"bytes,2,rep,name=complete_missions,json=completeMissions,proto3" json:"complete_missions,omitempty" protobuf_key:"varint,1,opt,name=key,proto3" protobuf_val:"varint,2,opt,name=value,proto3"`
	MissionBeginTime map[uint32]uint64         `protobuf:"bytes,3,rep,name=mission_begin_time,json=missionBeginTime,proto3" json:"mission_begin_time,omitempty" protobuf_key:"varint,1,opt,name=key,proto3" protobuf_val:"varint,2,opt,name=value,proto3"`
	Type             uint32                    `protobuf:"varint,4,opt,name=type,proto3" json:"type,omitempty"`
}

func (x *MissionsPbComp) Reset() {
	*x = MissionsPbComp{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_component_mission_comp_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *MissionsPbComp) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*MissionsPbComp) ProtoMessage() {}

func (x *MissionsPbComp) ProtoReflect() protoreflect.Message {
	mi := &file_logic_component_mission_comp_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use MissionsPbComp.ProtoReflect.Descriptor instead.
func (*MissionsPbComp) Descriptor() ([]byte, []int) {
	return file_logic_component_mission_comp_proto_rawDescGZIP(), []int{1}
}

func (x *MissionsPbComp) GetMissions() map[uint32]*MissionPbComp {
	if x != nil {
		return x.Missions
	}
	return nil
}

func (x *MissionsPbComp) GetCompleteMissions() map[uint32]bool {
	if x != nil {
		return x.CompleteMissions
	}
	return nil
}

func (x *MissionsPbComp) GetMissionBeginTime() map[uint32]uint64 {
	if x != nil {
		return x.MissionBeginTime
	}
	return nil
}

func (x *MissionsPbComp) GetType() uint32 {
	if x != nil {
		return x.Type
	}
	return 0
}

type MissionRewardPbComp struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	CanRewardMissionId map[uint32]bool `protobuf:"bytes,2,rep,name=can_reward_mission_id,json=canRewardMissionId,proto3" json:"can_reward_mission_id,omitempty" protobuf_key:"varint,1,opt,name=key,proto3" protobuf_val:"varint,2,opt,name=value,proto3"`
}

func (x *MissionRewardPbComp) Reset() {
	*x = MissionRewardPbComp{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_component_mission_comp_proto_msgTypes[2]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *MissionRewardPbComp) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*MissionRewardPbComp) ProtoMessage() {}

func (x *MissionRewardPbComp) ProtoReflect() protoreflect.Message {
	mi := &file_logic_component_mission_comp_proto_msgTypes[2]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use MissionRewardPbComp.ProtoReflect.Descriptor instead.
func (*MissionRewardPbComp) Descriptor() ([]byte, []int) {
	return file_logic_component_mission_comp_proto_rawDescGZIP(), []int{2}
}

func (x *MissionRewardPbComp) GetCanRewardMissionId() map[uint32]bool {
	if x != nil {
		return x.CanRewardMissionId
	}
	return nil
}

var File_logic_component_mission_comp_proto protoreflect.FileDescriptor

var file_logic_component_mission_comp_proto_rawDesc = []byte{
	0x0a, 0x22, 0x6c, 0x6f, 0x67, 0x69, 0x63, 0x2f, 0x63, 0x6f, 0x6d, 0x70, 0x6f, 0x6e, 0x65, 0x6e,
	0x74, 0x2f, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x5f, 0x63, 0x6f, 0x6d, 0x70, 0x2e, 0x70,
	0x72, 0x6f, 0x74, 0x6f, 0x22, 0xdc, 0x01, 0x0a, 0x0d, 0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e,
	0x50, 0x62, 0x43, 0x6f, 0x6d, 0x70, 0x12, 0x0e, 0x0a, 0x02, 0x69, 0x64, 0x18, 0x01, 0x20, 0x01,
	0x28, 0x0d, 0x52, 0x02, 0x69, 0x64, 0x12, 0x16, 0x0a, 0x06, 0x73, 0x74, 0x61, 0x74, 0x75, 0x73,
	0x18, 0x02, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x06, 0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 0x12, 0x1a,
	0x0a, 0x08, 0x70, 0x72, 0x6f, 0x67, 0x72, 0x65, 0x73, 0x73, 0x18, 0x03, 0x20, 0x03, 0x28, 0x0d,
	0x52, 0x08, 0x70, 0x72, 0x6f, 0x67, 0x72, 0x65, 0x73, 0x73, 0x22, 0x86, 0x01, 0x0a, 0x0e, 0x65,
	0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x53, 0x74, 0x61, 0x74, 0x75, 0x73, 0x12, 0x14, 0x0a,
	0x10, 0x45, 0x5f, 0x4d, 0x49, 0x53, 0x53, 0x49, 0x4f, 0x4e, 0x5f, 0x4e, 0x4f, 0x52, 0x4d, 0x41,
	0x4c, 0x10, 0x00, 0x12, 0x19, 0x0a, 0x15, 0x45, 0x5f, 0x4d, 0x49, 0x53, 0x53, 0x49, 0x4f, 0x4e,
	0x5f, 0x41, 0x43, 0x48, 0x49, 0x45, 0x56, 0x45, 0x4d, 0x45, 0x4e, 0x54, 0x10, 0x01, 0x12, 0x16,
	0x0a, 0x12, 0x45, 0x5f, 0x4d, 0x49, 0x53, 0x53, 0x49, 0x4f, 0x4e, 0x5f, 0x43, 0x4f, 0x4d, 0x50,
	0x4c, 0x45, 0x54, 0x45, 0x10, 0x02, 0x12, 0x16, 0x0a, 0x12, 0x45, 0x5f, 0x4d, 0x49, 0x53, 0x53,
	0x49, 0x4f, 0x4e, 0x5f, 0x54, 0x49, 0x4d, 0x45, 0x5f, 0x4f, 0x55, 0x54, 0x10, 0x03, 0x12, 0x13,
	0x0a, 0x0f, 0x45, 0x5f, 0x4d, 0x49, 0x53, 0x53, 0x49, 0x4f, 0x4e, 0x5f, 0x46, 0x41, 0x49, 0x4c,
	0x44, 0x10, 0x04, 0x22, 0xcc, 0x04, 0x0a, 0x0e, 0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x73,
	0x50, 0x62, 0x43, 0x6f, 0x6d, 0x70, 0x12, 0x39, 0x0a, 0x08, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f,
	0x6e, 0x73, 0x18, 0x01, 0x20, 0x03, 0x28, 0x0b, 0x32, 0x1d, 0x2e, 0x4d, 0x69, 0x73, 0x73, 0x69,
	0x6f, 0x6e, 0x73, 0x50, 0x62, 0x43, 0x6f, 0x6d, 0x70, 0x2e, 0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f,
	0x6e, 0x73, 0x45, 0x6e, 0x74, 0x72, 0x79, 0x52, 0x08, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e,
	0x73, 0x12, 0x52, 0x0a, 0x11, 0x63, 0x6f, 0x6d, 0x70, 0x6c, 0x65, 0x74, 0x65, 0x5f, 0x6d, 0x69,
	0x73, 0x73, 0x69, 0x6f, 0x6e, 0x73, 0x18, 0x02, 0x20, 0x03, 0x28, 0x0b, 0x32, 0x25, 0x2e, 0x4d,
	0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x73, 0x50, 0x62, 0x43, 0x6f, 0x6d, 0x70, 0x2e, 0x43, 0x6f,
	0x6d, 0x70, 0x6c, 0x65, 0x74, 0x65, 0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x73, 0x45, 0x6e,
	0x74, 0x72, 0x79, 0x52, 0x10, 0x63, 0x6f, 0x6d, 0x70, 0x6c, 0x65, 0x74, 0x65, 0x4d, 0x69, 0x73,
	0x73, 0x69, 0x6f, 0x6e, 0x73, 0x12, 0x53, 0x0a, 0x12, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e,
	0x5f, 0x62, 0x65, 0x67, 0x69, 0x6e, 0x5f, 0x74, 0x69, 0x6d, 0x65, 0x18, 0x03, 0x20, 0x03, 0x28,
	0x0b, 0x32, 0x25, 0x2e, 0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x73, 0x50, 0x62, 0x43, 0x6f,
	0x6d, 0x70, 0x2e, 0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x42, 0x65, 0x67, 0x69, 0x6e, 0x54,
	0x69, 0x6d, 0x65, 0x45, 0x6e, 0x74, 0x72, 0x79, 0x52, 0x10, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f,
	0x6e, 0x42, 0x65, 0x67, 0x69, 0x6e, 0x54, 0x69, 0x6d, 0x65, 0x12, 0x12, 0x0a, 0x04, 0x74, 0x79,
	0x70, 0x65, 0x18, 0x04, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x04, 0x74, 0x79, 0x70, 0x65, 0x1a, 0x4b,
	0x0a, 0x0d, 0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x73, 0x45, 0x6e, 0x74, 0x72, 0x79, 0x12,
	0x10, 0x0a, 0x03, 0x6b, 0x65, 0x79, 0x18, 0x01, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x03, 0x6b, 0x65,
	0x79, 0x12, 0x24, 0x0a, 0x05, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x18, 0x02, 0x20, 0x01, 0x28, 0x0b,
	0x32, 0x0e, 0x2e, 0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x50, 0x62, 0x43, 0x6f, 0x6d, 0x70,
	0x52, 0x05, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x3a, 0x02, 0x38, 0x01, 0x1a, 0x43, 0x0a, 0x15, 0x43,
	0x6f, 0x6d, 0x70, 0x6c, 0x65, 0x74, 0x65, 0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x73, 0x45,
	0x6e, 0x74, 0x72, 0x79, 0x12, 0x10, 0x0a, 0x03, 0x6b, 0x65, 0x79, 0x18, 0x01, 0x20, 0x01, 0x28,
	0x0d, 0x52, 0x03, 0x6b, 0x65, 0x79, 0x12, 0x14, 0x0a, 0x05, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x18,
	0x02, 0x20, 0x01, 0x28, 0x08, 0x52, 0x05, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x3a, 0x02, 0x38, 0x01,
	0x1a, 0x43, 0x0a, 0x15, 0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x42, 0x65, 0x67, 0x69, 0x6e,
	0x54, 0x69, 0x6d, 0x65, 0x45, 0x6e, 0x74, 0x72, 0x79, 0x12, 0x10, 0x0a, 0x03, 0x6b, 0x65, 0x79,
	0x18, 0x01, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x03, 0x6b, 0x65, 0x79, 0x12, 0x14, 0x0a, 0x05, 0x76,
	0x61, 0x6c, 0x75, 0x65, 0x18, 0x02, 0x20, 0x01, 0x28, 0x04, 0x52, 0x05, 0x76, 0x61, 0x6c, 0x75,
	0x65, 0x3a, 0x02, 0x38, 0x01, 0x22, 0x6b, 0x0a, 0x0c, 0x65, 0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f,
	0x6e, 0x54, 0x79, 0x70, 0x65, 0x12, 0x12, 0x0a, 0x0e, 0x6b, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72,
	0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x10, 0x00, 0x12, 0x15, 0x0a, 0x11, 0x6b, 0x50, 0x6c,
	0x61, 0x79, 0x65, 0x72, 0x41, 0x63, 0x68, 0x69, 0x65, 0x76, 0x6d, 0x65, 0x6e, 0x74, 0x10, 0x01,
	0x12, 0x18, 0x0a, 0x14, 0x6b, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x44, 0x61, 0x69, 0x6c, 0x79,
	0x41, 0x63, 0x74, 0x69, 0x76, 0x69, 0x74, 0x79, 0x10, 0x02, 0x12, 0x16, 0x0a, 0x12, 0x6b, 0x50,
	0x6c, 0x61, 0x79, 0x65, 0x72, 0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x53, 0x69, 0x7a, 0x65,
	0x10, 0x03, 0x22, 0xbd, 0x01, 0x0a, 0x13, 0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x52, 0x65,
	0x77, 0x61, 0x72, 0x64, 0x50, 0x62, 0x43, 0x6f, 0x6d, 0x70, 0x12, 0x5f, 0x0a, 0x15, 0x63, 0x61,
	0x6e, 0x5f, 0x72, 0x65, 0x77, 0x61, 0x72, 0x64, 0x5f, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e,
	0x5f, 0x69, 0x64, 0x18, 0x02, 0x20, 0x03, 0x28, 0x0b, 0x32, 0x2c, 0x2e, 0x4d, 0x69, 0x73, 0x73,
	0x69, 0x6f, 0x6e, 0x52, 0x65, 0x77, 0x61, 0x72, 0x64, 0x50, 0x62, 0x43, 0x6f, 0x6d, 0x70, 0x2e,
	0x43, 0x61, 0x6e, 0x52, 0x65, 0x77, 0x61, 0x72, 0x64, 0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e,
	0x49, 0x64, 0x45, 0x6e, 0x74, 0x72, 0x79, 0x52, 0x12, 0x63, 0x61, 0x6e, 0x52, 0x65, 0x77, 0x61,
	0x72, 0x64, 0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x49, 0x64, 0x1a, 0x45, 0x0a, 0x17, 0x43,
	0x61, 0x6e, 0x52, 0x65, 0x77, 0x61, 0x72, 0x64, 0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x49,
	0x64, 0x45, 0x6e, 0x74, 0x72, 0x79, 0x12, 0x10, 0x0a, 0x03, 0x6b, 0x65, 0x79, 0x18, 0x01, 0x20,
	0x01, 0x28, 0x0d, 0x52, 0x03, 0x6b, 0x65, 0x79, 0x12, 0x14, 0x0a, 0x05, 0x76, 0x61, 0x6c, 0x75,
	0x65, 0x18, 0x02, 0x20, 0x01, 0x28, 0x08, 0x52, 0x05, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x3a, 0x02,
	0x38, 0x01, 0x42, 0x09, 0x5a, 0x07, 0x70, 0x62, 0x2f, 0x67, 0x61, 0x6d, 0x65, 0x62, 0x06, 0x70,
	0x72, 0x6f, 0x74, 0x6f, 0x33,
}

var (
	file_logic_component_mission_comp_proto_rawDescOnce sync.Once
	file_logic_component_mission_comp_proto_rawDescData = file_logic_component_mission_comp_proto_rawDesc
)

func file_logic_component_mission_comp_proto_rawDescGZIP() []byte {
	file_logic_component_mission_comp_proto_rawDescOnce.Do(func() {
		file_logic_component_mission_comp_proto_rawDescData = protoimpl.X.CompressGZIP(file_logic_component_mission_comp_proto_rawDescData)
	})
	return file_logic_component_mission_comp_proto_rawDescData
}

var file_logic_component_mission_comp_proto_enumTypes = make([]protoimpl.EnumInfo, 2)
var file_logic_component_mission_comp_proto_msgTypes = make([]protoimpl.MessageInfo, 7)
var file_logic_component_mission_comp_proto_goTypes = []interface{}{
	(MissionPbCompEMissionStatus)(0), // 0: MissionPbComp.eMissionStatus
	(MissionsPbCompEMissionType)(0),  // 1: MissionsPbComp.eMissionType
	(*MissionPbComp)(nil),            // 2: MissionPbComp
	(*MissionsPbComp)(nil),           // 3: MissionsPbComp
	(*MissionRewardPbComp)(nil),      // 4: MissionRewardPbComp
	nil,                              // 5: MissionsPbComp.MissionsEntry
	nil,                              // 6: MissionsPbComp.CompleteMissionsEntry
	nil,                              // 7: MissionsPbComp.MissionBeginTimeEntry
	nil,                              // 8: MissionRewardPbComp.CanRewardMissionIdEntry
}
var file_logic_component_mission_comp_proto_depIdxs = []int32{
	5, // 0: MissionsPbComp.missions:type_name -> MissionsPbComp.MissionsEntry
	6, // 1: MissionsPbComp.complete_missions:type_name -> MissionsPbComp.CompleteMissionsEntry
	7, // 2: MissionsPbComp.mission_begin_time:type_name -> MissionsPbComp.MissionBeginTimeEntry
	8, // 3: MissionRewardPbComp.can_reward_mission_id:type_name -> MissionRewardPbComp.CanRewardMissionIdEntry
	2, // 4: MissionsPbComp.MissionsEntry.value:type_name -> MissionPbComp
	5, // [5:5] is the sub-list for method output_type
	5, // [5:5] is the sub-list for method input_type
	5, // [5:5] is the sub-list for extension type_name
	5, // [5:5] is the sub-list for extension extendee
	0, // [0:5] is the sub-list for field type_name
}

func init() { file_logic_component_mission_comp_proto_init() }
func file_logic_component_mission_comp_proto_init() {
	if File_logic_component_mission_comp_proto != nil {
		return
	}
	if !protoimpl.UnsafeEnabled {
		file_logic_component_mission_comp_proto_msgTypes[0].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*MissionPbComp); i {
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
		file_logic_component_mission_comp_proto_msgTypes[1].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*MissionsPbComp); i {
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
		file_logic_component_mission_comp_proto_msgTypes[2].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*MissionRewardPbComp); i {
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
			RawDescriptor: file_logic_component_mission_comp_proto_rawDesc,
			NumEnums:      2,
			NumMessages:   7,
			NumExtensions: 0,
			NumServices:   0,
		},
		GoTypes:           file_logic_component_mission_comp_proto_goTypes,
		DependencyIndexes: file_logic_component_mission_comp_proto_depIdxs,
		EnumInfos:         file_logic_component_mission_comp_proto_enumTypes,
		MessageInfos:      file_logic_component_mission_comp_proto_msgTypes,
	}.Build()
	File_logic_component_mission_comp_proto = out.File
	file_logic_component_mission_comp_proto_rawDesc = nil
	file_logic_component_mission_comp_proto_goTypes = nil
	file_logic_component_mission_comp_proto_depIdxs = nil
}
