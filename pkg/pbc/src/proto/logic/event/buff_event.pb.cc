// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: logic/event/buff_event.proto
// Protobuf C++ Version: 5.26.1

#include "logic/event/buff_event.pb.h"

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

inline constexpr SkillExecutedEvent::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : skill_id_{::uint64_t{0u}},
        caster_id_{::uint64_t{0u}},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR SkillExecutedEvent::SkillExecutedEvent(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct SkillExecutedEventDefaultTypeInternal {
  PROTOBUF_CONSTEXPR SkillExecutedEventDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~SkillExecutedEventDefaultTypeInternal() {}
  union {
    SkillExecutedEvent _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 SkillExecutedEventDefaultTypeInternal _SkillExecutedEvent_default_instance_;

inline constexpr BeforeGiveDamageEvent::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : skill_idd_{::uint64_t{0u}},
        attacker_id_{::uint64_t{0u}},
        receiver_id_{::uint64_t{0u}},
        damage_amount_{0},
        damage_flags_{0u},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR BeforeGiveDamageEvent::BeforeGiveDamageEvent(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct BeforeGiveDamageEventDefaultTypeInternal {
  PROTOBUF_CONSTEXPR BeforeGiveDamageEventDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~BeforeGiveDamageEventDefaultTypeInternal() {}
  union {
    BeforeGiveDamageEvent _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 BeforeGiveDamageEventDefaultTypeInternal _BeforeGiveDamageEvent_default_instance_;
static ::_pb::Metadata file_level_metadata_logic_2fevent_2fbuff_5fevent_2eproto[2];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_logic_2fevent_2fbuff_5fevent_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_logic_2fevent_2fbuff_5fevent_2eproto = nullptr;
const ::uint32_t
    TableStruct_logic_2fevent_2fbuff_5fevent_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::SkillExecutedEvent, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::SkillExecutedEvent, _impl_.skill_id_),
        PROTOBUF_FIELD_OFFSET(::SkillExecutedEvent, _impl_.caster_id_),
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::BeforeGiveDamageEvent, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::BeforeGiveDamageEvent, _impl_.skill_idd_),
        PROTOBUF_FIELD_OFFSET(::BeforeGiveDamageEvent, _impl_.attacker_id_),
        PROTOBUF_FIELD_OFFSET(::BeforeGiveDamageEvent, _impl_.receiver_id_),
        PROTOBUF_FIELD_OFFSET(::BeforeGiveDamageEvent, _impl_.damage_amount_),
        PROTOBUF_FIELD_OFFSET(::BeforeGiveDamageEvent, _impl_.damage_flags_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::SkillExecutedEvent)},
        {10, -1, -1, sizeof(::BeforeGiveDamageEvent)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::_SkillExecutedEvent_default_instance_._instance,
    &::_BeforeGiveDamageEvent_default_instance_._instance,
};
const char descriptor_table_protodef_logic_2fevent_2fbuff_5fevent_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\034logic/event/buff_event.proto\"9\n\022SkillE"
    "xecutedEvent\022\020\n\010skill_id\030\001 \001(\004\022\021\n\tcaster"
    "_id\030\002 \001(\004\"\201\001\n\025BeforeGiveDamageEvent\022\021\n\ts"
    "kill_idd\030\001 \001(\004\022\023\n\013attacker_id\030\002 \001(\004\022\023\n\013r"
    "eceiver_id\030\003 \001(\004\022\025\n\rdamage_amount\030\004 \001(\001\022"
    "\024\n\014damage_flags\030\005 \001(\rB\tZ\007pb/gameb\006proto3"
};
static ::absl::once_flag descriptor_table_logic_2fevent_2fbuff_5fevent_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_logic_2fevent_2fbuff_5fevent_2eproto = {
    false,
    false,
    240,
    descriptor_table_protodef_logic_2fevent_2fbuff_5fevent_2eproto,
    "logic/event/buff_event.proto",
    &descriptor_table_logic_2fevent_2fbuff_5fevent_2eproto_once,
    nullptr,
    0,
    2,
    schemas,
    file_default_instances,
    TableStruct_logic_2fevent_2fbuff_5fevent_2eproto::offsets,
    file_level_metadata_logic_2fevent_2fbuff_5fevent_2eproto,
    file_level_enum_descriptors_logic_2fevent_2fbuff_5fevent_2eproto,
    file_level_service_descriptors_logic_2fevent_2fbuff_5fevent_2eproto,
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
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_logic_2fevent_2fbuff_5fevent_2eproto_getter() {
  return &descriptor_table_logic_2fevent_2fbuff_5fevent_2eproto;
}
// ===================================================================

class SkillExecutedEvent::_Internal {
 public:
};

SkillExecutedEvent::SkillExecutedEvent(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:SkillExecutedEvent)
}
SkillExecutedEvent::SkillExecutedEvent(
    ::google::protobuf::Arena* arena, const SkillExecutedEvent& from)
    : SkillExecutedEvent(arena) {
  MergeFrom(from);
}
inline PROTOBUF_NDEBUG_INLINE SkillExecutedEvent::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0} {}

inline void SkillExecutedEvent::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, skill_id_),
           0,
           offsetof(Impl_, caster_id_) -
               offsetof(Impl_, skill_id_) +
               sizeof(Impl_::caster_id_));
}
SkillExecutedEvent::~SkillExecutedEvent() {
  // @@protoc_insertion_point(destructor:SkillExecutedEvent)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void SkillExecutedEvent::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
SkillExecutedEvent::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(SkillExecutedEvent, _impl_._cached_size_),
              false,
          },
          &SkillExecutedEvent::MergeImpl,
          &SkillExecutedEvent::kDescriptorMethods,
      };
  return &_data_;
}
PROTOBUF_NOINLINE void SkillExecutedEvent::Clear() {
// @@protoc_insertion_point(message_clear_start:SkillExecutedEvent)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&_impl_.skill_id_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.caster_id_) -
      reinterpret_cast<char*>(&_impl_.skill_id_)) + sizeof(_impl_.caster_id_));
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* SkillExecutedEvent::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 0, 0, 2> SkillExecutedEvent::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_SkillExecutedEvent_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::SkillExecutedEvent>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // uint64 caster_id = 2;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(SkillExecutedEvent, _impl_.caster_id_), 63>(),
     {16, 63, 0, PROTOBUF_FIELD_OFFSET(SkillExecutedEvent, _impl_.caster_id_)}},
    // uint64 skill_id = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(SkillExecutedEvent, _impl_.skill_id_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(SkillExecutedEvent, _impl_.skill_id_)}},
  }}, {{
    65535, 65535
  }}, {{
    // uint64 skill_id = 1;
    {PROTOBUF_FIELD_OFFSET(SkillExecutedEvent, _impl_.skill_id_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUInt64)},
    // uint64 caster_id = 2;
    {PROTOBUF_FIELD_OFFSET(SkillExecutedEvent, _impl_.caster_id_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUInt64)},
  }},
  // no aux_entries
  {{
  }},
};

