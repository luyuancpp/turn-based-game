// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.34.2
// 	protoc        v5.26.1
// source: common/mysql_database_table.proto

package game

import (
	_ "github.com/luyuancpp/dbprotooption"
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

// ///////////         game
type UserAccounts struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Account       string                   `protobuf:"bytes,1,opt,name=account,proto3" json:"account,omitempty"`
	Password      string                   `protobuf:"bytes,2,opt,name=password,proto3" json:"password,omitempty"`
	SimplePlayers *AccountSimplePlayerList `protobuf:"bytes,3,opt,name=simple_players,json=simplePlayers,proto3" json:"simple_players,omitempty"`
}

func (x *UserAccounts) Reset() {
	*x = UserAccounts{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_mysql_database_table_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *UserAccounts) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*UserAccounts) ProtoMessage() {}

func (x *UserAccounts) ProtoReflect() protoreflect.Message {
	mi := &file_common_mysql_database_table_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use UserAccounts.ProtoReflect.Descriptor instead.
func (*UserAccounts) Descriptor() ([]byte, []int) {
	return file_common_mysql_database_table_proto_rawDescGZIP(), []int{0}
}

func (x *UserAccounts) GetAccount() string {
	if x != nil {
		return x.Account
	}
	return ""
}

func (x *UserAccounts) GetPassword() string {
	if x != nil {
		return x.Password
	}
	return ""
}

func (x *UserAccounts) GetSimplePlayers() *AccountSimplePlayerList {
	if x != nil {
		return x.SimplePlayers
	}
	return nil
}

type AccountShareDatabase struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Account string `protobuf:"bytes,1,opt,name=account,proto3" json:"account,omitempty"`
}

func (x *AccountShareDatabase) Reset() {
	*x = AccountShareDatabase{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_mysql_database_table_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *AccountShareDatabase) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*AccountShareDatabase) ProtoMessage() {}

func (x *AccountShareDatabase) ProtoReflect() protoreflect.Message {
	mi := &file_common_mysql_database_table_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use AccountShareDatabase.ProtoReflect.Descriptor instead.
func (*AccountShareDatabase) Descriptor() ([]byte, []int) {
	return file_common_mysql_database_table_proto_rawDescGZIP(), []int{1}
}

func (x *AccountShareDatabase) GetAccount() string {
	if x != nil {
		return x.Account
	}
	return ""
}

// 中心服玩家专用数据
type PlayerCentreDatabase struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	PlayerId  uint64                    `protobuf:"varint,1,opt,name=player_id,json=playerId,proto3" json:"player_id,omitempty"`
	SceneInfo *PlayerSceneContextPBComp `protobuf:"bytes,2,opt,name=scene_info,json=sceneInfo,proto3" json:"scene_info,omitempty"`
}

func (x *PlayerCentreDatabase) Reset() {
	*x = PlayerCentreDatabase{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_mysql_database_table_proto_msgTypes[2]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *PlayerCentreDatabase) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*PlayerCentreDatabase) ProtoMessage() {}

func (x *PlayerCentreDatabase) ProtoReflect() protoreflect.Message {
	mi := &file_common_mysql_database_table_proto_msgTypes[2]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use PlayerCentreDatabase.ProtoReflect.Descriptor instead.
func (*PlayerCentreDatabase) Descriptor() ([]byte, []int) {
	return file_common_mysql_database_table_proto_rawDescGZIP(), []int{2}
}

func (x *PlayerCentreDatabase) GetPlayerId() uint64 {
	if x != nil {
		return x.PlayerId
	}
	return 0
}

func (x *PlayerCentreDatabase) GetSceneInfo() *PlayerSceneContextPBComp {
	if x != nil {
		return x.SceneInfo
	}
	return nil
}

// 玩家数据库表1,重要数据放这里，不重要数据放另外一个表，(重要:比如金钱，跟收入有关)，登录马上加载
type PlayerDatabase struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	PlayerId     uint64                 `protobuf:"varint,1,opt,name=player_id,json=playerId,proto3" json:"player_id,omitempty"`
	Transform    *Transform             `protobuf:"bytes,2,opt,name=transform,proto3" json:"transform,omitempty"`
	Uint64PbComp *PlayerUint64PBComp    `protobuf:"bytes,3,opt,name=uint64_pb_comp,json=uint64PbComp,proto3" json:"uint64_pb_comp,omitempty"`
	SkillList    *PlayerSkillListPBComp `protobuf:"bytes,4,opt,name=skill_list,json=skillList,proto3" json:"skill_list,omitempty"`
	Uint32PbComp *PlayerUint32PBComp    `protobuf:"bytes,5,opt,name=uint32_pb_comp,json=uint32PbComp,proto3" json:"uint32_pb_comp,omitempty"`
}

