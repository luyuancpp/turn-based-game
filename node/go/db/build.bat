protoc  ../../../proto/common_proto/account_database.proto --go_out=./  --proto_path=../../../proto/ --proto_path=../../../third_party/protobuf/src/
protoc  ../../../proto/common_proto/comp.proto --go_out=./  --proto_path=../../../proto/ --proto_path=../../../third_party/protobuf/src/
protoc  ../../../proto/common_proto/mysql_database_table.proto --go_out=./  --proto_path=../../../proto/ --proto_path=../../../third_party/protobuf/src/
protoc  ../../../proto/component_proto/player_scene_comp.proto --go_out=./  --proto_path=../../../proto/ --proto_path=../../../third_party/protobuf/src/
goctl rpc protoc ../../../proto/common_proto/db_service.proto --proto_path=../../../proto/ --proto_path=../../../third_party/protobuf/src/ --go_out=./ --go-grpc_out=./ --zrpc_out=. -m

pause