::uint8_t* SkillExecutedEvent::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:SkillExecutedEvent)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // uint64 skill_id = 1;
  if (this->_internal_skill_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(
        1, this->_internal_skill_id(), target);
  }

  // uint64 caster_id = 2;
  if (this->_internal_caster_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(
        2, this->_internal_caster_id(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:SkillExecutedEvent)
  return target;
}

::size_t SkillExecutedEvent::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:SkillExecutedEvent)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // uint64 skill_id = 1;
  if (this->_internal_skill_id() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(
        this->_internal_skill_id());
  }

  // uint64 caster_id = 2;
  if (this->_internal_caster_id() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(
        this->_internal_caster_id());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void SkillExecutedEvent::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<SkillExecutedEvent*>(&to_msg);
  auto& from = static_cast<const SkillExecutedEvent&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:SkillExecutedEvent)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_skill_id() != 0) {
    _this->_impl_.skill_id_ = from._impl_.skill_id_;
  }
  if (from._internal_caster_id() != 0) {
    _this->_impl_.caster_id_ = from._impl_.caster_id_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void SkillExecutedEvent::CopyFrom(const SkillExecutedEvent& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:SkillExecutedEvent)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool SkillExecutedEvent::IsInitialized() const {
  return true;
}

void SkillExecutedEvent::InternalSwap(SkillExecutedEvent* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(SkillExecutedEvent, _impl_.caster_id_)
      + sizeof(SkillExecutedEvent::_impl_.caster_id_)
      - PROTOBUF_FIELD_OFFSET(SkillExecutedEvent, _impl_.skill_id_)>(
          reinterpret_cast<char*>(&_impl_.skill_id_),
          reinterpret_cast<char*>(&other->_impl_.skill_id_));
}

::google::protobuf::Metadata SkillExecutedEvent::GetMetadata() const {
  return ::_pbi::AssignDescriptors(&descriptor_table_logic_2fevent_2fbuff_5fevent_2eproto_getter,
                                   &descriptor_table_logic_2fevent_2fbuff_5fevent_2eproto_once,
                                   file_level_metadata_logic_2fevent_2fbuff_5fevent_2eproto[0]);
}
// ===================================================================

class BeforeGiveDamageEvent::_Internal {
 public:
};

BeforeGiveDamageEvent::BeforeGiveDamageEvent(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:BeforeGiveDamageEvent)
}
BeforeGiveDamageEvent::BeforeGiveDamageEvent(
    ::google::protobuf::Arena* arena, const BeforeGiveDamageEvent& from)
    : BeforeGiveDamageEvent(arena) {
  MergeFrom(from);
}
inline PROTOBUF_NDEBUG_INLINE BeforeGiveDamageEvent::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0} {}

