// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mainscene_config.proto
// Protobuf C++ Version: 5.26.1

#include "mainscene_config.pb.h"

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

inline constexpr MainSceneTable::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : nav_bin_file_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        id_{0u},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR MainSceneTable::MainSceneTable(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct MainSceneTableDefaultTypeInternal {
  PROTOBUF_CONSTEXPR MainSceneTableDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~MainSceneTableDefaultTypeInternal() {}
  union {
    MainSceneTable _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 MainSceneTableDefaultTypeInternal _MainSceneTable_default_instance_;

inline constexpr MainSceneTabledData::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : data_{},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR MainSceneTabledData::MainSceneTabledData(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct MainSceneTabledDataDefaultTypeInternal {
  PROTOBUF_CONSTEXPR MainSceneTabledDataDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~MainSceneTabledDataDefaultTypeInternal() {}
  union {
    MainSceneTabledData _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 MainSceneTabledDataDefaultTypeInternal _MainSceneTabledData_default_instance_;
static ::_pb::Metadata file_level_metadata_mainscene_5fconfig_2eproto[2];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_mainscene_5fconfig_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_mainscene_5fconfig_2eproto = nullptr;
const ::uint32_t
    TableStruct_mainscene_5fconfig_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::MainSceneTable, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::MainSceneTable, _impl_.id_),
        PROTOBUF_FIELD_OFFSET(::MainSceneTable, _impl_.nav_bin_file_),
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::MainSceneTabledData, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::MainSceneTabledData, _impl_.data_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::MainSceneTable)},
        {10, -1, -1, sizeof(::MainSceneTabledData)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::_MainSceneTable_default_instance_._instance,
    &::_MainSceneTabledData_default_instance_._instance,
};
const char descriptor_table_protodef_mainscene_5fconfig_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\026mainscene_config.proto\"2\n\016MainSceneTab"
    "le\022\n\n\002id\030\001 \001(\r\022\024\n\014nav_bin_file\030\002 \001(\t\"4\n\023"
    "MainSceneTabledData\022\035\n\004data\030\001 \003(\0132\017.Main"
    "SceneTableB\tZ\007pb/gameb\006proto3"
};
static ::absl::once_flag descriptor_table_mainscene_5fconfig_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_mainscene_5fconfig_2eproto = {
    false,
    false,
    149,
    descriptor_table_protodef_mainscene_5fconfig_2eproto,
    "mainscene_config.proto",
    &descriptor_table_mainscene_5fconfig_2eproto_once,
    nullptr,
    0,
    2,
    schemas,
    file_default_instances,
    TableStruct_mainscene_5fconfig_2eproto::offsets,
    file_level_metadata_mainscene_5fconfig_2eproto,
    file_level_enum_descriptors_mainscene_5fconfig_2eproto,
    file_level_service_descriptors_mainscene_5fconfig_2eproto,
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
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_mainscene_5fconfig_2eproto_getter() {
  return &descriptor_table_mainscene_5fconfig_2eproto;
}
// ===================================================================

class MainSceneTable::_Internal {
 public:
};

MainSceneTable::MainSceneTable(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:MainSceneTable)
}
inline PROTOBUF_NDEBUG_INLINE MainSceneTable::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : nav_bin_file_(arena, from.nav_bin_file_),
        _cached_size_{0} {}

MainSceneTable::MainSceneTable(
    ::google::protobuf::Arena* arena,
    const MainSceneTable& from)
    : ::google::protobuf::Message(arena) {
  MainSceneTable* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  _impl_.id_ = from._impl_.id_;

  // @@protoc_insertion_point(copy_constructor:MainSceneTable)
}
inline PROTOBUF_NDEBUG_INLINE MainSceneTable::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : nav_bin_file_(arena),
        _cached_size_{0} {}

inline void MainSceneTable::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.id_ = {};
}
MainSceneTable::~MainSceneTable() {
  // @@protoc_insertion_point(destructor:MainSceneTable)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void MainSceneTable::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.nav_bin_file_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
MainSceneTable::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(MainSceneTable, _impl_._cached_size_),
              false,
          },
          &MainSceneTable::MergeImpl,
          &MainSceneTable::kDescriptorMethods,
      };
  return &_data_;
}
PROTOBUF_NOINLINE void MainSceneTable::Clear() {
// @@protoc_insertion_point(message_clear_start:MainSceneTable)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.nav_bin_file_.ClearToEmpty();
  _impl_.id_ = 0u;
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* MainSceneTable::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 0, 35, 2> MainSceneTable::_table_ = {
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
    &_MainSceneTable_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::MainSceneTable>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // string nav_bin_file = 2;
    {::_pbi::TcParser::FastUS1,
     {18, 63, 0, PROTOBUF_FIELD_OFFSET(MainSceneTable, _impl_.nav_bin_file_)}},
    // uint32 id = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(MainSceneTable, _impl_.id_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(MainSceneTable, _impl_.id_)}},
  }}, {{
    65535, 65535
  }}, {{
    // uint32 id = 1;
    {PROTOBUF_FIELD_OFFSET(MainSceneTable, _impl_.id_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUInt32)},
    // string nav_bin_file = 2;
    {PROTOBUF_FIELD_OFFSET(MainSceneTable, _impl_.nav_bin_file_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\16\0\14\0\0\0\0\0"
    "MainSceneTable"
    "nav_bin_file"
  }},
};

::uint8_t* MainSceneTable::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:MainSceneTable)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // uint32 id = 1;
  if (this->_internal_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(
        1, this->_internal_id(), target);
  }

  // string nav_bin_file = 2;
  if (!this->_internal_nav_bin_file().empty()) {
    const std::string& _s = this->_internal_nav_bin_file();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "MainSceneTable.nav_bin_file");
    target = stream->WriteStringMaybeAliased(2, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:MainSceneTable)
  return target;
}

