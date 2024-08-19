// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.34.2
// 	protoc        v5.26.1
// source: logic/component/scene_comp.proto

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

type CentreChangeSceneInfoPBCompEChangeGsStatus int32

const (
	CentreChangeSceneInfoPBComp_eLeaveGsScene            CentreChangeSceneInfoPBCompEChangeGsStatus = 0 //等待老gs保存完毕
	CentreChangeSceneInfoPBComp_eEnterGsSceneSucceed     CentreChangeSceneInfoPBCompEChangeGsStatus = 1 //不同服务器要走完这步
	CentreChangeSceneInfoPBComp_eGateEnterGsSceneSucceed CentreChangeSceneInfoPBCompEChangeGsStatus = 2 //todo换的时候gate断线了
)

// Enum value maps for CentreChangeSceneInfoPBCompEChangeGsStatus.
var (
	CentreChangeSceneInfoPBCompEChangeGsStatus_name = map[int32]string{
		0: "eLeaveGsScene",
		1: "eEnterGsSceneSucceed",
		2: "eGateEnterGsSceneSucceed",
	}
	CentreChangeSceneInfoPBCompEChangeGsStatus_value = map[string]int32{
		"eLeaveGsScene":            0,
		"eEnterGsSceneSucceed":     1,
		"eGateEnterGsSceneSucceed": 2,
	}
)

func (x CentreChangeSceneInfoPBCompEChangeGsStatus) Enum() *CentreChangeSceneInfoPBCompEChangeGsStatus {
	p := new(CentreChangeSceneInfoPBCompEChangeGsStatus)
	*p = x
	return p
}

func (x CentreChangeSceneInfoPBCompEChangeGsStatus) String() string {
	return protoimpl.X.EnumStringOf(x.Descriptor(), protoreflect.EnumNumber(x))
}

func (CentreChangeSceneInfoPBCompEChangeGsStatus) Descriptor() protoreflect.EnumDescriptor {
	return file_logic_component_scene_comp_proto_enumTypes[0].Descriptor()
}

func (CentreChangeSceneInfoPBCompEChangeGsStatus) Type() protoreflect.EnumType {
	return &file_logic_component_scene_comp_proto_enumTypes[0]
}

func (x CentreChangeSceneInfoPBCompEChangeGsStatus) Number() protoreflect.EnumNumber {
	return protoreflect.EnumNumber(x)
}

// Deprecated: Use CentreChangeSceneInfoPBCompEChangeGsStatus.Descriptor instead.
func (CentreChangeSceneInfoPBCompEChangeGsStatus) EnumDescriptor() ([]byte, []int) {
	return file_logic_component_scene_comp_proto_rawDescGZIP(), []int{1, 0}
}

type CentreChangeSceneInfoPBCompEChangeGsType int32

const (
	CentreChangeSceneInfoPBComp_eSameGs      CentreChangeSceneInfoPBCompEChangeGsType = 0 //同服务器间切换
	CentreChangeSceneInfoPBComp_eDifferentGs CentreChangeSceneInfoPBCompEChangeGsType = 1 //不同服务器间切换
)

// Enum value maps for CentreChangeSceneInfoPBCompEChangeGsType.
var (
	CentreChangeSceneInfoPBCompEChangeGsType_name = map[int32]string{
		0: "eSameGs",
		1: "eDifferentGs",
	}
	CentreChangeSceneInfoPBCompEChangeGsType_value = map[string]int32{
		"eSameGs":      0,
		"eDifferentGs": 1,
	}
)

func (x CentreChangeSceneInfoPBCompEChangeGsType) Enum() *CentreChangeSceneInfoPBCompEChangeGsType {
	p := new(CentreChangeSceneInfoPBCompEChangeGsType)
	*p = x
	return p
}

func (x CentreChangeSceneInfoPBCompEChangeGsType) String() string {
	return protoimpl.X.EnumStringOf(x.Descriptor(), protoreflect.EnumNumber(x))
}

func (CentreChangeSceneInfoPBCompEChangeGsType) Descriptor() protoreflect.EnumDescriptor {
	return file_logic_component_scene_comp_proto_enumTypes[1].Descriptor()
}

