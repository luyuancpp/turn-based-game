// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: logic/server_player/centre_player.proto
// Protobuf C++ Version: 5.26.1

#include "logic/server_player/centre_player.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_logic_2fserver_5fplayer_2fcentre_5fplayer_2eproto = nullptr;
static const ::_pb::ServiceDescriptor*
    file_level_service_descriptors_logic_2fserver_5fplayer_2fcentre_5fplayer_2eproto[1];
const ::uint32_t TableStruct_logic_2fserver_5fplayer_2fcentre_5fplayer_2eproto::offsets[1] = {};
static constexpr ::_pbi::MigrationSchema* schemas = nullptr;
static constexpr ::_pb::Message* const* file_default_instances = nullptr;
const char descriptor_table_protodef_logic_2fserver_5fplayer_2fcentre_5fplayer_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\'logic/server_player/centre_player.prot"
    "o\032\033google/protobuf/empty.proto2M\n\023Centre"
    "PlayerService\0226\n\004Test\022\026.google.protobuf."
    "Empty\032\026.google.protobuf.EmptyB\014Z\007pb/game"
    "\200\001\001b\006proto3"
};
static const ::_pbi::DescriptorTable* const descriptor_table_logic_2fserver_5fplayer_2fcentre_5fplayer_2eproto_deps[1] =
    {
        &::descriptor_table_google_2fprotobuf_2fempty_2eproto,
};
static ::absl::once_flag descriptor_table_logic_2fserver_5fplayer_2fcentre_5fplayer_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_logic_2fserver_5fplayer_2fcentre_5fplayer_2eproto = {
    false,
    false,
    171,
    descriptor_table_protodef_logic_2fserver_5fplayer_2fcentre_5fplayer_2eproto,
    "logic/server_player/centre_player.proto",
    &descriptor_table_logic_2fserver_5fplayer_2fcentre_5fplayer_2eproto_once,
    descriptor_table_logic_2fserver_5fplayer_2fcentre_5fplayer_2eproto_deps,
    1,
    0,
    schemas,
    file_default_instances,
    TableStruct_logic_2fserver_5fplayer_2fcentre_5fplayer_2eproto::offsets,
    nullptr,
    file_level_enum_descriptors_logic_2fserver_5fplayer_2fcentre_5fplayer_2eproto,
    file_level_service_descriptors_logic_2fserver_5fplayer_2fcentre_5fplayer_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_logic_2fserver_5fplayer_2fcentre_5fplayer_2eproto_getter() {
  return &descriptor_table_logic_2fserver_5fplayer_2fcentre_5fplayer_2eproto;
}
// ===================================================================

const ::google::protobuf::ServiceDescriptor* CentrePlayerService::descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&descriptor_table_logic_2fserver_5fplayer_2fcentre_5fplayer_2eproto);
  return file_level_service_descriptors_logic_2fserver_5fplayer_2fcentre_5fplayer_2eproto[0];
}

const ::google::protobuf::ServiceDescriptor* CentrePlayerService::GetDescriptor() {
  return descriptor();
}

void CentrePlayerService::Test(::google::protobuf::RpcController* controller,
                         const ::google::protobuf::Empty*, ::google::protobuf::Empty*, ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Test() not implemented.");
  done->Run();
}

void CentrePlayerService::CallMethod(
    const ::google::protobuf::MethodDescriptor* method,
    ::google::protobuf::RpcController* controller,
    const ::google::protobuf::Message* request,
    ::google::protobuf::Message* response, ::google::protobuf::Closure* done) {
  ABSL_DCHECK_EQ(method->service(), file_level_service_descriptors_logic_2fserver_5fplayer_2fcentre_5fplayer_2eproto[0]);
  switch (method->index()) {
    case 0:
      Test(controller,
             ::google::protobuf::internal::DownCast<const ::google::protobuf::Empty*>(request),
             ::google::protobuf::internal::DownCast<::google::protobuf::Empty*>(response), done);
      break;

    default:
      ABSL_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::google::protobuf::Message& CentrePlayerService::GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  ABSL_DCHECK_EQ(method->service(), descriptor());
  switch (method->index()) {
    case 0:
      return ::google::protobuf::Empty::default_instance();

    default:
      ABSL_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::google::protobuf::MessageFactory::generated_factory()
                  ->GetPrototype(method->input_type());
  }
}

const ::google::protobuf::Message& CentrePlayerService::GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  ABSL_DCHECK_EQ(method->service(), descriptor());
  switch (method->index()) {
    case 0:
      return ::google::protobuf::Empty::default_instance();

    default:
      ABSL_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::google::protobuf::MessageFactory::generated_factory()
                  ->GetPrototype(method->output_type());
  }
}

CentrePlayerService_Stub::CentrePlayerService_Stub(::google::protobuf::RpcChannel* channel)
    : channel_(channel), owns_channel_(false) {}

CentrePlayerService_Stub::CentrePlayerService_Stub(
    ::google::protobuf::RpcChannel* channel,
    ::google::protobuf::Service::ChannelOwnership ownership)
    : channel_(channel),
      owns_channel_(ownership ==
                    ::google::protobuf::Service::STUB_OWNS_CHANNEL) {}

CentrePlayerService_Stub::~CentrePlayerService_Stub() {
  if (owns_channel_) delete channel_;
}

void CentrePlayerService_Stub::Test(::google::protobuf::RpcController* controller,
                              const ::google::protobuf::Empty* request,
                              ::google::protobuf::Empty* response, ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0), controller,
                       request, response, done);
}
// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::std::false_type _static_init_ PROTOBUF_UNUSED =
    (::_pbi::AddDescriptors(&descriptor_table_logic_2fserver_5fplayer_2fcentre_5fplayer_2eproto),
     ::std::false_type{});
#include "google/protobuf/port_undef.inc"