func (x *PlayerDatabase) Reset() {
	*x = PlayerDatabase{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_mysql_database_table_proto_msgTypes[3]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *PlayerDatabase) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*PlayerDatabase) ProtoMessage() {}

func (x *PlayerDatabase) ProtoReflect() protoreflect.Message {
	mi := &file_common_mysql_database_table_proto_msgTypes[3]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use PlayerDatabase.ProtoReflect.Descriptor instead.
func (*PlayerDatabase) Descriptor() ([]byte, []int) {
	return file_common_mysql_database_table_proto_rawDescGZIP(), []int{3}
}

func (x *PlayerDatabase) GetPlayerId() uint64 {
	if x != nil {
		return x.PlayerId
	}
	return 0
}

func (x *PlayerDatabase) GetTransform() *Transform {
	if x != nil {
		return x.Transform
	}
	return nil
}

func (x *PlayerDatabase) GetUint64PbComp() *PlayerUint64PBComp {
	if x != nil {
		return x.Uint64PbComp
	}
	return nil
}

func (x *PlayerDatabase) GetSkillList() *PlayerSkillListPBComp {
	if x != nil {
		return x.SkillList
	}
	return nil
}

func (x *PlayerDatabase) GetUint32PbComp() *PlayerUint32PBComp {
	if x != nil {
		return x.Uint32PbComp
	}
	return nil
}

type PlayerDatabase_1 struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	PlayerId uint64 `protobuf:"varint,1,opt,name=player_id,json=playerId,proto3" json:"player_id,omitempty"`
}

func (x *PlayerDatabase_1) Reset() {
	*x = PlayerDatabase_1{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_mysql_database_table_proto_msgTypes[4]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *PlayerDatabase_1) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*PlayerDatabase_1) ProtoMessage() {}