func (CentreChangeSceneInfoPBCompEChangeGsType) Type() protoreflect.EnumType {
	return &file_logic_component_scene_comp_proto_enumTypes[1]
}

func (x CentreChangeSceneInfoPBCompEChangeGsType) Number() protoreflect.EnumNumber {
	return protoreflect.EnumNumber(x)
}

// Deprecated: Use CentreChangeSceneInfoPBCompEChangeGsType.Descriptor instead.
func (CentreChangeSceneInfoPBCompEChangeGsType) EnumDescriptor() ([]byte, []int) {
	return file_logic_component_scene_comp_proto_rawDescGZIP(), []int{1, 1}
}

type SceneInfoPBComp struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	SceneConfid  uint32          `protobuf:"varint,1,opt,name=scene_confid,json=sceneConfid,proto3" json:"scene_confid,omitempty"`                                                                 //场景id
	Guid         uint32          `protobuf:"varint,2,opt,name=guid,proto3" json:"guid,omitempty"`                                                                                                  //场景唯一id
	MirrorConfid uint32          `protobuf:"varint,3,opt,name=mirror_confid,json=mirrorConfid,proto3" json:"mirror_confid,omitempty"`                                                              //镜像id
	DungenConfid uint32          `protobuf:"varint,4,opt,name=dungen_confid,json=dungenConfid,proto3" json:"dungen_confid,omitempty"`                                                              //副本id
	Creators     map[uint64]bool `protobuf:"bytes,5,rep,name=creators,proto3" json:"creators,omitempty" protobuf_key:"varint,1,opt,name=key,proto3" protobuf_val:"varint,2,opt,name=value,proto3"` //创建者
}

func (x *SceneInfoPBComp) Reset() {
	*x = SceneInfoPBComp{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_component_scene_comp_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *SceneInfoPBComp) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*SceneInfoPBComp) ProtoMessage() {}

func (x *SceneInfoPBComp) ProtoReflect() protoreflect.Message {
	mi := &file_logic_component_scene_comp_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use SceneInfoPBComp.ProtoReflect.Descriptor instead.
func (*SceneInfoPBComp) Descriptor() ([]byte, []int) {
	return file_logic_component_scene_comp_proto_rawDescGZIP(), []int{0}
}

func (x *SceneInfoPBComp) GetSceneConfid() uint32 {
	if x != nil {
		return x.SceneConfid
	}
	return 0
}

func (x *SceneInfoPBComp) GetGuid() uint32 {
	if x != nil {
		return x.Guid
	}
	return 0
}

func (x *SceneInfoPBComp) GetMirrorConfid() uint32 {
	if x != nil {
		return x.MirrorConfid
	}
	return 0
}

func (x *SceneInfoPBComp) GetDungenConfid() uint32 {
	if x != nil {
		return x.DungenConfid
	}
	return 0
}

func (x *SceneInfoPBComp) GetCreators() map[uint64]bool {
	if x != nil {
		return x.Creators
	}
	return nil
}

type CentreChangeSceneInfoPBComp struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	SceneConfid    uint32 `protobuf:"varint,1,opt,name=scene_confid,json=sceneConfid,proto3" json:"scene_confid,omitempty"`
	Guid           uint32 `protobuf:"varint,2,opt,name=guid,proto3" json:"guid,omitempty"` //场景id
	DungenConfid   uint32 `protobuf:"varint,3,opt,name=dungen_confid,json=dungenConfid,proto3" json:"dungen_confid,omitempty"`
	MirrorConfid   uint32 `protobuf:"varint,4,opt,name=mirror_confid,json=mirrorConfid,proto3" json:"mirror_confid,omitempty"`
	ChangeSequence uint32 `protobuf:"varint,5,opt,name=change_sequence,json=changeSequence,proto3" json:"change_sequence,omitempty"`
	ChangeGsType   uint32 `protobuf:"varint,6,opt,name=change_gs_type,json=changeGsType,proto3" json:"change_gs_type,omitempty"`
	ChangeGsStatus uint32 `protobuf:"varint,7,opt,name=change_gs_status,json=changeGsStatus,proto3" json:"change_gs_status,omitempty"` //eChangeGsStatus
	ChangeTime     uint64 `protobuf:"varint,8,opt,name=change_time,json=changeTime,proto3" json:"change_time,omitempty"`               //设置超时，超时代表服务器崩溃了,或者网络延时
	IgnoreFull     bool   `protobuf:"varint,9,opt,name=ignore_full,json=ignoreFull,proto3" json:"ignore_full,omitempty"`               //忽略人数满了
	Processing     bool   `protobuf:"varint,10,opt,name=processing,proto3" json:"processing,omitempty"`
}