::size_t MainSceneTable::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:MainSceneTable)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string nav_bin_file = 2;
  if (!this->_internal_nav_bin_file().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_nav_bin_file());
  }

  // uint32 id = 1;
  if (this->_internal_id() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(
        this->_internal_id());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void MainSceneTable::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<MainSceneTable*>(&to_msg);
  auto& from = static_cast<const MainSceneTable&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:MainSceneTable)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_nav_bin_file().empty()) {
    _this->_internal_set_nav_bin_file(from._internal_nav_bin_file());
  }
  if (from._internal_id() != 0) {
    _this->_impl_.id_ = from._impl_.id_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void MainSceneTable::CopyFrom(const MainSceneTable& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:MainSceneTable)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool MainSceneTable::IsInitialized() const {
  return true;
}

void MainSceneTable::InternalSwap(MainSceneTable* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.nav_bin_file_, &other->_impl_.nav_bin_file_, arena);
        swap(_impl_.id_, other->_impl_.id_);
}

::google::protobuf::Metadata MainSceneTable::GetMetadata() const {
  return ::_pbi::AssignDescriptors(&descriptor_table_mainscene_5fconfig_2eproto_getter,
                                   &descriptor_table_mainscene_5fconfig_2eproto_once,
                                   file_level_metadata_mainscene_5fconfig_2eproto[0]);
}
// ===================================================================

class MainSceneTabledData::_Internal {
 public:
};

MainSceneTabledData::MainSceneTabledData(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:MainSceneTabledData)
}
inline PROTOBUF_NDEBUG_INLINE MainSceneTabledData::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : data_{visibility, arena, from.data_},
        _cached_size_{0} {}

MainSceneTabledData::MainSceneTabledData(
    ::google::protobuf::Arena* arena,
    const MainSceneTabledData& from)
    : ::google::protobuf::Message(arena) {
  MainSceneTabledData* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);

  // @@protoc_insertion_point(copy_constructor:MainSceneTabledData)
}
inline PROTOBUF_NDEBUG_INLINE MainSceneTabledData::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : data_{visibility, arena},
        _cached_size_{0} {}

inline void MainSceneTabledData::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
MainSceneTabledData::~MainSceneTabledData() {
  // @@protoc_insertion_point(destructor:MainSceneTabledData)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void MainSceneTabledData::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
MainSceneTabledData::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(MainSceneTabledData, _impl_._cached_size_),
              false,
          },
          &MainSceneTabledData::MergeImpl,
          &MainSceneTabledData::kDescriptorMethods,
      };
  return &_data_;
}
PROTOBUF_NOINLINE void MainSceneTabledData::Clear() {
// @@protoc_insertion_point(message_clear_start:MainSceneTabledData)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.data_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* MainSceneTabledData::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 1, 0, 2> MainSceneTabledData::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    1,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_MainSceneTabledData_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::MainSceneTabledData>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // repeated .MainSceneTable data = 1;
    {::_pbi::TcParser::FastMtR1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(MainSceneTabledData, _impl_.data_)}},
  }}, {{
    65535, 65535
  }}, {{
    // repeated .MainSceneTable data = 1;
    {PROTOBUF_FIELD_OFFSET(MainSceneTabledData, _impl_.data_), 0, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kMessage | ::_fl::kTvTable)},
  }}, {{
    {::_pbi::TcParser::GetTable<::MainSceneTable>()},
  }}, {{
  }},
};

::uint8_t* MainSceneTabledData::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:MainSceneTabledData)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // repeated .MainSceneTable data = 1;
  for (unsigned i = 0, n = static_cast<unsigned>(
                           this->_internal_data_size());
       i < n; i++) {
    const auto& repfield = this->_internal_data().Get(i);
    target =
        ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
            1, repfield, repfield.GetCachedSize(),
            target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:MainSceneTabledData)
  return target;
}

::size_t MainSceneTabledData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:MainSceneTabledData)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .MainSceneTable data = 1;
  total_size += 1UL * this->_internal_data_size();
  for (const auto& msg : this->_internal_data()) {
    total_size += ::google::protobuf::internal::WireFormatLite::MessageSize(msg);
  }
  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void MainSceneTabledData::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<MainSceneTabledData*>(&to_msg);
  auto& from = static_cast<const MainSceneTabledData&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:MainSceneTabledData)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_data()->MergeFrom(
      from._internal_data());
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void MainSceneTabledData::CopyFrom(const MainSceneTabledData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:MainSceneTabledData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool MainSceneTabledData::IsInitialized() const {
  return true;
}

void MainSceneTabledData::InternalSwap(MainSceneTabledData* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.data_.InternalSwap(&other->_impl_.data_);
}

::google::protobuf::Metadata MainSceneTabledData::GetMetadata() const {
  return ::_pbi::AssignDescriptors(&descriptor_table_mainscene_5fconfig_2eproto_getter,
                                   &descriptor_table_mainscene_5fconfig_2eproto_once,
                                   file_level_metadata_mainscene_5fconfig_2eproto[1]);
}
// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::std::false_type _static_init_ PROTOBUF_UNUSED =
    (::_pbi::AddDescriptors(&descriptor_table_mainscene_5fconfig_2eproto),
     ::std::false_type{});
#include "google/protobuf/port_undef.inc"
