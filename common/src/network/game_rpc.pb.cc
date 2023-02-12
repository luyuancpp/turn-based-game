// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: game_rpc.proto

#include "game_rpc.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace muduo {
namespace net {
PROTOBUF_CONSTEXPR RpcMessage::RpcMessage(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.service_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.method_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.request_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.response_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.id_)*/uint64_t{0u}
  , /*decltype(_impl_.type_)*/0
  , /*decltype(_impl_.error_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct RpcMessageDefaultTypeInternal {
  PROTOBUF_CONSTEXPR RpcMessageDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~RpcMessageDefaultTypeInternal() {}
  union {
    RpcMessage _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 RpcMessageDefaultTypeInternal _RpcMessage_default_instance_;
}  // namespace net
}  // namespace muduo
static ::_pb::Metadata file_level_metadata_game_5frpc_2eproto[1];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_game_5frpc_2eproto[2];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_game_5frpc_2eproto = nullptr;

const uint32_t TableStruct_game_5frpc_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::muduo::net::RpcMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::muduo::net::RpcMessage, _impl_.type_),
  PROTOBUF_FIELD_OFFSET(::muduo::net::RpcMessage, _impl_.id_),
  PROTOBUF_FIELD_OFFSET(::muduo::net::RpcMessage, _impl_.service_),
  PROTOBUF_FIELD_OFFSET(::muduo::net::RpcMessage, _impl_.method_),
  PROTOBUF_FIELD_OFFSET(::muduo::net::RpcMessage, _impl_.request_),
  PROTOBUF_FIELD_OFFSET(::muduo::net::RpcMessage, _impl_.response_),
  PROTOBUF_FIELD_OFFSET(::muduo::net::RpcMessage, _impl_.error_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::muduo::net::RpcMessage)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::muduo::net::_RpcMessage_default_instance_._instance,
};

const char descriptor_table_protodef_game_5frpc_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016game_rpc.proto\022\tmuduo.net\"\247\001\n\nRpcMessa"
  "ge\022$\n\004type\030\001 \001(\0162\026.muduo.net.MessageType"
  "\022\n\n\002id\030\002 \001(\006\022\017\n\007service\030\003 \001(\t\022\016\n\006method\030"
  "\004 \001(\t\022\017\n\007request\030\005 \001(\014\022\020\n\010response\030\006 \001(\014"
  "\022#\n\005error\030\007 \001(\0162\024.muduo.net.ErrorCode*X\n"
  "\013MessageType\022\013\n\007REQUEST\020\000\022\014\n\010RESPONSE\020\001\022"
  "\017\n\013S2C_REQUEST\020\002\022\016\n\nNODE_ROUTE\020\003\022\r\n\tRPC_"
  "ERROR\020\004*\205\001\n\tErrorCode\022\020\n\014RPC_NO_ERROR\020\000\022"
  "\017\n\013WRONG_PROTO\020\001\022\016\n\nNO_SERVICE\020\002\022\r\n\tNO_M"
  "ETHOD\020\003\022\023\n\017INVALID_REQUEST\020\004\022\024\n\020INVALID_"
  "RESPONSE\020\005\022\013\n\007TIMEOUT\020\006B\'\n\033com.chenshuo."
  "muduo.protorpcB\010RpcProtob\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_game_5frpc_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_game_5frpc_2eproto = {
    false, false, 472, descriptor_table_protodef_game_5frpc_2eproto,
    "game_rpc.proto",
    &descriptor_table_game_5frpc_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_game_5frpc_2eproto::offsets,
    file_level_metadata_game_5frpc_2eproto, file_level_enum_descriptors_game_5frpc_2eproto,
    file_level_service_descriptors_game_5frpc_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_game_5frpc_2eproto_getter() {
  return &descriptor_table_game_5frpc_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_game_5frpc_2eproto(&descriptor_table_game_5frpc_2eproto);
namespace muduo {
namespace net {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* MessageType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_game_5frpc_2eproto);
  return file_level_enum_descriptors_game_5frpc_2eproto[0];
}
bool MessageType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ErrorCode_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_game_5frpc_2eproto);
  return file_level_enum_descriptors_game_5frpc_2eproto[1];
}
bool ErrorCode_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
      return true;
    default:
      return false;
  }
}


// ===================================================================

class RpcMessage::_Internal {
 public:
};

RpcMessage::RpcMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:muduo.net.RpcMessage)
}
RpcMessage::RpcMessage(const RpcMessage& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  RpcMessage* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.service_){}
    , decltype(_impl_.method_){}
    , decltype(_impl_.request_){}
    , decltype(_impl_.response_){}
    , decltype(_impl_.id_){}
    , decltype(_impl_.type_){}
    , decltype(_impl_.error_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.service_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.service_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_service().empty()) {
    _this->_impl_.service_.Set(from._internal_service(), 
      _this->GetArenaForAllocation());
  }
  _impl_.method_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.method_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_method().empty()) {
    _this->_impl_.method_.Set(from._internal_method(), 
      _this->GetArenaForAllocation());
  }
  _impl_.request_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.request_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_request().empty()) {
    _this->_impl_.request_.Set(from._internal_request(), 
      _this->GetArenaForAllocation());
  }
  _impl_.response_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.response_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_response().empty()) {
    _this->_impl_.response_.Set(from._internal_response(), 
      _this->GetArenaForAllocation());
  }
  ::memcpy(&_impl_.id_, &from._impl_.id_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.error_) -
    reinterpret_cast<char*>(&_impl_.id_)) + sizeof(_impl_.error_));
  // @@protoc_insertion_point(copy_constructor:muduo.net.RpcMessage)
}

inline void RpcMessage::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.service_){}
    , decltype(_impl_.method_){}
    , decltype(_impl_.request_){}
    , decltype(_impl_.response_){}
    , decltype(_impl_.id_){uint64_t{0u}}
    , decltype(_impl_.type_){0}
    , decltype(_impl_.error_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.service_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.service_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.method_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.method_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.request_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.request_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.response_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.response_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

RpcMessage::~RpcMessage() {
  // @@protoc_insertion_point(destructor:muduo.net.RpcMessage)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void RpcMessage::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.service_.Destroy();
  _impl_.method_.Destroy();
  _impl_.request_.Destroy();
  _impl_.response_.Destroy();
}

void RpcMessage::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void RpcMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:muduo.net.RpcMessage)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.service_.ClearToEmpty();
  _impl_.method_.ClearToEmpty();
  _impl_.request_.ClearToEmpty();
  _impl_.response_.ClearToEmpty();
  ::memset(&_impl_.id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.error_) -
      reinterpret_cast<char*>(&_impl_.id_)) + sizeof(_impl_.error_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* RpcMessage::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .muduo.net.MessageType type = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_type(static_cast<::muduo::net::MessageType>(val));
        } else
          goto handle_unusual;
        continue;
      // fixed64 id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 17)) {
          _impl_.id_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<uint64_t>(ptr);
          ptr += sizeof(uint64_t);
        } else
          goto handle_unusual;
        continue;
      // string service = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_service();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "muduo.net.RpcMessage.service"));
        } else
          goto handle_unusual;
        continue;
      // string method = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          auto str = _internal_mutable_method();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "muduo.net.RpcMessage.method"));
        } else
          goto handle_unusual;
        continue;
      // bytes request = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 42)) {
          auto str = _internal_mutable_request();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes response = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 50)) {
          auto str = _internal_mutable_response();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .muduo.net.ErrorCode error = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 56)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_error(static_cast<::muduo::net::ErrorCode>(val));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* RpcMessage::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:muduo.net.RpcMessage)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .muduo.net.MessageType type = 1;
  if (this->_internal_type() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      1, this->_internal_type(), target);
  }

  // fixed64 id = 2;
  if (this->_internal_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFixed64ToArray(2, this->_internal_id(), target);
  }

  // string service = 3;
  if (!this->_internal_service().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_service().data(), static_cast<int>(this->_internal_service().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "muduo.net.RpcMessage.service");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_service(), target);
  }

  // string method = 4;
  if (!this->_internal_method().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_method().data(), static_cast<int>(this->_internal_method().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "muduo.net.RpcMessage.method");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_method(), target);
  }

  // bytes request = 5;
  if (!this->_internal_request().empty()) {
    target = stream->WriteBytesMaybeAliased(
        5, this->_internal_request(), target);
  }

  // bytes response = 6;
  if (!this->_internal_response().empty()) {
    target = stream->WriteBytesMaybeAliased(
        6, this->_internal_response(), target);
  }

  // .muduo.net.ErrorCode error = 7;
  if (this->_internal_error() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      7, this->_internal_error(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:muduo.net.RpcMessage)
  return target;
}

size_t RpcMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:muduo.net.RpcMessage)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string service = 3;
  if (!this->_internal_service().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_service());
  }

  // string method = 4;
  if (!this->_internal_method().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_method());
  }

  // bytes request = 5;
  if (!this->_internal_request().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_request());
  }

  // bytes response = 6;
  if (!this->_internal_response().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_response());
  }

  // fixed64 id = 2;
  if (this->_internal_id() != 0) {
    total_size += 1 + 8;
  }

  // .muduo.net.MessageType type = 1;
  if (this->_internal_type() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_type());
  }

  // .muduo.net.ErrorCode error = 7;
  if (this->_internal_error() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_error());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData RpcMessage::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    RpcMessage::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*RpcMessage::GetClassData() const { return &_class_data_; }


void RpcMessage::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<RpcMessage*>(&to_msg);
  auto& from = static_cast<const RpcMessage&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:muduo.net.RpcMessage)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_service().empty()) {
    _this->_internal_set_service(from._internal_service());
  }
  if (!from._internal_method().empty()) {
    _this->_internal_set_method(from._internal_method());
  }
  if (!from._internal_request().empty()) {
    _this->_internal_set_request(from._internal_request());
  }
  if (!from._internal_response().empty()) {
    _this->_internal_set_response(from._internal_response());
  }
  if (from._internal_id() != 0) {
    _this->_internal_set_id(from._internal_id());
  }
  if (from._internal_type() != 0) {
    _this->_internal_set_type(from._internal_type());
  }
  if (from._internal_error() != 0) {
    _this->_internal_set_error(from._internal_error());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void RpcMessage::CopyFrom(const RpcMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:muduo.net.RpcMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RpcMessage::IsInitialized() const {
  return true;
}

void RpcMessage::InternalSwap(RpcMessage* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.service_, lhs_arena,
      &other->_impl_.service_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.method_, lhs_arena,
      &other->_impl_.method_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.request_, lhs_arena,
      &other->_impl_.request_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.response_, lhs_arena,
      &other->_impl_.response_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(RpcMessage, _impl_.error_)
      + sizeof(RpcMessage::_impl_.error_)
      - PROTOBUF_FIELD_OFFSET(RpcMessage, _impl_.id_)>(
          reinterpret_cast<char*>(&_impl_.id_),
          reinterpret_cast<char*>(&other->_impl_.id_));
}

::PROTOBUF_NAMESPACE_ID::Metadata RpcMessage::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_game_5frpc_2eproto_getter, &descriptor_table_game_5frpc_2eproto_once,
      file_level_metadata_game_5frpc_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace net
}  // namespace muduo
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::muduo::net::RpcMessage*
Arena::CreateMaybeMessage< ::muduo::net::RpcMessage >(Arena* arena) {
  return Arena::CreateMessageInternal< ::muduo::net::RpcMessage >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