func (x *CentreChangeSceneInfoPBComp) Reset() {
	*x = CentreChangeSceneInfoPBComp{}
	if protoimpl.UnsafeEnabled {
		mi := &file_logic_component_scene_comp_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *CentreChangeSceneInfoPBComp) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*CentreChangeSceneInfoPBComp) ProtoMessage() {}

func (x *CentreChangeSceneInfoPBComp) ProtoReflect() protoreflect.Message {
	mi := &file_logic_component_scene_comp_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use CentreChangeSceneInfoPBComp.ProtoReflect.Descriptor instead.
func (*CentreChangeSceneInfoPBComp) Descriptor() ([]byte, []int) {
	return file_logic_component_scene_comp_proto_rawDescGZIP(), []int{1}
}

func (x *CentreChangeSceneInfoPBComp) GetSceneConfid() uint32 {
	if x != nil {
		return x.SceneConfid
	}
	return 0
}

func (x *CentreChangeSceneInfoPBComp) GetGuid() uint32 {
	if x != nil {
		return x.Guid
	}
	return 0
}

func (x *CentreChangeSceneInfoPBComp) GetDungenConfid() uint32 {
	if x != nil {
		return x.DungenConfid
	}
	return 0
}

func (x *CentreChangeSceneInfoPBComp) GetMirrorConfid() uint32 {
	if x != nil {
		return x.MirrorConfid
	}
	return 0
}

func (x *CentreChangeSceneInfoPBComp) GetChangeSequence() uint32 {
	if x != nil {
		return x.ChangeSequence
	}
	return 0
}

func (x *CentreChangeSceneInfoPBComp) GetChangeGsType() uint32 {
	if x != nil {
		return x.ChangeGsType
	}
	return 0
}

func (x *CentreChangeSceneInfoPBComp) GetChangeGsStatus() uint32 {
	if x != nil {
		return x.ChangeGsStatus
	}
	return 0
}

func (x *CentreChangeSceneInfoPBComp) GetChangeTime() uint64 {
	if x != nil {
		return x.ChangeTime
	}
	return 0
}

func (x *CentreChangeSceneInfoPBComp) GetIgnoreFull() bool {
	if x != nil {
		return x.IgnoreFull
	}
	return false
}

func (x *CentreChangeSceneInfoPBComp) GetProcessing() bool {
	if x != nil {
		return x.Processing
	}
	return false
}

var File_logic_component_scene_comp_proto protoreflect.FileDescriptor

var file_logic_component_scene_comp_proto_rawDesc = []byte{
	0x0a, 0x20, 0x6c, 0x6f, 0x67, 0x69, 0x63, 0x2f, 0x63, 0x6f, 0x6d, 0x70, 0x6f, 0x6e, 0x65, 0x6e,
	0x74, 0x2f, 0x73, 0x63, 0x65, 0x6e, 0x65, 0x5f, 0x63, 0x6f, 0x6d, 0x70, 0x2e, 0x70, 0x72, 0x6f,
	0x74, 0x6f, 0x22, 0x8b, 0x02, 0x0a, 0x0f, 0x53, 0x63, 0x65, 0x6e, 0x65, 0x49, 0x6e, 0x66, 0x6f,
	0x50, 0x42, 0x43, 0x6f, 0x6d, 0x70, 0x12, 0x21, 0x0a, 0x0c, 0x73, 0x63, 0x65, 0x6e, 0x65, 0x5f,
	0x63, 0x6f, 0x6e, 0x66, 0x69, 0x64, 0x18, 0x01, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x0b, 0x73, 0x63,
	0x65, 0x6e, 0x65, 0x43, 0x6f, 0x6e, 0x66, 0x69, 0x64, 0x12, 0x12, 0x0a, 0x04, 0x67, 0x75, 0x69,
	0x64, 0x18, 0x02, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x04, 0x67, 0x75, 0x69, 0x64, 0x12, 0x23, 0x0a,
	0x0d, 0x6d, 0x69, 0x72, 0x72, 0x6f, 0x72, 0x5f, 0x63, 0x6f, 0x6e, 0x66, 0x69, 0x64, 0x18, 0x03,
	0x20, 0x01, 0x28, 0x0d, 0x52, 0x0c, 0x6d, 0x69, 0x72, 0x72, 0x6f, 0x72, 0x43, 0x6f, 0x6e, 0x66,
	0x69, 0x64, 0x12, 0x23, 0x0a, 0x0d, 0x64, 0x75, 0x6e, 0x67, 0x65, 0x6e, 0x5f, 0x63, 0x6f, 0x6e,
	0x66, 0x69, 0x64, 0x18, 0x04, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x0c, 0x64, 0x75, 0x6e, 0x67, 0x65,
	0x6e, 0x43, 0x6f, 0x6e, 0x66, 0x69, 0x64, 0x12, 0x3a, 0x0a, 0x08, 0x63, 0x72, 0x65, 0x61, 0x74,
	0x6f, 0x72, 0x73, 0x18, 0x05, 0x20, 0x03, 0x28, 0x0b, 0x32, 0x1e, 0x2e, 0x53, 0x63, 0x65, 0x6e,
	0x65, 0x49, 0x6e, 0x66, 0x6f, 0x50, 0x42, 0x43, 0x6f, 0x6d, 0x70, 0x2e, 0x43, 0x72, 0x65, 0x61,
	0x74, 0x6f, 0x72, 0x73, 0x45, 0x6e, 0x74, 0x72, 0x79, 0x52, 0x08, 0x63, 0x72, 0x65, 0x61, 0x74,
	0x6f, 0x72, 0x73, 0x1a, 0x3b, 0x0a, 0x0d, 0x43, 0x72, 0x65, 0x61, 0x74, 0x6f, 0x72, 0x73, 0x45,
	0x6e, 0x74, 0x72, 0x79, 0x12, 0x10, 0x0a, 0x03, 0x6b, 0x65, 0x79, 0x18, 0x01, 0x20, 0x01, 0x28,
	0x04, 0x52, 0x03, 0x6b, 0x65, 0x79, 0x12, 0x14, 0x0a, 0x05, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x18,
	0x02, 0x20, 0x01, 0x28, 0x08, 0x52, 0x05, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x3a, 0x02, 0x38, 0x01,
	0x22, 0x87, 0x04, 0x0a, 0x1b, 0x43, 0x65, 0x6e, 0x74, 0x72, 0x65, 0x43, 0x68, 0x61, 0x6e, 0x67,
	0x65, 0x53, 0x63, 0x65, 0x6e, 0x65, 0x49, 0x6e, 0x66, 0x6f, 0x50, 0x42, 0x43, 0x6f, 0x6d, 0x70,
	0x12, 0x21, 0x0a, 0x0c, 0x73, 0x63, 0x65, 0x6e, 0x65, 0x5f, 0x63, 0x6f, 0x6e, 0x66, 0x69, 0x64,
	0x18, 0x01, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x0b, 0x73, 0x63, 0x65, 0x6e, 0x65, 0x43, 0x6f, 0x6e,
	0x66, 0x69, 0x64, 0x12, 0x12, 0x0a, 0x04, 0x67, 0x75, 0x69, 0x64, 0x18, 0x02, 0x20, 0x01, 0x28,
	0x0d, 0x52, 0x04, 0x67, 0x75, 0x69, 0x64, 0x12, 0x23, 0x0a, 0x0d, 0x64, 0x75, 0x6e, 0x67, 0x65,
	0x6e, 0x5f, 0x63, 0x6f, 0x6e, 0x66, 0x69, 0x64, 0x18, 0x03, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x0c,
	0x64, 0x75, 0x6e, 0x67, 0x65, 0x6e, 0x43, 0x6f, 0x6e, 0x66, 0x69, 0x64, 0x12, 0x23, 0x0a, 0x0d,
	0x6d, 0x69, 0x72, 0x72, 0x6f, 0x72, 0x5f, 0x63, 0x6f, 0x6e, 0x66, 0x69, 0x64, 0x18, 0x04, 0x20,
	0x01, 0x28, 0x0d, 0x52, 0x0c, 0x6d, 0x69, 0x72, 0x72, 0x6f, 0x72, 0x43, 0x6f, 0x6e, 0x66, 0x69,
	0x64, 0x12, 0x27, 0x0a, 0x0f, 0x63, 0x68, 0x61, 0x6e, 0x67, 0x65, 0x5f, 0x73, 0x65, 0x71, 0x75,
	0x65, 0x6e, 0x63, 0x65, 0x18, 0x05, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x0e, 0x63, 0x68, 0x61, 0x6e,
	0x67, 0x65, 0x53, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x65, 0x12, 0x24, 0x0a, 0x0e, 0x63, 0x68,
	0x61, 0x6e, 0x67, 0x65, 0x5f, 0x67, 0x73, 0x5f, 0x74, 0x79, 0x70, 0x65, 0x18, 0x06, 0x20, 0x01,
	0x28, 0x0d, 0x52, 0x0c, 0x63, 0x68, 0x61, 0x6e, 0x67, 0x65, 0x47, 0x73, 0x54, 0x79, 0x70, 0x65,
	0x12, 0x28, 0x0a, 0x10, 0x63, 0x68, 0x61, 0x6e, 0x67, 0x65, 0x5f, 0x67, 0x73, 0x5f, 0x73, 0x74,
	0x61, 0x74, 0x75, 0x73, 0x18, 0x07, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x0e, 0x63, 0x68, 0x61, 0x6e,
	0x67, 0x65, 0x47, 0x73, 0x53, 0x74, 0x61, 0x74, 0x75, 0x73, 0x12, 0x1f, 0x0a, 0x0b, 0x63, 0x68,
	0x61, 0x6e, 0x67, 0x65, 0x5f, 0x74, 0x69, 0x6d, 0x65, 0x18, 0x08, 0x20, 0x01, 0x28, 0x04, 0x52,
	0x0a, 0x63, 0x68, 0x61, 0x6e, 0x67, 0x65, 0x54, 0x69, 0x6d, 0x65, 0x12, 0x1f, 0x0a, 0x0b, 0x69,
	0x67, 0x6e, 0x6f, 0x72, 0x65, 0x5f, 0x66, 0x75, 0x6c, 0x6c, 0x18, 0x09, 0x20, 0x01, 0x28, 0x08,
	0x52, 0x0a, 0x69, 0x67, 0x6e, 0x6f, 0x72, 0x65, 0x46, 0x75, 0x6c, 0x6c, 0x12, 0x1e, 0x0a, 0x0a,
	0x70, 0x72, 0x6f, 0x63, 0x65, 0x73, 0x73, 0x69, 0x6e, 0x67, 0x18, 0x0a, 0x20, 0x01, 0x28, 0x08,
	0x52, 0x0a, 0x70, 0x72, 0x6f, 0x63, 0x65, 0x73, 0x73, 0x69, 0x6e, 0x67, 0x22, 0x5c, 0x0a, 0x0f,
	0x65, 0x43, 0x68, 0x61, 0x6e, 0x67, 0x65, 0x47, 0x73, 0x53, 0x74, 0x61, 0x74, 0x75, 0x73, 0x12,
	0x11, 0x0a, 0x0d, 0x65, 0x4c, 0x65, 0x61, 0x76, 0x65, 0x47, 0x73, 0x53, 0x63, 0x65, 0x6e, 0x65,
	0x10, 0x00, 0x12, 0x18, 0x0a, 0x14, 0x65, 0x45, 0x6e, 0x74, 0x65, 0x72, 0x47, 0x73, 0x53, 0x63,
	0x65, 0x6e, 0x65, 0x53, 0x75, 0x63, 0x63, 0x65, 0x65, 0x64, 0x10, 0x01, 0x12, 0x1c, 0x0a, 0x18,
	0x65, 0x47, 0x61, 0x74, 0x65, 0x45, 0x6e, 0x74, 0x65, 0x72, 0x47, 0x73, 0x53, 0x63, 0x65, 0x6e,
	0x65, 0x53, 0x75, 0x63, 0x63, 0x65, 0x65, 0x64, 0x10, 0x02, 0x22, 0x2e, 0x0a, 0x0d, 0x65, 0x43,
	0x68, 0x61, 0x6e, 0x67, 0x65, 0x47, 0x73, 0x54, 0x79, 0x70, 0x65, 0x12, 0x0b, 0x0a, 0x07, 0x65,
	0x53, 0x61, 0x6d, 0x65, 0x47, 0x73, 0x10, 0x00, 0x12, 0x10, 0x0a, 0x0c, 0x65, 0x44, 0x69, 0x66,
	0x66, 0x65, 0x72, 0x65, 0x6e, 0x74, 0x47, 0x73, 0x10, 0x01, 0x42, 0x09, 0x5a, 0x07, 0x70, 0x62,
	0x2f, 0x67, 0x61, 0x6d, 0x65, 0x62, 0x06, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x33,
}

var (
	file_logic_component_scene_comp_proto_rawDescOnce sync.Once
	file_logic_component_scene_comp_proto_rawDescData = file_logic_component_scene_comp_proto_rawDesc
)

func file_logic_component_scene_comp_proto_rawDescGZIP() []byte {
	file_logic_component_scene_comp_proto_rawDescOnce.Do(func() {
		file_logic_component_scene_comp_proto_rawDescData = protoimpl.X.CompressGZIP(file_logic_component_scene_comp_proto_rawDescData)
	})
	return file_logic_component_scene_comp_proto_rawDescData
}

var file_logic_component_scene_comp_proto_enumTypes = make([]protoimpl.EnumInfo, 2)
var file_logic_component_scene_comp_proto_msgTypes = make([]protoimpl.MessageInfo, 3)
var file_logic_component_scene_comp_proto_goTypes = []any{
	(CentreChangeSceneInfoPBCompEChangeGsStatus)(0), // 0: CentreChangeSceneInfoPBComp.eChangeGsStatus
	(CentreChangeSceneInfoPBCompEChangeGsType)(0),   // 1: CentreChangeSceneInfoPBComp.eChangeGsType
	(*SceneInfoPBComp)(nil),                         // 2: SceneInfoPBComp
	(*CentreChangeSceneInfoPBComp)(nil),             // 3: CentreChangeSceneInfoPBComp
	nil,                                             // 4: SceneInfoPBComp.CreatorsEntry
}
var file_logic_component_scene_comp_proto_depIdxs = []int32{
	4, // 0: SceneInfoPBComp.creators:type_name -> SceneInfoPBComp.CreatorsEntry
	1, // [1:1] is the sub-list for method output_type
	1, // [1:1] is the sub-list for method input_type
	1, // [1:1] is the sub-list for extension type_name
	1, // [1:1] is the sub-list for extension extendee
	0, // [0:1] is the sub-list for field type_name
}

func init() { file_logic_component_scene_comp_proto_init() }
func file_logic_component_scene_comp_proto_init() {
	if File_logic_component_scene_comp_proto != nil {
		return
	}
	if !protoimpl.UnsafeEnabled {
		file_logic_component_scene_comp_proto_msgTypes[0].Exporter = func(v any, i int) any {
			switch v := v.(*SceneInfoPBComp); i {
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
		file_logic_component_scene_comp_proto_msgTypes[1].Exporter = func(v any, i int) any {
			switch v := v.(*CentreChangeSceneInfoPBComp); i {
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
			RawDescriptor: file_logic_component_scene_comp_proto_rawDesc,
			NumEnums:      2,
			NumMessages:   3,
			NumExtensions: 0,
			NumServices:   0,
		},
		GoTypes:           file_logic_component_scene_comp_proto_goTypes,
		DependencyIndexes: file_logic_component_scene_comp_proto_depIdxs,
		EnumInfos:         file_logic_component_scene_comp_proto_enumTypes,
		MessageInfos:      file_logic_component_scene_comp_proto_msgTypes,
	}.Build()
	File_logic_component_scene_comp_proto = out.File
	file_logic_component_scene_comp_proto_rawDesc = nil
	file_logic_component_scene_comp_proto_goTypes = nil
	file_logic_component_scene_comp_proto_depIdxs = nil
}
