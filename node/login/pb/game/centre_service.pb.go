// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.34.2
// 	protoc        v5.26.1
// source: common/centre_service.proto

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

type GateClientMessageRequest struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	RpcClient *IpPort `protobuf:"bytes,1,opt,name=rpc_client,json=rpcClient,proto3" json:"rpc_client,omitempty"`
}

func (x *GateClientMessageRequest) Reset() {
	*x = GateClientMessageRequest{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_centre_service_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *GateClientMessageRequest) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*GateClientMessageRequest) ProtoMessage() {}

func (x *GateClientMessageRequest) ProtoReflect() protoreflect.Message {
	mi := &file_common_centre_service_proto_msgTypes[0]
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
	return file_common_centre_service_proto_rawDescGZIP(), []int{0}
}

func (x *GateClientMessageRequest) GetRpcClient() *IpPort {
	if x != nil {
		return x.RpcClient
	}
	return nil
}

type LoginNodeLeaveGameRequest struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields
}

func (x *LoginNodeLeaveGameRequest) Reset() {
	*x = LoginNodeLeaveGameRequest{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_centre_service_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *LoginNodeLeaveGameRequest) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*LoginNodeLeaveGameRequest) ProtoMessage() {}

func (x *LoginNodeLeaveGameRequest) ProtoReflect() protoreflect.Message {
	mi := &file_common_centre_service_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use LoginNodeLeaveGameRequest.ProtoReflect.Descriptor instead.
func (*LoginNodeLeaveGameRequest) Descriptor() ([]byte, []int) {
	return file_common_centre_service_proto_rawDescGZIP(), []int{1}
}

type EnterGameNodeSuccessRequest struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	PlayerId   uint64 `protobuf:"varint,1,opt,name=player_id,json=playerId,proto3" json:"player_id,omitempty"`
	GameNodeId uint32 `protobuf:"varint,2,opt,name=game_node_id,json=gameNodeId,proto3" json:"game_node_id,omitempty"`
}

func (x *EnterGameNodeSuccessRequest) Reset() {
	*x = EnterGameNodeSuccessRequest{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_centre_service_proto_msgTypes[2]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *EnterGameNodeSuccessRequest) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*EnterGameNodeSuccessRequest) ProtoMessage() {}

func (x *EnterGameNodeSuccessRequest) ProtoReflect() protoreflect.Message {
	mi := &file_common_centre_service_proto_msgTypes[2]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use EnterGameNodeSuccessRequest.ProtoReflect.Descriptor instead.
func (*EnterGameNodeSuccessRequest) Descriptor() ([]byte, []int) {
	return file_common_centre_service_proto_rawDescGZIP(), []int{2}
}

func (x *EnterGameNodeSuccessRequest) GetPlayerId() uint64 {
	if x != nil {
		return x.PlayerId
	}
	return 0
}

func (x *EnterGameNodeSuccessRequest) GetGameNodeId() uint32 {
	if x != nil {
		return x.GameNodeId
	}
	return 0
}

type CentrePlayerGameNodeEntryRequest struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	ClientMsgBody *EnterGameRequest `protobuf:"bytes,1,opt,name=client_msg_body,json=clientMsgBody,proto3" json:"client_msg_body,omitempty"`
	SessionInfo   *SessionInfo      `protobuf:"bytes,2,opt,name=session_info,json=sessionInfo,proto3" json:"session_info,omitempty"`
}

func (x *CentrePlayerGameNodeEntryRequest) Reset() {
	*x = CentrePlayerGameNodeEntryRequest{}
	if protoimpl.UnsafeEnabled {
		mi := &file_common_centre_service_proto_msgTypes[3]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *CentrePlayerGameNodeEntryRequest) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*CentrePlayerGameNodeEntryRequest) ProtoMessage() {}

