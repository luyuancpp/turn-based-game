// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.34.1
// 	protoc        v4.25.1
// source: common_proto/centre_service.proto

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

type CtrlStartGsResponse struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	CentreNodeId uint32 `protobuf:"varint,1,opt,name=centre_node_id,json=centreNodeId,proto3" json:"centre_node_id,omitempty"`
	GateNodeId   uint32 `protobuf:"varint,3,opt,name=gate_node_id,json=gateNodeId,proto3" json:"gate_node_id,omitempty"`
}

func (x *CtrlStartGsResponse) Reset() {
	*x = CtrlStartGsResponse{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_proto_centre_service_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *CtrlStartGsResponse) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*CtrlStartGsResponse) ProtoMessage() {}

func (x *CtrlStartGsResponse) ProtoReflect() protoreflect.Message {
	mi := &file_common_proto_centre_service_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use CtrlStartGsResponse.ProtoReflect.Descriptor instead.
func (*CtrlStartGsResponse) Descriptor() ([]byte, []int) {
	return file_common_proto_centre_service_proto_rawDescGZIP(), []int{0}
}

func (x *CtrlStartGsResponse) GetCentreNodeId() uint32 {
	if x != nil {
		return x.CentreNodeId
	}
	return 0
}

func (x *CtrlStartGsResponse) GetGateNodeId() uint32 {
	if x != nil {
		return x.GateNodeId
	}
	return 0
}

type GateClientMessageRequest struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	RpcClient *IpPort `protobuf:"bytes,1,opt,name=rpc_client,json=rpcClient,proto3" json:"rpc_client,omitempty"`
}

func (x *GateClientMessageRequest) Reset() {
	*x = GateClientMessageRequest{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_proto_centre_service_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *GateClientMessageRequest) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*GateClientMessageRequest) ProtoMessage() {}

func (x *GateClientMessageRequest) ProtoReflect() protoreflect.Message {
	mi := &file_common_proto_centre_service_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use GateClientMessageRequest.ProtoReflect.Descriptor instead.
func (*GateClientMessageRequest) Descriptor() ([]byte, []int) {
	return file_common_proto_centre_service_proto_rawDescGZIP(), []int{1}
}

func (x *GateClientMessageRequest) GetRpcClient() *IpPort {
	if x != nil {
		return x.RpcClient
	}
	return nil
}

type CtrlConnectedGameRequest struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	RpcClient *IpPort `protobuf:"bytes,1,opt,name=rpc_client,json=rpcClient,proto3" json:"rpc_client,omitempty"`
}

func (x *CtrlConnectedGameRequest) Reset() {
	*x = CtrlConnectedGameRequest{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_proto_centre_service_proto_msgTypes[2]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *CtrlConnectedGameRequest) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*CtrlConnectedGameRequest) ProtoMessage() {}

func (x *CtrlConnectedGameRequest) ProtoReflect() protoreflect.Message {
	mi := &file_common_proto_centre_service_proto_msgTypes[2]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use CtrlConnectedGameRequest.ProtoReflect.Descriptor instead.
func (*CtrlConnectedGameRequest) Descriptor() ([]byte, []int) {
	return file_common_proto_centre_service_proto_rawDescGZIP(), []int{2}
}

func (x *CtrlConnectedGameRequest) GetRpcClient() *IpPort {
	if x != nil {
		return x.RpcClient
	}
	return nil
}

type GateSessionDisconnectRequest struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	SessionId uint64 `protobuf:"varint,1,opt,name=session_id,json=sessionId,proto3" json:"session_id,omitempty"`
}

func (x *GateSessionDisconnectRequest) Reset() {
	*x = GateSessionDisconnectRequest{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_proto_centre_service_proto_msgTypes[3]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *GateSessionDisconnectRequest) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*GateSessionDisconnectRequest) ProtoMessage() {}

