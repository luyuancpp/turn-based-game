// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.34.1
// 	protoc        v4.25.1
// source: client_player_proto/common_client_player.proto

package game

import (
	protoreflect "google.golang.org/protobuf/reflect/protoreflect"
	protoimpl "google.golang.org/protobuf/runtime/protoimpl"
	reflect "reflect"
)

const (
	// Verify that this generated code is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(20 - protoimpl.MinVersion)
	// Verify that runtime/protoimpl is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(protoimpl.MaxVersion - 20)
)

var File_client_player_proto_common_client_player_proto protoreflect.FileDescriptor

var file_client_player_proto_common_client_player_proto_rawDesc = []byte{
	0x0a, 0x2e, 0x63, 0x6c, 0x69, 0x65, 0x6e, 0x74, 0x5f, 0x70, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x5f,
	0x70, 0x72, 0x6f, 0x74, 0x6f, 0x2f, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x5f, 0x63, 0x6c, 0x69,
	0x65, 0x6e, 0x74, 0x5f, 0x70, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f,
	0x1a, 0x16, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x5f, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x2f, 0x74,
	0x69, 0x70, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x1a, 0x19, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e,
	0x5f, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x2f, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2e, 0x70, 0x72,
	0x6f, 0x74, 0x6f, 0x32, 0x57, 0x0a, 0x19, 0x43, 0x6c, 0x69, 0x65, 0x6e, 0x74, 0x50, 0x6c, 0x61,
	0x79, 0x65, 0x72, 0x43, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x53, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65,
	0x12, 0x1e, 0x0a, 0x0a, 0x50, 0x75, 0x73, 0x68, 0x54, 0x69, 0x70, 0x53, 0x32, 0x43, 0x12, 0x07,
	0x2e, 0x54, 0x69, 0x70, 0x53, 0x32, 0x43, 0x1a, 0x07, 0x2e, 0x54, 0x69, 0x70, 0x53, 0x32, 0x43,
	0x12, 0x1a, 0x0a, 0x06, 0x42, 0x65, 0x4b, 0x69, 0x63, 0x6b, 0x12, 0x07, 0x2e, 0x54, 0x69, 0x70,
	0x53, 0x32, 0x43, 0x1a, 0x07, 0x2e, 0x54, 0x69, 0x70, 0x53, 0x32, 0x43, 0x42, 0x0c, 0x5a, 0x07,
	0x70, 0x62, 0x2f, 0x67, 0x61, 0x6d, 0x65, 0x80, 0x01, 0x01, 0x62, 0x06, 0x70, 0x72, 0x6f, 0x74,
	0x6f, 0x33,
}

var file_client_player_proto_common_client_player_proto_goTypes = []interface{}{
	(*TipS2C)(nil), // 0: TipS2C
}
var file_client_player_proto_common_client_player_proto_depIdxs = []int32{
	0, // 0: ClientPlayerCommonService.PushTipS2C:input_type -> TipS2C
	0, // 1: ClientPlayerCommonService.BeKick:input_type -> TipS2C
	0, // 2: ClientPlayerCommonService.PushTipS2C:output_type -> TipS2C
	0, // 3: ClientPlayerCommonService.BeKick:output_type -> TipS2C
	2, // [2:4] is the sub-list for method output_type
	0, // [0:2] is the sub-list for method input_type
	0, // [0:0] is the sub-list for extension type_name
	0, // [0:0] is the sub-list for extension extendee
	0, // [0:0] is the sub-list for field type_name
}

func init() { file_client_player_proto_common_client_player_proto_init() }
func file_client_player_proto_common_client_player_proto_init() {
	if File_client_player_proto_common_client_player_proto != nil {
		return
	}
	file_common_proto_tip_proto_init()
	file_common_proto_common_proto_init()
	type x struct{}
	out := protoimpl.TypeBuilder{
		File: protoimpl.DescBuilder{
			GoPackagePath: reflect.TypeOf(x{}).PkgPath(),
			RawDescriptor: file_client_player_proto_common_client_player_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   0,
			NumExtensions: 0,
			NumServices:   1,
		},
		GoTypes:           file_client_player_proto_common_client_player_proto_goTypes,
		DependencyIndexes: file_client_player_proto_common_client_player_proto_depIdxs,
	}.Build()
	File_client_player_proto_common_client_player_proto = out.File
	file_client_player_proto_common_client_player_proto_rawDesc = nil
	file_client_player_proto_common_client_player_proto_goTypes = nil
	file_client_player_proto_common_client_player_proto_depIdxs = nil
}
