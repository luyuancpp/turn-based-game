// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.34.1
// 	protoc        v4.25.1
// source: logic_proto/centre_team.proto

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

var File_logic_proto_centre_team_proto protoreflect.FileDescriptor

var file_logic_proto_centre_team_proto_rawDesc = []byte{
	0x0a, 0x1d, 0x6c, 0x6f, 0x67, 0x69, 0x63, 0x5f, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x2f, 0x63, 0x65,
	0x6e, 0x74, 0x72, 0x65, 0x5f, 0x74, 0x65, 0x61, 0x6d, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x1a,
	0x1f, 0x63, 0x6f, 0x6d, 0x70, 0x6f, 0x6e, 0x65, 0x6e, 0x74, 0x5f, 0x70, 0x72, 0x6f, 0x74, 0x6f,
	0x2f, 0x74, 0x65, 0x61, 0x6d, 0x5f, 0x63, 0x6f, 0x6d, 0x70, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f,
	0x42, 0x0c, 0x5a, 0x07, 0x70, 0x62, 0x2f, 0x67, 0x61, 0x6d, 0x65, 0x80, 0x01, 0x01, 0x62, 0x06,
	0x70, 0x72, 0x6f, 0x74, 0x6f, 0x33,
}

var file_logic_proto_centre_team_proto_goTypes = []interface{}{}
var file_logic_proto_centre_team_proto_depIdxs = []int32{
	0, // [0:0] is the sub-list for method output_type
	0, // [0:0] is the sub-list for method input_type
	0, // [0:0] is the sub-list for extension type_name
	0, // [0:0] is the sub-list for extension extendee
	0, // [0:0] is the sub-list for field type_name
}

func init() { file_logic_proto_centre_team_proto_init() }
func file_logic_proto_centre_team_proto_init() {
	if File_logic_proto_centre_team_proto != nil {
		return
	}
	file_component_proto_team_comp_proto_init()
	type x struct{}
	out := protoimpl.TypeBuilder{
		File: protoimpl.DescBuilder{
			GoPackagePath: reflect.TypeOf(x{}).PkgPath(),
			RawDescriptor: file_logic_proto_centre_team_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   0,
			NumExtensions: 0,
			NumServices:   0,
		},
		GoTypes:           file_logic_proto_centre_team_proto_goTypes,
		DependencyIndexes: file_logic_proto_centre_team_proto_depIdxs,
	}.Build()
	File_logic_proto_centre_team_proto = out.File
	file_logic_proto_centre_team_proto_rawDesc = nil
	file_logic_proto_centre_team_proto_goTypes = nil
	file_logic_proto_centre_team_proto_depIdxs = nil
}