func (x *GateSessionDisconnectRequest) ProtoReflect() protoreflect.Message {
	mi := &file_common_proto_centre_service_proto_msgTypes[3]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use GateSessionDisconnectRequest.ProtoReflect.Descriptor instead.
func (*GateSessionDisconnectRequest) Descriptor() ([]byte, []int) {
	return file_common_proto_centre_service_proto_rawDescGZIP(), []int{3}
}

func (x *GateSessionDisconnectRequest) GetSessionId() uint64 {
	if x != nil {
		return x.SessionId
	}
	return 0
}

type CtrlLsLeaveGameRequest struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields
}

func (x *CtrlLsLeaveGameRequest) Reset() {
	*x = CtrlLsLeaveGameRequest{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_proto_centre_service_proto_msgTypes[4]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *CtrlLsLeaveGameRequest) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*CtrlLsLeaveGameRequest) ProtoMessage() {}

func (x *CtrlLsLeaveGameRequest) ProtoReflect() protoreflect.Message {
	mi := &file_common_proto_centre_service_proto_msgTypes[4]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use CtrlLsLeaveGameRequest.ProtoReflect.Descriptor instead.
func (*CtrlLsLeaveGameRequest) Descriptor() ([]byte, []int) {
	return file_common_proto_centre_service_proto_rawDescGZIP(), []int{4}
}

type CtrlLsDisconnectRequest struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields
}

func (x *CtrlLsDisconnectRequest) Reset() {
	*x = CtrlLsDisconnectRequest{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_proto_centre_service_proto_msgTypes[5]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *CtrlLsDisconnectRequest) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*CtrlLsDisconnectRequest) ProtoMessage() {}

func (x *CtrlLsDisconnectRequest) ProtoReflect() protoreflect.Message {
	mi := &file_common_proto_centre_service_proto_msgTypes[5]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use CtrlLsDisconnectRequest.ProtoReflect.Descriptor instead.
func (*CtrlLsDisconnectRequest) Descriptor() ([]byte, []int) {
	return file_common_proto_centre_service_proto_rawDescGZIP(), []int{5}
}

type EnterGameNodeSucceedRequest struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	PlayerId   uint64 `protobuf:"varint,1,opt,name=player_id,json=playerId,proto3" json:"player_id,omitempty"`
	GameNodeId uint32 `protobuf:"varint,2,opt,name=game_node_id,json=gameNodeId,proto3" json:"game_node_id,omitempty"`
}

func (x *EnterGameNodeSucceedRequest) Reset() {
	*x = EnterGameNodeSucceedRequest{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_proto_centre_service_proto_msgTypes[6]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *EnterGameNodeSucceedRequest) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*EnterGameNodeSucceedRequest) ProtoMessage() {}

func (x *EnterGameNodeSucceedRequest) ProtoReflect() protoreflect.Message {
	mi := &file_common_proto_centre_service_proto_msgTypes[6]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use EnterGameNodeSucceedRequest.ProtoReflect.Descriptor instead.
func (*EnterGameNodeSucceedRequest) Descriptor() ([]byte, []int) {
	return file_common_proto_centre_service_proto_rawDescGZIP(), []int{6}
}

func (x *EnterGameNodeSucceedRequest) GetPlayerId() uint64 {
	if x != nil {
		return x.PlayerId
	}
	return 0
}

func (x *EnterGameNodeSucceedRequest) GetGameNodeId() uint32 {
	if x != nil {
		return x.GameNodeId
	}
	return 0
}

type EnterGameL2Ctr struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	ClientMsgBody *EnterGameRequest `protobuf:"bytes,1,opt,name=client_msg_body,json=clientMsgBody,proto3" json:"client_msg_body,omitempty"`
	SessionInfo   *SessionInfo      `protobuf:"bytes,2,opt,name=session_info,json=sessionInfo,proto3" json:"session_info,omitempty"`
}

func (x *EnterGameL2Ctr) Reset() {
	*x = EnterGameL2Ctr{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_proto_centre_service_proto_msgTypes[7]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *EnterGameL2Ctr) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*EnterGameL2Ctr) ProtoMessage() {}

