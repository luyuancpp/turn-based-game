// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: logic/component/player_login_comp.proto
// Protobuf C++ Version: 5.26.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_logic_2fcomponent_2fplayer_5flogin_5fcomp_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_logic_2fcomponent_2fplayer_5flogin_5fcomp_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION != 5026001
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/generated_enum_reflection.h"
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_logic_2fcomponent_2fplayer_5flogin_5fcomp_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_logic_2fcomponent_2fplayer_5flogin_5fcomp_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_logic_2fcomponent_2fplayer_5flogin_5fcomp_2eproto;
class EnterGameNodeInfoPBComp;
struct EnterGameNodeInfoPBCompDefaultTypeInternal;
extern EnterGameNodeInfoPBCompDefaultTypeInternal _EnterGameNodeInfoPBComp_default_instance_;
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

enum EnterGsType : int {
  LOGIN_NONE = 0,
  LOGIN_FIRST = 1,
  LOGIN_REPLACE = 2,
  LOGIN_RECONNECT = 3,
  EnterGsType_INT_MIN_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::min(),
  EnterGsType_INT_MAX_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::max(),
};

bool EnterGsType_IsValid(int value);
extern const uint32_t EnterGsType_internal_data_[];
constexpr EnterGsType EnterGsType_MIN = static_cast<EnterGsType>(0);
constexpr EnterGsType EnterGsType_MAX = static_cast<EnterGsType>(3);
constexpr int EnterGsType_ARRAYSIZE = 3 + 1;
const ::google::protobuf::EnumDescriptor*
EnterGsType_descriptor();
template <typename T>
const std::string& EnterGsType_Name(T value) {
  static_assert(std::is_same<T, EnterGsType>::value ||
                    std::is_integral<T>::value,
                "Incorrect type passed to EnterGsType_Name().");
  return EnterGsType_Name(static_cast<EnterGsType>(value));
}
template <>
inline const std::string& EnterGsType_Name(EnterGsType value) {
  return ::google::protobuf::internal::NameOfDenseEnum<EnterGsType_descriptor,
                                                 0, 3>(
      static_cast<int>(value));
}
inline bool EnterGsType_Parse(absl::string_view name, EnterGsType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EnterGsType>(
      EnterGsType_descriptor(), name, value);
}

// ===================================================================


// -------------------------------------------------------------------

class EnterGameNodeInfoPBComp final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:EnterGameNodeInfoPBComp) */ {
 public:
  inline EnterGameNodeInfoPBComp() : EnterGameNodeInfoPBComp(nullptr) {}
  ~EnterGameNodeInfoPBComp() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR EnterGameNodeInfoPBComp(
      ::google::protobuf::internal::ConstantInitialized);

  inline EnterGameNodeInfoPBComp(const EnterGameNodeInfoPBComp& from) : EnterGameNodeInfoPBComp(nullptr, from) {}
  inline EnterGameNodeInfoPBComp(EnterGameNodeInfoPBComp&& from) noexcept
      : EnterGameNodeInfoPBComp(nullptr, std::move(from)) {}
  inline EnterGameNodeInfoPBComp& operator=(const EnterGameNodeInfoPBComp& from) {
    CopyFrom(from);
    return *this;
  }
  inline EnterGameNodeInfoPBComp& operator=(EnterGameNodeInfoPBComp&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const EnterGameNodeInfoPBComp& default_instance() {
    return *internal_default_instance();
  }
  static inline const EnterGameNodeInfoPBComp* internal_default_instance() {
    return reinterpret_cast<const EnterGameNodeInfoPBComp*>(
        &_EnterGameNodeInfoPBComp_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(EnterGameNodeInfoPBComp& a, EnterGameNodeInfoPBComp& b) { a.Swap(&b); }
  inline void Swap(EnterGameNodeInfoPBComp* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(EnterGameNodeInfoPBComp* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  EnterGameNodeInfoPBComp* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<EnterGameNodeInfoPBComp>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const EnterGameNodeInfoPBComp& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const EnterGameNodeInfoPBComp& from) { EnterGameNodeInfoPBComp::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(EnterGameNodeInfoPBComp* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "EnterGameNodeInfoPBComp"; }

 protected:
  explicit EnterGameNodeInfoPBComp(::google::protobuf::Arena* arena);
  EnterGameNodeInfoPBComp(::google::protobuf::Arena* arena, const EnterGameNodeInfoPBComp& from);
  EnterGameNodeInfoPBComp(::google::protobuf::Arena* arena, EnterGameNodeInfoPBComp&& from) noexcept
      : EnterGameNodeInfoPBComp(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kEnterGsTypeFieldNumber = 1,
  };
  // uint32 enter_gs_type = 1;
  void clear_enter_gs_type() ;
  ::uint32_t enter_gs_type() const;
  void set_enter_gs_type(::uint32_t value);

  private:
  ::uint32_t _internal_enter_gs_type() const;
  void _internal_set_enter_gs_type(::uint32_t value);

  public:
  // @@protoc_insertion_point(class_scope:EnterGameNodeInfoPBComp)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 0,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from);
    ::uint32_t enter_gs_type_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_logic_2fcomponent_2fplayer_5flogin_5fcomp_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// EnterGameNodeInfoPBComp

// uint32 enter_gs_type = 1;
inline void EnterGameNodeInfoPBComp::clear_enter_gs_type() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.enter_gs_type_ = 0u;
}
inline ::uint32_t EnterGameNodeInfoPBComp::enter_gs_type() const {
  // @@protoc_insertion_point(field_get:EnterGameNodeInfoPBComp.enter_gs_type)
  return _internal_enter_gs_type();
}
inline void EnterGameNodeInfoPBComp::set_enter_gs_type(::uint32_t value) {
  _internal_set_enter_gs_type(value);
  // @@protoc_insertion_point(field_set:EnterGameNodeInfoPBComp.enter_gs_type)
}
inline ::uint32_t EnterGameNodeInfoPBComp::_internal_enter_gs_type() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.enter_gs_type_;
}
inline void EnterGameNodeInfoPBComp::_internal_set_enter_gs_type(::uint32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.enter_gs_type_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


namespace google {
namespace protobuf {

template <>
struct is_proto_enum<::EnterGsType> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::EnterGsType>() {
  return ::EnterGsType_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_logic_2fcomponent_2fplayer_5flogin_5fcomp_2eproto_2epb_2eh