func (x *CentrePlayerGameNodeEntryRequest) ProtoReflect() protoreflect.Message {
	mi := &file_common_centre_service_proto_msgTypes[3]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use CentrePlayerGameNodeEntryRequest.ProtoReflect.Descriptor instead.
func (*CentrePlayerGameNodeEntryRequest) Descriptor() ([]byte, []int) {
	return file_common_centre_service_proto_rawDescGZIP(), []int{3}
}

func (x *CentrePlayerGameNodeEntryRequest) GetClientMsgBody() *EnterGameRequest {
	if x != nil {
		return x.ClientMsgBody
	}
	return nil
}

func (x *CentrePlayerGameNodeEntryRequest) GetSessionInfo() *SessionInfo {
	if x != nil {
		return x.SessionInfo
	}
	return nil
}

var File_common_centre_service_proto protoreflect.FileDescriptor

var file_common_centre_service_proto_rawDesc = []byte{
	0x0a, 0x1b, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2f, 0x63, 0x65, 0x6e, 0x74, 0x72, 0x65, 0x5f,
	0x73, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x1a, 0x13, 0x63,
	0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2f, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2e, 0x70, 0x72, 0x6f,
	0x74, 0x6f, 0x1a, 0x12, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2f, 0x65, 0x6d, 0x70, 0x74, 0x79,
	0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x1a, 0x14, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2f, 0x73,
	0x65, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x1a, 0x13, 0x63, 0x6f,
	0x6d, 0x6d, 0x6f, 0x6e, 0x2f, 0x63, 0x32, 0x67, 0x61, 0x74, 0x65, 0x2e, 0x70, 0x72, 0x6f, 0x74,
	0x6f, 0x1a, 0x18, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2f, 0x6e, 0x6f, 0x64, 0x65, 0x5f, 0x63,
	0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x22, 0x42, 0x0a, 0x18, 0x47,
	0x61, 0x74, 0x65, 0x43, 0x6c, 0x69, 0x65, 0x6e, 0x74, 0x4d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65,
	0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x12, 0x26, 0x0a, 0x0a, 0x72, 0x70, 0x63, 0x5f, 0x63,
	0x6c, 0x69, 0x65, 0x6e, 0x74, 0x18, 0x01, 0x20, 0x01, 0x28, 0x0b, 0x32, 0x07, 0x2e, 0x49, 0x70,
	0x50, 0x6f, 0x72, 0x74, 0x52, 0x09, 0x72, 0x70, 0x63, 0x43, 0x6c, 0x69, 0x65, 0x6e, 0x74, 0x22,
	0x1b, 0x0a, 0x19, 0x4c, 0x6f, 0x67, 0x69, 0x6e, 0x4e, 0x6f, 0x64, 0x65, 0x4c, 0x65, 0x61, 0x76,
	0x65, 0x47, 0x61, 0x6d, 0x65, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x22, 0x5c, 0x0a, 0x1b,
	0x45, 0x6e, 0x74, 0x65, 0x72, 0x47, 0x61, 0x6d, 0x65, 0x4e, 0x6f, 0x64, 0x65, 0x53, 0x75, 0x63,
	0x63, 0x65, 0x73, 0x73, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x12, 0x1b, 0x0a, 0x09, 0x70,
	0x6c, 0x61, 0x79, 0x65, 0x72, 0x5f, 0x69, 0x64, 0x18, 0x01, 0x20, 0x01, 0x28, 0x04, 0x52, 0x08,
	0x70, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x49, 0x64, 0x12, 0x20, 0x0a, 0x0c, 0x67, 0x61, 0x6d, 0x65,
	0x5f, 0x6e, 0x6f, 0x64, 0x65, 0x5f, 0x69, 0x64, 0x18, 0x02, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x0a,
	0x67, 0x61, 0x6d, 0x65, 0x4e, 0x6f, 0x64, 0x65, 0x49, 0x64, 0x22, 0x8e, 0x01, 0x0a, 0x20, 0x43,
	0x65, 0x6e, 0x74, 0x72, 0x65, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x47, 0x61, 0x6d, 0x65, 0x4e,
	0x6f, 0x64, 0x65, 0x45, 0x6e, 0x74, 0x72, 0x79, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x12,
	0x39, 0x0a, 0x0f, 0x63, 0x6c, 0x69, 0x65, 0x6e, 0x74, 0x5f, 0x6d, 0x73, 0x67, 0x5f, 0x62, 0x6f,
	0x64, 0x79, 0x18, 0x01, 0x20, 0x01, 0x28, 0x0b, 0x32, 0x11, 0x2e, 0x45, 0x6e, 0x74, 0x65, 0x72,
	0x47, 0x61, 0x6d, 0x65, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x52, 0x0d, 0x63, 0x6c, 0x69,
	0x65, 0x6e, 0x74, 0x4d, 0x73, 0x67, 0x42, 0x6f, 0x64, 0x79, 0x12, 0x2f, 0x0a, 0x0c, 0x73, 0x65,
	0x73, 0x73, 0x69, 0x6f, 0x6e, 0x5f, 0x69, 0x6e, 0x66, 0x6f, 0x18, 0x02, 0x20, 0x01, 0x28, 0x0b,
	0x32, 0x0c, 0x2e, 0x53, 0x65, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x49, 0x6e, 0x66, 0x6f, 0x52, 0x0b,
	0x73, 0x65, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x49, 0x6e, 0x66, 0x6f, 0x32, 0x92, 0x06, 0x0a, 0x0d,
	0x43, 0x65, 0x6e, 0x74, 0x72, 0x65, 0x53, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x12, 0x2c, 0x0a,
	0x0c, 0x52, 0x65, 0x67, 0x69, 0x73, 0x74, 0x65, 0x72, 0x47, 0x61, 0x6d, 0x65, 0x12, 0x14, 0x2e,
	0x52, 0x65, 0x67, 0x69, 0x73, 0x74, 0x65, 0x72, 0x47, 0x61, 0x6d, 0x65, 0x52, 0x65, 0x71, 0x75,
	0x65, 0x73, 0x74, 0x1a, 0x06, 0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x12, 0x2c, 0x0a, 0x0c, 0x52,
	0x65, 0x67, 0x69, 0x73, 0x74, 0x65, 0x72, 0x47, 0x61, 0x74, 0x65, 0x12, 0x14, 0x2e, 0x52, 0x65,
	0x67, 0x69, 0x73, 0x74, 0x65, 0x72, 0x47, 0x61, 0x74, 0x65, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73,
	0x74, 0x1a, 0x06, 0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x12, 0x36, 0x0a, 0x11, 0x47, 0x61, 0x74,
	0x65, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x53, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x12, 0x19,
	0x2e, 0x47, 0x61, 0x74, 0x65, 0x43, 0x6c, 0x69, 0x65, 0x6e, 0x74, 0x4d, 0x65, 0x73, 0x73, 0x61,
	0x67, 0x65, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x06, 0x2e, 0x45, 0x6d, 0x70, 0x74,
	0x79, 0x12, 0x3e, 0x0a, 0x15, 0x47, 0x61, 0x74, 0x65, 0x53, 0x65, 0x73, 0x73, 0x69, 0x6f, 0x6e,
	0x44, 0x69, 0x73, 0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x12, 0x1d, 0x2e, 0x47, 0x61, 0x74,
	0x65, 0x53, 0x65, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x44, 0x69, 0x73, 0x63, 0x6f, 0x6e, 0x6e, 0x65,
	0x63, 0x74, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x06, 0x2e, 0x45, 0x6d, 0x70, 0x74,
	0x79, 0x12, 0x2f, 0x0a, 0x0e, 0x4c, 0x73, 0x4c, 0x6f, 0x67, 0x69, 0x6e, 0x41, 0x63, 0x63, 0x6f,
	0x75, 0x6e, 0x74, 0x12, 0x0d, 0x2e, 0x4c, 0x6f, 0x67, 0x69, 0x6e, 0x52, 0x65, 0x71, 0x75, 0x65,
	0x73, 0x74, 0x1a, 0x0e, 0x2e, 0x4c, 0x6f, 0x67, 0x69, 0x6e, 0x52, 0x65, 0x73, 0x70, 0x6f, 0x6e,
	0x73, 0x65, 0x12, 0x3d, 0x0a, 0x10, 0x4f, 0x6e, 0x4c, 0x6f, 0x67, 0x69, 0x6e, 0x45, 0x6e, 0x74,
	0x65, 0x72, 0x47, 0x61, 0x6d, 0x65, 0x12, 0x21, 0x2e, 0x43, 0x65, 0x6e, 0x74, 0x72, 0x65, 0x50,
	0x6c, 0x61, 0x79, 0x65, 0x72, 0x47, 0x61, 0x6d, 0x65, 0x4e, 0x6f, 0x64, 0x65, 0x45, 0x6e, 0x74,
	0x72, 0x79, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x06, 0x2e, 0x45, 0x6d, 0x70, 0x74,
	0x79, 0x12, 0x38, 0x0a, 0x12, 0x4c, 0x6f, 0x67, 0x69, 0x6e, 0x4e, 0x6f, 0x64, 0x65, 0x4c, 0x65,
	0x61, 0x76, 0x65, 0x47, 0x61, 0x6d, 0x65, 0x12, 0x1a, 0x2e, 0x4c, 0x6f, 0x67, 0x69, 0x6e, 0x4e,
	0x6f, 0x64, 0x65, 0x4c, 0x65, 0x61, 0x76, 0x65, 0x47, 0x61, 0x6d, 0x65, 0x52, 0x65, 0x71, 0x75,
	0x65, 0x73, 0x74, 0x1a, 0x06, 0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x12, 0x35, 0x0a, 0x0c, 0x4c,
	0x73, 0x44, 0x69, 0x73, 0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x12, 0x1d, 0x2e, 0x47, 0x61,
	0x74, 0x65, 0x53, 0x65, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x44, 0x69, 0x73, 0x63, 0x6f, 0x6e, 0x6e,
	0x65, 0x63, 0x74, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x06, 0x2e, 0x45, 0x6d, 0x70,
	0x74, 0x79, 0x12, 0x46, 0x0a, 0x0f, 0x47, 0x73, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x53, 0x65,
	0x72, 0x76, 0x69, 0x63, 0x65, 0x12, 0x18, 0x2e, 0x4e, 0x6f, 0x64, 0x65, 0x52, 0x6f, 0x75, 0x74,
	0x65, 0x4d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a,
	0x19, 0x2e, 0x4e, 0x6f, 0x64, 0x65, 0x52, 0x6f, 0x75, 0x74, 0x65, 0x4d, 0x65, 0x73, 0x73, 0x61,
	0x67, 0x65, 0x52, 0x65, 0x73, 0x70, 0x6f, 0x6e, 0x73, 0x65, 0x12, 0x36, 0x0a, 0x0e, 0x45, 0x6e,
	0x74, 0x65, 0x72, 0x47, 0x73, 0x53, 0x75, 0x63, 0x63, 0x65, 0x65, 0x64, 0x12, 0x1c, 0x2e, 0x45,
	0x6e, 0x74, 0x65, 0x72, 0x47, 0x61, 0x6d, 0x65, 0x4e, 0x6f, 0x64, 0x65, 0x53, 0x75, 0x63, 0x63,
	0x65, 0x73, 0x73, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x06, 0x2e, 0x45, 0x6d, 0x70,
	0x74, 0x79, 0x12, 0x45, 0x0a, 0x12, 0x52, 0x6f, 0x75, 0x74, 0x65, 0x4e, 0x6f, 0x64, 0x65, 0x53,
	0x74, 0x72, 0x69, 0x6e, 0x67, 0x4d, 0x73, 0x67, 0x12, 0x16, 0x2e, 0x52, 0x6f, 0x75, 0x74, 0x65,
	0x4d, 0x73, 0x67, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74,
	0x1a, 0x17, 0x2e, 0x52, 0x6f, 0x75, 0x74, 0x65, 0x4d, 0x73, 0x67, 0x53, 0x74, 0x72, 0x69, 0x6e,
	0x67, 0x52, 0x65, 0x73, 0x70, 0x6f, 0x6e, 0x73, 0x65, 0x12, 0x53, 0x0a, 0x14, 0x52, 0x6f, 0x75,
	0x74, 0x65, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x4d, 0x73,
	0x67, 0x12, 0x1c, 0x2e, 0x52, 0x6f, 0x75, 0x74, 0x65, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x4d,
	0x73, 0x67, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a,
	0x1d, 0x2e, 0x52, 0x6f, 0x75, 0x74, 0x65, 0x50, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x4d, 0x73, 0x67,
	0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x52, 0x65, 0x73, 0x70, 0x6f, 0x6e, 0x73, 0x65, 0x12, 0x30,
	0x0a, 0x0e, 0x55, 0x6e, 0x52, 0x65, 0x67, 0x69, 0x73, 0x74, 0x65, 0x72, 0x47, 0x61, 0x6d, 0x65,
	0x12, 0x16, 0x2e, 0x55, 0x6e, 0x52, 0x65, 0x67, 0x69, 0x73, 0x74, 0x65, 0x72, 0x47, 0x61, 0x6d,
	0x65, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x06, 0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79,
	0x42, 0x0c, 0x5a, 0x07, 0x70, 0x62, 0x2f, 0x67, 0x61, 0x6d, 0x65, 0x80, 0x01, 0x01, 0x62, 0x06,
	0x70, 0x72, 0x6f, 0x74, 0x6f, 0x33,
}

var (
	file_common_centre_service_proto_rawDescOnce sync.Once
	file_common_centre_service_proto_rawDescData = file_common_centre_service_proto_rawDesc
)

func file_common_centre_service_proto_rawDescGZIP() []byte {
	file_common_centre_service_proto_rawDescOnce.Do(func() {
		file_common_centre_service_proto_rawDescData = protoimpl.X.CompressGZIP(file_common_centre_service_proto_rawDescData)
	})
	return file_common_centre_service_proto_rawDescData
}

var file_common_centre_service_proto_msgTypes = make([]protoimpl.MessageInfo, 4)
var file_common_centre_service_proto_goTypes = []any{
	(*GateClientMessageRequest)(nil),         // 0: GateClientMessageRequest
	(*LoginNodeLeaveGameRequest)(nil),        // 1: LoginNodeLeaveGameRequest
	(*EnterGameNodeSuccessRequest)(nil),      // 2: EnterGameNodeSuccessRequest
	(*CentrePlayerGameNodeEntryRequest)(nil), // 3: CentrePlayerGameNodeEntryRequest
	(*IpPort)(nil),                           // 4: IpPort
	(*EnterGameRequest)(nil),                 // 5: EnterGameRequest
	(*SessionInfo)(nil),                      // 6: SessionInfo
	(*RegisterGameRequest)(nil),              // 7: RegisterGameRequest
	(*RegisterGateRequest)(nil),              // 8: RegisterGateRequest
	(*GateSessionDisconnectRequest)(nil),     // 9: GateSessionDisconnectRequest
	(*LoginRequest)(nil),                     // 10: LoginRequest
	(*NodeRouteMessageRequest)(nil),          // 11: NodeRouteMessageRequest
	(*RouteMsgStringRequest)(nil),            // 12: RouteMsgStringRequest
	(*RoutePlayerMsgStringRequest)(nil),      // 13: RoutePlayerMsgStringRequest
	(*UnRegisterGameRequest)(nil),            // 14: UnRegisterGameRequest
	(*Empty)(nil),                            // 15: Empty
	(*LoginResponse)(nil),                    // 16: LoginResponse
	(*NodeRouteMessageResponse)(nil),         // 17: NodeRouteMessageResponse
	(*RouteMsgStringResponse)(nil),           // 18: RouteMsgStringResponse
	(*RoutePlayerMsgStringResponse)(nil),     // 19: RoutePlayerMsgStringResponse
}
var file_common_centre_service_proto_depIdxs = []int32{
	4,  // 0: GateClientMessageRequest.rpc_client:type_name -> IpPort
	5,  // 1: CentrePlayerGameNodeEntryRequest.client_msg_body:type_name -> EnterGameRequest
	6,  // 2: CentrePlayerGameNodeEntryRequest.session_info:type_name -> SessionInfo
	7,  // 3: CentreService.RegisterGame:input_type -> RegisterGameRequest
	8,  // 4: CentreService.RegisterGate:input_type -> RegisterGateRequest
	0,  // 5: CentreService.GatePlayerService:input_type -> GateClientMessageRequest
	9,  // 6: CentreService.GateSessionDisconnect:input_type -> GateSessionDisconnectRequest
	10, // 7: CentreService.LsLoginAccount:input_type -> LoginRequest
	3,  // 8: CentreService.OnLoginEnterGame:input_type -> CentrePlayerGameNodeEntryRequest
	1,  // 9: CentreService.LoginNodeLeaveGame:input_type -> LoginNodeLeaveGameRequest
	9,  // 10: CentreService.LsDisconnect:input_type -> GateSessionDisconnectRequest
	11, // 11: CentreService.GsPlayerService:input_type -> NodeRouteMessageRequest
	2,  // 12: CentreService.EnterGsSucceed:input_type -> EnterGameNodeSuccessRequest
	12, // 13: CentreService.RouteNodeStringMsg:input_type -> RouteMsgStringRequest
	13, // 14: CentreService.RoutePlayerStringMsg:input_type -> RoutePlayerMsgStringRequest
	14, // 15: CentreService.UnRegisterGame:input_type -> UnRegisterGameRequest
	15, // 16: CentreService.RegisterGame:output_type -> Empty
	15, // 17: CentreService.RegisterGate:output_type -> Empty
	15, // 18: CentreService.GatePlayerService:output_type -> Empty
	15, // 19: CentreService.GateSessionDisconnect:output_type -> Empty
	16, // 20: CentreService.LsLoginAccount:output_type -> LoginResponse
	15, // 21: CentreService.OnLoginEnterGame:output_type -> Empty
	15, // 22: CentreService.LoginNodeLeaveGame:output_type -> Empty
	15, // 23: CentreService.LsDisconnect:output_type -> Empty
	17, // 24: CentreService.GsPlayerService:output_type -> NodeRouteMessageResponse
	15, // 25: CentreService.EnterGsSucceed:output_type -> Empty
	18, // 26: CentreService.RouteNodeStringMsg:output_type -> RouteMsgStringResponse
	19, // 27: CentreService.RoutePlayerStringMsg:output_type -> RoutePlayerMsgStringResponse
	15, // 28: CentreService.UnRegisterGame:output_type -> Empty
	16, // [16:29] is the sub-list for method output_type
	3,  // [3:16] is the sub-list for method input_type
	3,  // [3:3] is the sub-list for extension type_name
	3,  // [3:3] is the sub-list for extension extendee
	0,  // [0:3] is the sub-list for field type_name
}

func init() { file_common_centre_service_proto_init() }
func file_common_centre_service_proto_init() {
	if File_common_centre_service_proto != nil {
		return
	}
	file_common_common_proto_init()
	file_common_empty_proto_init()
	file_common_session_proto_init()
	file_common_c2gate_proto_init()
	file_common_node_common_proto_init()
	if !protoimpl.UnsafeEnabled {
		file_common_centre_service_proto_msgTypes[0].Exporter = func(v any, i int) any {
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
		file_common_centre_service_proto_msgTypes[1].Exporter = func(v any, i int) any {
			switch v := v.(*LoginNodeLeaveGameRequest); i {
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
		file_common_centre_service_proto_msgTypes[2].Exporter = func(v any, i int) any {
			switch v := v.(*EnterGameNodeSuccessRequest); i {
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
		file_common_centre_service_proto_msgTypes[3].Exporter = func(v any, i int) any {
			switch v := v.(*CentrePlayerGameNodeEntryRequest); i {
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
			RawDescriptor: file_common_centre_service_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   4,
			NumExtensions: 0,
			NumServices:   1,
		},
		GoTypes:           file_common_centre_service_proto_goTypes,
		DependencyIndexes: file_common_centre_service_proto_depIdxs,
		MessageInfos:      file_common_centre_service_proto_msgTypes,
	}.Build()
	File_common_centre_service_proto = out.File
	file_common_centre_service_proto_rawDesc = nil
	file_common_centre_service_proto_goTypes = nil
	file_common_centre_service_proto_depIdxs = nil
}