func (x *PlayerDatabase_1) ProtoReflect() protoreflect.Message {
	mi := &file_common_mysql_database_table_proto_msgTypes[4]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use PlayerDatabase_1.ProtoReflect.Descriptor instead.
func (*PlayerDatabase_1) Descriptor() ([]byte, []int) {
	return file_common_mysql_database_table_proto_rawDescGZIP(), []int{4}
}

func (x *PlayerDatabase_1) GetPlayerId() uint64 {
	if x != nil {
		return x.PlayerId
	}
	return 0
}

var File_common_mysql_database_table_proto protoreflect.FileDescriptor

var file_common_mysql_database_table_proto_rawDesc = []byte{
	0x0a, 0x21, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2f, 0x6d, 0x79, 0x73, 0x71, 0x6c, 0x5f, 0x64,
	0x61, 0x74, 0x61, 0x62, 0x61, 0x73, 0x65, 0x5f, 0x74, 0x61, 0x62, 0x6c, 0x65, 0x2e, 0x70, 0x72,
	0x6f, 0x74, 0x6f, 0x1a, 0x14, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2f, 0x64, 0x62, 0x5f, 0x62,
	0x61, 0x73, 0x65, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x1a, 0x1a, 0x63, 0x6f, 0x6d, 0x6d, 0x6f,
	0x6e, 0x2f, 0x75, 0x73, 0x65, 0x72, 0x5f, 0x61, 0x63, 0x63, 0x6f, 0x75, 0x6e, 0x74, 0x73, 0x2e,
	0x70, 0x72, 0x6f, 0x74, 0x6f, 0x1a, 0x11, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2f, 0x63, 0x6f,
	0x6d, 0x70, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x1a, 0x27, 0x6c, 0x6f, 0x67, 0x69, 0x63, 0x2f,
	0x63, 0x6f, 0x6d, 0x70, 0x6f, 0x6e, 0x65, 0x6e, 0x74, 0x2f, 0x70, 0x6c, 0x61, 0x79, 0x65, 0x72,
	0x5f, 0x73, 0x63, 0x65, 0x6e, 0x65, 0x5f, 0x63, 0x6f, 0x6d, 0x70, 0x2e, 0x70, 0x72, 0x6f, 0x74,
	0x6f, 0x1a, 0x20, 0x6c, 0x6f, 0x67, 0x69, 0x63, 0x2f, 0x63, 0x6f, 0x6d, 0x70, 0x6f, 0x6e, 0x65,
	0x6e, 0x74, 0x2f, 0x61, 0x63, 0x74, 0x6f, 0x72, 0x5f, 0x63, 0x6f, 0x6d, 0x70, 0x2e, 0x70, 0x72,
	0x6f, 0x74, 0x6f, 0x1a, 0x21, 0x6c, 0x6f, 0x67, 0x69, 0x63, 0x2f, 0x63, 0x6f, 0x6d, 0x70, 0x6f,
	0x6e, 0x65, 0x6e, 0x74, 0x2f, 0x70, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x5f, 0x63, 0x6f, 0x6d, 0x70,
	0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x1a, 0x27, 0x6c, 0x6f, 0x67, 0x69, 0x63, 0x2f, 0x63, 0x6f,
	0x6d, 0x70, 0x6f, 0x6e, 0x65, 0x6e, 0x74, 0x2f, 0x70, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x5f, 0x73,
	0x6b, 0x69, 0x6c, 0x6c, 0x5f, 0x63, 0x6f, 0x6d, 0x70, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x22,
	0x93, 0x01, 0x0a, 0x0d, 0x75, 0x73, 0x65, 0x72, 0x5f, 0x61, 0x63, 0x63, 0x6f, 0x75, 0x6e, 0x74,
	0x73, 0x12, 0x18, 0x0a, 0x07, 0x61, 0x63, 0x63, 0x6f, 0x75, 0x6e, 0x74, 0x18, 0x01, 0x20, 0x01,
	0x28, 0x09, 0x52, 0x07, 0x61, 0x63, 0x63, 0x6f, 0x75, 0x6e, 0x74, 0x12, 0x1a, 0x0a, 0x08, 0x70,
	0x61, 0x73, 0x73, 0x77, 0x6f, 0x72, 0x64, 0x18, 0x02, 0x20, 0x01, 0x28, 0x09, 0x52, 0x08, 0x70,
	0x61, 0x73, 0x73, 0x77, 0x6f, 0x72, 0x64, 0x12, 0x3f, 0x0a, 0x0e, 0x73, 0x69, 0x6d, 0x70, 0x6c,
	0x65, 0x5f, 0x70, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x73, 0x18, 0x03, 0x20, 0x01, 0x28, 0x0b, 0x32,
	0x18, 0x2e, 0x41, 0x63, 0x63, 0x6f, 0x75, 0x6e, 0x74, 0x53, 0x69, 0x6d, 0x70, 0x6c, 0x65, 0x50,
	0x6c, 0x61, 0x79, 0x65, 0x72, 0x4c, 0x69, 0x73, 0x74, 0x52, 0x0d, 0x73, 0x69, 0x6d, 0x70, 0x6c,
	0x65, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x73, 0x3a, 0x0b, 0x92, 0xb5, 0x18, 0x07, 0x61, 0x63,
	0x63, 0x6f, 0x75, 0x6e, 0x74, 0x22, 0x3f, 0x0a, 0x16, 0x61, 0x63, 0x63, 0x6f, 0x75, 0x6e, 0x74,
	0x5f, 0x73, 0x68, 0x61, 0x72, 0x65, 0x5f, 0x64, 0x61, 0x74, 0x61, 0x62, 0x61, 0x73, 0x65, 0x12,
	0x18, 0x0a, 0x07, 0x61, 0x63, 0x63, 0x6f, 0x75, 0x6e, 0x74, 0x18, 0x01, 0x20, 0x01, 0x28, 0x09,
	0x52, 0x07, 0x61, 0x63, 0x63, 0x6f, 0x75, 0x6e, 0x74, 0x3a, 0x0b, 0x92, 0xb5, 0x18, 0x07, 0x61,
	0x63, 0x63, 0x6f, 0x75, 0x6e, 0x74, 0x22, 0x8b, 0x01, 0x0a, 0x16, 0x70, 0x6c, 0x61, 0x79, 0x65,
	0x72, 0x5f, 0x63, 0x65, 0x6e, 0x74, 0x72, 0x65, 0x5f, 0x64, 0x61, 0x74, 0x61, 0x62, 0x61, 0x73,
	0x65, 0x12, 0x1b, 0x0a, 0x09, 0x70, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x5f, 0x69, 0x64, 0x18, 0x01,
	0x20, 0x01, 0x28, 0x04, 0x52, 0x08, 0x70, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x49, 0x64, 0x12, 0x38,
	0x0a, 0x0a, 0x73, 0x63, 0x65, 0x6e, 0x65, 0x5f, 0x69, 0x6e, 0x66, 0x6f, 0x18, 0x02, 0x20, 0x01,
	0x28, 0x0b, 0x32, 0x19, 0x2e, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x53, 0x63, 0x65, 0x6e, 0x65,
	0x43, 0x6f, 0x6e, 0x74, 0x65, 0x78, 0x74, 0x50, 0x42, 0x43, 0x6f, 0x6d, 0x70, 0x52, 0x09, 0x73,
	0x63, 0x65, 0x6e, 0x65, 0x49, 0x6e, 0x66, 0x6f, 0x3a, 0x1a, 0x92, 0xb5, 0x18, 0x09, 0x70, 0x6c,
	0x61, 0x79, 0x65, 0x72, 0x5f, 0x69, 0x64, 0xb2, 0xb5, 0x18, 0x09, 0x70, 0x6c, 0x61, 0x79, 0x65,
	0x72, 0x5f, 0x69, 0x64, 0x22, 0xa1, 0x02, 0x0a, 0x0f, 0x70, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x5f,
	0x64, 0x61, 0x74, 0x61, 0x62, 0x61, 0x73, 0x65, 0x12, 0x1b, 0x0a, 0x09, 0x70, 0x6c, 0x61, 0x79,
	0x65, 0x72, 0x5f, 0x69, 0x64, 0x18, 0x01, 0x20, 0x01, 0x28, 0x04, 0x52, 0x08, 0x70, 0x6c, 0x61,
	0x79, 0x65, 0x72, 0x49, 0x64, 0x12, 0x28, 0x0a, 0x09, 0x74, 0x72, 0x61, 0x6e, 0x73, 0x66, 0x6f,
	0x72, 0x6d, 0x18, 0x02, 0x20, 0x01, 0x28, 0x0b, 0x32, 0x0a, 0x2e, 0x54, 0x72, 0x61, 0x6e, 0x73,
	0x66, 0x6f, 0x72, 0x6d, 0x52, 0x09, 0x74, 0x72, 0x61, 0x6e, 0x73, 0x66, 0x6f, 0x72, 0x6d, 0x12,
	0x39, 0x0a, 0x0e, 0x75, 0x69, 0x6e, 0x74, 0x36, 0x34, 0x5f, 0x70, 0x62, 0x5f, 0x63, 0x6f, 0x6d,
	0x70, 0x18, 0x03, 0x20, 0x01, 0x28, 0x0b, 0x32, 0x13, 0x2e, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72,
	0x55, 0x69, 0x6e, 0x74, 0x36, 0x34, 0x50, 0x42, 0x43, 0x6f, 0x6d, 0x70, 0x52, 0x0c, 0x75, 0x69,
	0x6e, 0x74, 0x36, 0x34, 0x50, 0x62, 0x43, 0x6f, 0x6d, 0x70, 0x12, 0x35, 0x0a, 0x0a, 0x73, 0x6b,
	0x69, 0x6c, 0x6c, 0x5f, 0x6c, 0x69, 0x73, 0x74, 0x18, 0x04, 0x20, 0x01, 0x28, 0x0b, 0x32, 0x16,
	0x2e, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x53, 0x6b, 0x69, 0x6c, 0x6c, 0x4c, 0x69, 0x73, 0x74,
	0x50, 0x42, 0x43, 0x6f, 0x6d, 0x70, 0x52, 0x09, 0x73, 0x6b, 0x69, 0x6c, 0x6c, 0x4c, 0x69, 0x73,
	0x74, 0x12, 0x39, 0x0a, 0x0e, 0x75, 0x69, 0x6e, 0x74, 0x33, 0x32, 0x5f, 0x70, 0x62, 0x5f, 0x63,
	0x6f, 0x6d, 0x70, 0x18, 0x05, 0x20, 0x01, 0x28, 0x0b, 0x32, 0x13, 0x2e, 0x50, 0x6c, 0x61, 0x79,
	0x65, 0x72, 0x55, 0x69, 0x6e, 0x74, 0x33, 0x32, 0x50, 0x42, 0x43, 0x6f, 0x6d, 0x70, 0x52, 0x0c,
	0x75, 0x69, 0x6e, 0x74, 0x33, 0x32, 0x50, 0x62, 0x43, 0x6f, 0x6d, 0x70, 0x3a, 0x1a, 0x92, 0xb5,
	0x18, 0x09, 0x70, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x5f, 0x69, 0x64, 0xb2, 0xb5, 0x18, 0x09, 0x70,
	0x6c, 0x61, 0x79, 0x65, 0x72, 0x5f, 0x69, 0x64, 0x22, 0x4c, 0x0a, 0x11, 0x70, 0x6c, 0x61, 0x79,
	0x65, 0x72, 0x5f, 0x64, 0x61, 0x74, 0x61, 0x62, 0x61, 0x73, 0x65, 0x5f, 0x31, 0x12, 0x1b, 0x0a,
	0x09, 0x70, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x5f, 0x69, 0x64, 0x18, 0x01, 0x20, 0x01, 0x28, 0x04,
	0x52, 0x08, 0x70, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x49, 0x64, 0x3a, 0x1a, 0x92, 0xb5, 0x18, 0x09,
	0x70, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x5f, 0x69, 0x64, 0xb2, 0xb5, 0x18, 0x09, 0x70, 0x6c, 0x61,
	0x79, 0x65, 0x72, 0x5f, 0x69, 0x64, 0x42, 0x09, 0x5a, 0x07, 0x70, 0x62, 0x2f, 0x67, 0x61, 0x6d,
	0x65, 0x62, 0x06, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x33,
}

var (
	file_common_mysql_database_table_proto_rawDescOnce sync.Once
	file_common_mysql_database_table_proto_rawDescData = file_common_mysql_database_table_proto_rawDesc
)

func file_common_mysql_database_table_proto_rawDescGZIP() []byte {
	file_common_mysql_database_table_proto_rawDescOnce.Do(func() {
		file_common_mysql_database_table_proto_rawDescData = protoimpl.X.CompressGZIP(file_common_mysql_database_table_proto_rawDescData)
	})
	return file_common_mysql_database_table_proto_rawDescData
}

var file_common_mysql_database_table_proto_msgTypes = make([]protoimpl.MessageInfo, 5)
var file_common_mysql_database_table_proto_goTypes = []any{
	(*UserAccounts)(nil),             // 0: user_accounts
	(*AccountShareDatabase)(nil),     // 1: account_share_database
	(*PlayerCentreDatabase)(nil),     // 2: player_centre_database
	(*PlayerDatabase)(nil),           // 3: player_database
	(*PlayerDatabase_1)(nil),         // 4: player_database_1
	(*AccountSimplePlayerList)(nil),  // 5: AccountSimplePlayerList
	(*PlayerSceneContextPBComp)(nil), // 6: PlayerSceneContextPBComp
	(*Transform)(nil),                // 7: Transform
	(*PlayerUint64PBComp)(nil),       // 8: PlayerUint64PBComp
	(*PlayerSkillListPBComp)(nil),    // 9: PlayerSkillListPBComp
	(*PlayerUint32PBComp)(nil),       // 10: PlayerUint32PBComp
}
var file_common_mysql_database_table_proto_depIdxs = []int32{
	5,  // 0: user_accounts.simple_players:type_name -> AccountSimplePlayerList
	6,  // 1: player_centre_database.scene_info:type_name -> PlayerSceneContextPBComp
	7,  // 2: player_database.transform:type_name -> Transform
	8,  // 3: player_database.uint64_pb_comp:type_name -> PlayerUint64PBComp
	9,  // 4: player_database.skill_list:type_name -> PlayerSkillListPBComp
	10, // 5: player_database.uint32_pb_comp:type_name -> PlayerUint32PBComp
	6,  // [6:6] is the sub-list for method output_type
	6,  // [6:6] is the sub-list for method input_type
	6,  // [6:6] is the sub-list for extension type_name
	6,  // [6:6] is the sub-list for extension extendee
	0,  // [0:6] is the sub-list for field type_name
}

func init() { file_common_mysql_database_table_proto_init() }
func file_common_mysql_database_table_proto_init() {
	if File_common_mysql_database_table_proto != nil {
		return
	}
	file_common_user_accounts_proto_init()
	file_common_comp_proto_init()
	file_logic_component_player_scene_comp_proto_init()
	file_logic_component_actor_comp_proto_init()
	file_logic_component_player_comp_proto_init()
	file_logic_component_player_skill_comp_proto_init()
	if !protoimpl.UnsafeEnabled {
		file_common_mysql_database_table_proto_msgTypes[0].Exporter = func(v any, i int) any {
			switch v := v.(*UserAccounts); i {
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
		file_common_mysql_database_table_proto_msgTypes[1].Exporter = func(v any, i int) any {
			switch v := v.(*AccountShareDatabase); i {
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
		file_common_mysql_database_table_proto_msgTypes[2].Exporter = func(v any, i int) any {
			switch v := v.(*PlayerCentreDatabase); i {
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
		file_common_mysql_database_table_proto_msgTypes[3].Exporter = func(v any, i int) any {
			switch v := v.(*PlayerDatabase); i {
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
		file_common_mysql_database_table_proto_msgTypes[4].Exporter = func(v any, i int) any {
			switch v := v.(*PlayerDatabase_1); i {
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
			RawDescriptor: file_common_mysql_database_table_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   5,
			NumExtensions: 0,
			NumServices:   0,
		},
		GoTypes:           file_common_mysql_database_table_proto_goTypes,
		DependencyIndexes: file_common_mysql_database_table_proto_depIdxs,
		MessageInfos:      file_common_mysql_database_table_proto_msgTypes,
	}.Build()
	File_common_mysql_database_table_proto = out.File
	file_common_mysql_database_table_proto_rawDesc = nil
	file_common_mysql_database_table_proto_goTypes = nil
	file_common_mysql_database_table_proto_depIdxs = nil
}