func (x *EnterGameL2Ctr) ProtoReflect() protoreflect.Message {
	mi := &file_common_proto_centre_service_proto_msgTypes[7]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use EnterGameL2Ctr.ProtoReflect.Descriptor instead.
func (*EnterGameL2Ctr) Descriptor() ([]byte, []int) {
	return file_common_proto_centre_service_proto_rawDescGZIP(), []int{7}
}

func (x *EnterGameL2Ctr) GetClientMsgBody() *EnterGameRequest {
	if x != nil {
		return x.ClientMsgBody
	}
	return nil
}

func (x *EnterGameL2Ctr) GetSessionInfo() *SessionInfo {
	if x != nil {
		return x.SessionInfo
	}
	return nil
}

var File_common_proto_centre_service_proto protoreflect.FileDescriptor

var file_common_proto_centre_service_proto_rawDesc = []byte{
	0x0a, 0x21, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x5f, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x2f, 0x63,
	0x65, 0x6e, 0x74, 0x72, 0x65, 0x5f, 0x73, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x2e, 0x70, 0x72,
	0x6f, 0x74, 0x6f, 0x1a, 0x19, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x5f, 0x70, 0x72, 0x6f, 0x74,
	0x6f, 0x2f, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x1a, 0x18,
	0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x5f, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x2f, 0x65, 0x6d, 0x70,
	0x74, 0x79, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x1a, 0x1a, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e,
	0x5f, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x2f, 0x73, 0x65, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x2e, 0x70,
	0x72, 0x6f, 0x74, 0x6f, 0x1a, 0x19, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x5f, 0x70, 0x72, 0x6f,
	0x74, 0x6f, 0x2f, 0x63, 0x32, 0x67, 0x61, 0x74, 0x65, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x1a,
	0x1e, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x5f, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x2f, 0x6e, 0x6f,
	0x64, 0x65, 0x5f, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x22,
	0x5d, 0x0a, 0x13, 0x43, 0x74, 0x72, 0x6c, 0x53, 0x74, 0x61, 0x72, 0x74, 0x47, 0x73, 0x52, 0x65,
	0x73, 0x70, 0x6f, 0x6e, 0x73, 0x65, 0x12, 0x24, 0x0a, 0x0e, 0x63, 0x65, 0x6e, 0x74, 0x72, 0x65,
	0x5f, 0x6e, 0x6f, 0x64, 0x65, 0x5f, 0x69, 0x64, 0x18, 0x01, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x0c,
	0x63, 0x65, 0x6e, 0x74, 0x72, 0x65, 0x4e, 0x6f, 0x64, 0x65, 0x49, 0x64, 0x12, 0x20, 0x0a, 0x0c,
	0x67, 0x61, 0x74, 0x65, 0x5f, 0x6e, 0x6f, 0x64, 0x65, 0x5f, 0x69, 0x64, 0x18, 0x03, 0x20, 0x01,
	0x28, 0x0d, 0x52, 0x0a, 0x67, 0x61, 0x74, 0x65, 0x4e, 0x6f, 0x64, 0x65, 0x49, 0x64, 0x22, 0x42,
	0x0a, 0x18, 0x47, 0x61, 0x74, 0x65, 0x43, 0x6c, 0x69, 0x65, 0x6e, 0x74, 0x4d, 0x65, 0x73, 0x73,
	0x61, 0x67, 0x65, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x12, 0x26, 0x0a, 0x0a, 0x72, 0x70,
	0x63, 0x5f, 0x63, 0x6c, 0x69, 0x65, 0x6e, 0x74, 0x18, 0x01, 0x20, 0x01, 0x28, 0x0b, 0x32, 0x07,
	0x2e, 0x49, 0x70, 0x50, 0x6f, 0x72, 0x74, 0x52, 0x09, 0x72, 0x70, 0x63, 0x43, 0x6c, 0x69, 0x65,
	0x6e, 0x74, 0x22, 0x42, 0x0a, 0x18, 0x43, 0x74, 0x72, 0x6c, 0x43, 0x6f, 0x6e, 0x6e, 0x65, 0x63,
	0x74, 0x65, 0x64, 0x47, 0x61, 0x6d, 0x65, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x12, 0x26,
	0x0a, 0x0a, 0x72, 0x70, 0x63, 0x5f, 0x63, 0x6c, 0x69, 0x65, 0x6e, 0x74, 0x18, 0x01, 0x20, 0x01,
	0x28, 0x0b, 0x32, 0x07, 0x2e, 0x49, 0x70, 0x50, 0x6f, 0x72, 0x74, 0x52, 0x09, 0x72, 0x70, 0x63,
	0x43, 0x6c, 0x69, 0x65, 0x6e, 0x74, 0x22, 0x3d, 0x0a, 0x1c, 0x47, 0x61, 0x74, 0x65, 0x53, 0x65,
	0x73, 0x73, 0x69, 0x6f, 0x6e, 0x44, 0x69, 0x73, 0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x52,
	0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x12, 0x1d, 0x0a, 0x0a, 0x73, 0x65, 0x73, 0x73, 0x69, 0x6f,
	0x6e, 0x5f, 0x69, 0x64, 0x18, 0x01, 0x20, 0x01, 0x28, 0x04, 0x52, 0x09, 0x73, 0x65, 0x73, 0x73,
	0x69, 0x6f, 0x6e, 0x49, 0x64, 0x22, 0x18, 0x0a, 0x16, 0x43, 0x74, 0x72, 0x6c, 0x4c, 0x73, 0x4c,
	0x65, 0x61, 0x76, 0x65, 0x47, 0x61, 0x6d, 0x65, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x22,
	0x19, 0x0a, 0x17, 0x43, 0x74, 0x72, 0x6c, 0x4c, 0x73, 0x44, 0x69, 0x73, 0x63, 0x6f, 0x6e, 0x6e,
	0x65, 0x63, 0x74, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x22, 0x5c, 0x0a, 0x1b, 0x45, 0x6e,
	0x74, 0x65, 0x72, 0x47, 0x61, 0x6d, 0x65, 0x4e, 0x6f, 0x64, 0x65, 0x53, 0x75, 0x63, 0x63, 0x65,
	0x65, 0x64, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x12, 0x1b, 0x0a, 0x09, 0x70, 0x6c, 0x61,
	0x79, 0x65, 0x72, 0x5f, 0x69, 0x64, 0x18, 0x01, 0x20, 0x01, 0x28, 0x04, 0x52, 0x08, 0x70, 0x6c,
	0x61, 0x79, 0x65, 0x72, 0x49, 0x64, 0x12, 0x20, 0x0a, 0x0c, 0x67, 0x61, 0x6d, 0x65, 0x5f, 0x6e,
	0x6f, 0x64, 0x65, 0x5f, 0x69, 0x64, 0x18, 0x02, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x0a, 0x67, 0x61,
	0x6d, 0x65, 0x4e, 0x6f, 0x64, 0x65, 0x49, 0x64, 0x22, 0x7c, 0x0a, 0x0e, 0x45, 0x6e, 0x74, 0x65,
	0x72, 0x47, 0x61, 0x6d, 0x65, 0x4c, 0x32, 0x43, 0x74, 0x72, 0x12, 0x39, 0x0a, 0x0f, 0x63, 0x6c,
	0x69, 0x65, 0x6e, 0x74, 0x5f, 0x6d, 0x73, 0x67, 0x5f, 0x62, 0x6f, 0x64, 0x79, 0x18, 0x01, 0x20,
	0x01, 0x28, 0x0b, 0x32, 0x11, 0x2e, 0x45, 0x6e, 0x74, 0x65, 0x72, 0x47, 0x61, 0x6d, 0x65, 0x52,
	0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x52, 0x0d, 0x63, 0x6c, 0x69, 0x65, 0x6e, 0x74, 0x4d, 0x73,
	0x67, 0x42, 0x6f, 0x64, 0x79, 0x12, 0x2f, 0x0a, 0x0c, 0x73, 0x65, 0x73, 0x73, 0x69, 0x6f, 0x6e,
	0x5f, 0x69, 0x6e, 0x66, 0x6f, 0x18, 0x02, 0x20, 0x01, 0x28, 0x0b, 0x32, 0x0c, 0x2e, 0x53, 0x65,
	0x73, 0x73, 0x69, 0x6f, 0x6e, 0x49, 0x6e, 0x66, 0x6f, 0x52, 0x0b, 0x73, 0x65, 0x73, 0x73, 0x69,
	0x6f, 0x6e, 0x49, 0x6e, 0x66, 0x6f, 0x32, 0xf1, 0x05, 0x0a, 0x0d, 0x43, 0x65, 0x6e, 0x74, 0x72,
	0x65, 0x53, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x12, 0x2c, 0x0a, 0x0c, 0x52, 0x65, 0x67, 0x69,
	0x73, 0x74, 0x65, 0x72, 0x47, 0x61, 0x6d, 0x65, 0x12, 0x14, 0x2e, 0x52, 0x65, 0x67, 0x69, 0x73,
	0x74, 0x65, 0x72, 0x47, 0x61, 0x6d, 0x65, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x06,
	0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x12, 0x2c, 0x0a, 0x0c, 0x52, 0x65, 0x67, 0x69, 0x73, 0x74,
	0x65, 0x72, 0x47, 0x61, 0x74, 0x65, 0x12, 0x14, 0x2e, 0x52, 0x65, 0x67, 0x69, 0x73, 0x74, 0x65,
	0x72, 0x47, 0x61, 0x74, 0x65, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x06, 0x2e, 0x45,
	0x6d, 0x70, 0x74, 0x79, 0x12, 0x36, 0x0a, 0x11, 0x47, 0x61, 0x74, 0x65, 0x50, 0x6c, 0x61, 0x79,
	0x65, 0x72, 0x53, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x12, 0x19, 0x2e, 0x47, 0x61, 0x74, 0x65,
	0x43, 0x6c, 0x69, 0x65, 0x6e, 0x74, 0x4d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x52, 0x65, 0x71,
	0x75, 0x65, 0x73, 0x74, 0x1a, 0x06, 0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x12, 0x3e, 0x0a, 0x15,
	0x47, 0x61, 0x74, 0x65, 0x53, 0x65, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x44, 0x69, 0x73, 0x63, 0x6f,
	0x6e, 0x6e, 0x65, 0x63, 0x74, 0x12, 0x1d, 0x2e, 0x47, 0x61, 0x74, 0x65, 0x53, 0x65, 0x73, 0x73,
	0x69, 0x6f, 0x6e, 0x44, 0x69, 0x73, 0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x52, 0x65, 0x71,
	0x75, 0x65, 0x73, 0x74, 0x1a, 0x06, 0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x12, 0x2f, 0x0a, 0x0e,
	0x4c, 0x73, 0x4c, 0x6f, 0x67, 0x69, 0x6e, 0x41, 0x63, 0x63, 0x6f, 0x75, 0x6e, 0x74, 0x12, 0x0d,
	0x2e, 0x4c, 0x6f, 0x67, 0x69, 0x6e, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x0e, 0x2e,
	0x4c, 0x6f, 0x67, 0x69, 0x6e, 0x52, 0x65, 0x73, 0x70, 0x6f, 0x6e, 0x73, 0x65, 0x12, 0x2b, 0x0a,
	0x10, 0x4f, 0x6e, 0x4c, 0x6f, 0x67, 0x69, 0x6e, 0x45, 0x6e, 0x74, 0x65, 0x72, 0x47, 0x61, 0x6d,
	0x65, 0x12, 0x0f, 0x2e, 0x45, 0x6e, 0x74, 0x65, 0x72, 0x47, 0x61, 0x6d, 0x65, 0x4c, 0x32, 0x43,
	0x74, 0x72, 0x1a, 0x06, 0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x12, 0x2e, 0x0a, 0x0b, 0x4c, 0x73,
	0x4c, 0x65, 0x61, 0x76, 0x65, 0x47, 0x61, 0x6d, 0x65, 0x12, 0x17, 0x2e, 0x43, 0x74, 0x72, 0x6c,
	0x4c, 0x73, 0x4c, 0x65, 0x61, 0x76, 0x65, 0x47, 0x61, 0x6d, 0x65, 0x52, 0x65, 0x71, 0x75, 0x65,
	0x73, 0x74, 0x1a, 0x06, 0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x12, 0x30, 0x0a, 0x0c, 0x4c, 0x73,
	0x44, 0x69, 0x73, 0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x12, 0x18, 0x2e, 0x43, 0x74, 0x72,
	0x6c, 0x4c, 0x73, 0x44, 0x69, 0x73, 0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x52, 0x65, 0x71,
	0x75, 0x65, 0x73, 0x74, 0x1a, 0x06, 0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x12, 0x46, 0x0a, 0x0f,
	0x47, 0x73, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x53, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x12,
	0x18, 0x2e, 0x4e, 0x6f, 0x64, 0x65, 0x52, 0x6f, 0x75, 0x74, 0x65, 0x4d, 0x65, 0x73, 0x73, 0x61,
	0x67, 0x65, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x19, 0x2e, 0x4e, 0x6f, 0x64, 0x65,
	0x52, 0x6f, 0x75, 0x74, 0x65, 0x4d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x52, 0x65, 0x73, 0x70,
	0x6f, 0x6e, 0x73, 0x65, 0x12, 0x36, 0x0a, 0x0e, 0x45, 0x6e, 0x74, 0x65, 0x72, 0x47, 0x73, 0x53,
	0x75, 0x63, 0x63, 0x65, 0x65, 0x64, 0x12, 0x1c, 0x2e, 0x45, 0x6e, 0x74, 0x65, 0x72, 0x47, 0x61,
	0x6d, 0x65, 0x4e, 0x6f, 0x64, 0x65, 0x53, 0x75, 0x63, 0x63, 0x65, 0x65, 0x64, 0x52, 0x65, 0x71,
	0x75, 0x65, 0x73, 0x74, 0x1a, 0x06, 0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x12, 0x45, 0x0a, 0x12,
	0x52, 0x6f, 0x75, 0x74, 0x65, 0x4e, 0x6f, 0x64, 0x65, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x4d,
	0x73, 0x67, 0x12, 0x16, 0x2e, 0x52, 0x6f, 0x75, 0x74, 0x65, 0x4d, 0x73, 0x67, 0x53, 0x74, 0x72,
	0x69, 0x6e, 0x67, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x17, 0x2e, 0x52, 0x6f, 0x75,
	0x74, 0x65, 0x4d, 0x73, 0x67, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x52, 0x65, 0x73, 0x70, 0x6f,
	0x6e, 0x73, 0x65, 0x12, 0x53, 0x0a, 0x14, 0x52, 0x6f, 0x75, 0x74, 0x65, 0x50, 0x6c, 0x61, 0x79,
	0x65, 0x72, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x4d, 0x73, 0x67, 0x12, 0x1c, 0x2e, 0x52, 0x6f,
	0x75, 0x74, 0x65, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x4d, 0x73, 0x67, 0x53, 0x74, 0x72, 0x69,
	0x6e, 0x67, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x1d, 0x2e, 0x52, 0x6f, 0x75, 0x74,
	0x65, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x4d, 0x73, 0x67, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67,
	0x52, 0x65, 0x73, 0x70, 0x6f, 0x6e, 0x73, 0x65, 0x12, 0x30, 0x0a, 0x0e, 0x55, 0x6e, 0x52, 0x65,
	0x67, 0x69, 0x73, 0x74, 0x65, 0x72, 0x47, 0x61, 0x6d, 0x65, 0x12, 0x16, 0x2e, 0x55, 0x6e, 0x52,
	0x65, 0x67, 0x69, 0x73, 0x74, 0x65, 0x72, 0x47, 0x61, 0x6d, 0x65, 0x52, 0x65, 0x71, 0x75, 0x65,
	0x73, 0x74, 0x1a, 0x06, 0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x42, 0x0c, 0x5a, 0x07, 0x70, 0x62,
	0x2f, 0x67, 0x61, 0x6d, 0x65, 0x80, 0x01, 0x01, 0x62, 0x06, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x33,
}

var (
	file_common_proto_centre_service_proto_rawDescOnce sync.Once
	file_common_proto_centre_service_proto_rawDescData = file_common_proto_centre_service_proto_rawDesc
)

func file_common_proto_centre_service_proto_rawDescGZIP() []byte {
	file_common_proto_centre_service_proto_rawDescOnce.Do(func() {
		file_common_proto_centre_service_proto_rawDescData = protoimpl.X.CompressGZIP(file_common_proto_centre_service_proto_rawDescData)
	})
	return file_common_proto_centre_service_proto_rawDescData
}

var file_common_proto_centre_service_proto_msgTypes = make([]protoimpl.MessageInfo, 8)
var file_common_proto_centre_service_proto_goTypes = []interface{}{
	(*CtrlStartGsResponse)(nil),          // 0: CtrlStartGsResponse
	(*GateClientMessageRequest)(nil),     // 1: GateClientMessageRequest
	(*CtrlConnectedGameRequest)(nil),     // 2: CtrlConnectedGameRequest
	(*GateSessionDisconnectRequest)(nil), // 3: GateSessionDisconnectRequest
	(*CtrlLsLeaveGameRequest)(nil),       // 4: CtrlLsLeaveGameRequest
	(*CtrlLsDisconnectRequest)(nil),      // 5: CtrlLsDisconnectRequest
	(*EnterGameNodeSucceedRequest)(nil),  // 6: EnterGameNodeSucceedRequest
	(*EnterGameL2Ctr)(nil),               // 7: EnterGameL2Ctr
	(*IpPort)(nil),                       // 8: IpPort
	(*EnterGameRequest)(nil),             // 9: EnterGameRequest
	(*SessionInfo)(nil),                  // 10: SessionInfo
	(*RegisterGameRequest)(nil),          // 11: RegisterGameRequest
	(*RegisterGateRequest)(nil),          // 12: RegisterGateRequest
	(*LoginRequest)(nil),                 // 13: LoginRequest
	(*NodeRouteMessageRequest)(nil),      // 14: NodeRouteMessageRequest
	(*RouteMsgStringRequest)(nil),        // 15: RouteMsgStringRequest
	(*RoutePlayerMsgStringRequest)(nil),  // 16: RoutePlayerMsgStringRequest
	(*UnRegisterGameRequest)(nil),        // 17: UnRegisterGameRequest
	(*Empty)(nil),                        // 18: Empty
	(*LoginResponse)(nil),                // 19: LoginResponse
	(*NodeRouteMessageResponse)(nil),     // 20: NodeRouteMessageResponse
	(*RouteMsgStringResponse)(nil),       // 21: RouteMsgStringResponse
	(*RoutePlayerMsgStringResponse)(nil), // 22: RoutePlayerMsgStringResponse
}
var file_common_proto_centre_service_proto_depIdxs = []int32{
	8,  // 0: GateClientMessageRequest.rpc_client:type_name -> IpPort
	8,  // 1: CtrlConnectedGameRequest.rpc_client:type_name -> IpPort
	9,  // 2: EnterGameL2Ctr.client_msg_body:type_name -> EnterGameRequest
	10, // 3: EnterGameL2Ctr.session_info:type_name -> SessionInfo
	11, // 4: CentreService.RegisterGame:input_type -> RegisterGameRequest
	12, // 5: CentreService.RegisterGate:input_type -> RegisterGateRequest
	1,  // 6: CentreService.GatePlayerService:input_type -> GateClientMessageRequest
	3,  // 7: CentreService.GateSessionDisconnect:input_type -> GateSessionDisconnectRequest
	13, // 8: CentreService.LsLoginAccount:input_type -> LoginRequest
	7,  // 9: CentreService.OnLoginEnterGame:input_type -> EnterGameL2Ctr
	4,  // 10: CentreService.LsLeaveGame:input_type -> CtrlLsLeaveGameRequest
	5,  // 11: CentreService.LsDisconnect:input_type -> CtrlLsDisconnectRequest
	14, // 12: CentreService.GsPlayerService:input_type -> NodeRouteMessageRequest
	6,  // 13: CentreService.EnterGsSucceed:input_type -> EnterGameNodeSucceedRequest
	15, // 14: CentreService.RouteNodeStringMsg:input_type -> RouteMsgStringRequest
	16, // 15: CentreService.RoutePlayerStringMsg:input_type -> RoutePlayerMsgStringRequest
	17, // 16: CentreService.UnRegisterGame:input_type -> UnRegisterGameRequest
	18, // 17: CentreService.RegisterGame:output_type -> Empty
	18, // 18: CentreService.RegisterGate:output_type -> Empty
	18, // 19: CentreService.GatePlayerService:output_type -> Empty
	18, // 20: CentreService.GateSessionDisconnect:output_type -> Empty
	19, // 21: CentreService.LsLoginAccount:output_type -> LoginResponse
	18, // 22: CentreService.OnLoginEnterGame:output_type -> Empty
	18, // 23: CentreService.LsLeaveGame:output_type -> Empty
	18, // 24: CentreService.LsDisconnect:output_type -> Empty
	20, // 25: CentreService.GsPlayerService:output_type -> NodeRouteMessageResponse
	18, // 26: CentreService.EnterGsSucceed:output_type -> Empty
	21, // 27: CentreService.RouteNodeStringMsg:output_type -> RouteMsgStringResponse
	22, // 28: CentreService.RoutePlayerStringMsg:output_type -> RoutePlayerMsgStringResponse
	18, // 29: CentreService.UnRegisterGame:output_type -> Empty
	17, // [17:30] is the sub-list for method output_type
	4,  // [4:17] is the sub-list for method input_type
	4,  // [4:4] is the sub-list for extension type_name
	4,  // [4:4] is the sub-list for extension extendee
	0,  // [0:4] is the sub-list for field type_name
}

func init() { file_common_proto_centre_service_proto_init() }
func file_common_proto_centre_service_proto_init() {
	if File_common_proto_centre_service_proto != nil {
		return
	}
	file_common_proto_common_proto_init()
	file_common_proto_empty_proto_init()
	file_common_proto_session_proto_init()
	file_common_proto_c2gate_proto_init()
	file_common_proto_node_common_proto_init()
	if !protoimpl.UnsafeEnabled {
		file_common_proto_centre_service_proto_msgTypes[0].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*CtrlStartGsResponse); i {
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
		file_common_proto_centre_service_proto_msgTypes[1].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*GateClientMessageRequest); i {
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
		file_common_proto_centre_service_proto_msgTypes[2].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*CtrlConnectedGameRequest); i {
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
		file_common_proto_centre_service_proto_msgTypes[3].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*GateSessionDisconnectRequest); i {
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
		file_common_proto_centre_service_proto_msgTypes[4].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*CtrlLsLeaveGameRequest); i {
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
		file_common_proto_centre_service_proto_msgTypes[5].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*CtrlLsDisconnectRequest); i {
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
		file_common_proto_centre_service_proto_msgTypes[6].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*EnterGameNodeSucceedRequest); i {
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
		file_common_proto_centre_service_proto_msgTypes[7].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*EnterGameL2Ctr); i {
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
			RawDescriptor: file_common_proto_centre_service_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   8,
			NumExtensions: 0,
			NumServices:   1,
		},
		GoTypes:           file_common_proto_centre_service_proto_goTypes,
		DependencyIndexes: file_common_proto_centre_service_proto_depIdxs,
		MessageInfos:      file_common_proto_centre_service_proto_msgTypes,
	}.Build()
	File_common_proto_centre_service_proto = out.File
	file_common_proto_centre_service_proto_rawDesc = nil
	file_common_proto_centre_service_proto_goTypes = nil
	file_common_proto_centre_service_proto_depIdxs = nil
}