inline void BeforeGiveDamageEvent::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, skill_idd_),
           0,
           offsetof(Impl_, damage_flags_) -
               offsetof(Impl_, skill_idd_) +
               sizeof(Impl_::damage_flags_));
}
BeforeGiveDamageEvent::~BeforeGiveDamageEvent() {
  // @@protoc_insertion_point(destructor:BeforeGiveDamageEvent)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void BeforeGiveDamageEvent::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
BeforeGiveDamageEvent::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(BeforeGiveDamageEvent, _impl_._cached_size_),
              false,
          },
          &BeforeGiveDamageEvent::MergeImpl,
          &BeforeGiveDamageEvent::kDescriptorMethods,
      };
  return &_data_;
}
PROTOBUF_NOINLINE void BeforeGiveDamageEvent::Clear() {
// @@protoc_insertion_point(message_clear_start:BeforeGiveDamageEvent)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&_impl_.skill_idd_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.damage_flags_) -
      reinterpret_cast<char*>(&_impl_.skill_idd_)) + sizeof(_impl_.damage_flags_));
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* BeforeGiveDamageEvent::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<3, 5, 0, 0, 2> BeforeGiveDamageEvent::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    5, 56,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967264,  // skipmap
    offsetof(decltype(_table_), field_entries),
    5,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_BeforeGiveDamageEvent_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::BeforeGiveDamageEvent>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // uint64 skill_idd = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(BeforeGiveDamageEvent, _impl_.skill_idd_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(BeforeGiveDamageEvent, _impl_.skill_idd_)}},
    // uint64 attacker_id = 2;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(BeforeGiveDamageEvent, _impl_.attacker_id_), 63>(),
     {16, 63, 0, PROTOBUF_FIELD_OFFSET(BeforeGiveDamageEvent, _impl_.attacker_id_)}},
    // uint64 receiver_id = 3;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(BeforeGiveDamageEvent, _impl_.receiver_id_), 63>(),
     {24, 63, 0, PROTOBUF_FIELD_OFFSET(BeforeGiveDamageEvent, _impl_.receiver_id_)}},
    // double damage_amount = 4;
    {::_pbi::TcParser::FastF64S1,
     {33, 63, 0, PROTOBUF_FIELD_OFFSET(BeforeGiveDamageEvent, _impl_.damage_amount_)}},
    // uint32 damage_flags = 5;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(BeforeGiveDamageEvent, _impl_.damage_flags_), 63>(),
     {40, 63, 0, PROTOBUF_FIELD_OFFSET(BeforeGiveDamageEvent, _impl_.damage_flags_)}},
    {::_pbi::TcParser::MiniParse, {}},
    {::_pbi::TcParser::MiniParse, {}},
  }}, {{
    65535, 65535
  }}, {{
    // uint64 skill_idd = 1;
    {PROTOBUF_FIELD_OFFSET(BeforeGiveDamageEvent, _impl_.skill_idd_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUInt64)},
    // uint64 attacker_id = 2;
    {PROTOBUF_FIELD_OFFSET(BeforeGiveDamageEvent, _impl_.attacker_id_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUInt64)},
    // uint64 receiver_id = 3;
    {PROTOBUF_FIELD_OFFSET(BeforeGiveDamageEvent, _impl_.receiver_id_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUInt64)},
    // double damage_amount = 4;
    {PROTOBUF_FIELD_OFFSET(BeforeGiveDamageEvent, _impl_.damage_amount_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kDouble)},
    // uint32 damage_flags = 5;
    {PROTOBUF_FIELD_OFFSET(BeforeGiveDamageEvent, _impl_.damage_flags_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUInt32)},
  }},
  // no aux_entries
  {{
  }},
};

::uint8_t* BeforeGiveDamageEvent::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:BeforeGiveDamageEvent)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // uint64 skill_idd = 1;
  if (this->_internal_skill_idd() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(
        1, this->_internal_skill_idd(), target);
  }

  // uint64 attacker_id = 2;
  if (this->_internal_attacker_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(
        2, this->_internal_attacker_id(), target);
  }

  // uint64 receiver_id = 3;
  if (this->_internal_receiver_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(
        3, this->_internal_receiver_id(), target);
  }

  // double damage_amount = 4;
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_damage_amount = this->_internal_damage_amount();
  ::uint64_t raw_damage_amount;
  memcpy(&raw_damage_amount, &tmp_damage_amount, sizeof(tmp_damage_amount));
  if (raw_damage_amount != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(
        4, this->_internal_damage_amount(), target);
  }

  // uint32 damage_flags = 5;
  if (this->_internal_damage_flags() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(
        5, this->_internal_damage_flags(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:BeforeGiveDamageEvent)
  return target;
}

::size_t BeforeGiveDamageEvent::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:BeforeGiveDamageEvent)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // uint64 skill_idd = 1;
  if (this->_internal_skill_idd() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(
        this->_internal_skill_idd());
  }

  // uint64 attacker_id = 2;
  if (this->_internal_attacker_id() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(
        this->_internal_attacker_id());
  }

  // uint64 receiver_id = 3;
  if (this->_internal_receiver_id() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(
        this->_internal_receiver_id());
  }

  // double damage_amount = 4;
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_damage_amount = this->_internal_damage_amount();
  ::uint64_t raw_damage_amount;
  memcpy(&raw_damage_amount, &tmp_damage_amount, sizeof(tmp_damage_amount));
  if (raw_damage_amount != 0) {
    total_size += 9;
  }

  // uint32 damage_flags = 5;
  if (this->_internal_damage_flags() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(
        this->_internal_damage_flags());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void BeforeGiveDamageEvent::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<BeforeGiveDamageEvent*>(&to_msg);
  auto& from = static_cast<const BeforeGiveDamageEvent&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:BeforeGiveDamageEvent)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_skill_idd() != 0) {
    _this->_impl_.skill_idd_ = from._impl_.skill_idd_;
  }
  if (from._internal_attacker_id() != 0) {
    _this->_impl_.attacker_id_ = from._impl_.attacker_id_;
  }
  if (from._internal_receiver_id() != 0) {
    _this->_impl_.receiver_id_ = from._impl_.receiver_id_;
  }
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_damage_amount = from._internal_damage_amount();
  ::uint64_t raw_damage_amount;
  memcpy(&raw_damage_amount, &tmp_damage_amount, sizeof(tmp_damage_amount));
  if (raw_damage_amount != 0) {
    _this->_impl_.damage_amount_ = from._impl_.damage_amount_;
  }
  if (from._internal_damage_flags() != 0) {
    _this->_impl_.damage_flags_ = from._impl_.damage_flags_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void BeforeGiveDamageEvent::CopyFrom(const BeforeGiveDamageEvent& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:BeforeGiveDamageEvent)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool BeforeGiveDamageEvent::IsInitialized() const {
  return true;
}

void BeforeGiveDamageEvent::InternalSwap(BeforeGiveDamageEvent* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(BeforeGiveDamageEvent, _impl_.damage_flags_)
      + sizeof(BeforeGiveDamageEvent::_impl_.damage_flags_)
      - PROTOBUF_FIELD_OFFSET(BeforeGiveDamageEvent, _impl_.skill_idd_)>(
          reinterpret_cast<char*>(&_impl_.skill_idd_),
          reinterpret_cast<char*>(&other->_impl_.skill_idd_));
}

::google::protobuf::Metadata BeforeGiveDamageEvent::GetMetadata() const {
  return ::_pbi::AssignDescriptors(&descriptor_table_logic_2fevent_2fbuff_5fevent_2eproto_getter,
                                   &descriptor_table_logic_2fevent_2fbuff_5fevent_2eproto_once,
                                   file_level_metadata_logic_2fevent_2fbuff_5fevent_2eproto[1]);
}
// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::std::false_type _static_init_ PROTOBUF_UNUSED =
    (::_pbi::AddDescriptors(&descriptor_table_logic_2fevent_2fbuff_5fevent_2eproto),
     ::std::false_type{});
#include "google/protobuf/port_undef.inc"
