// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: bag_operator.proto
// Protobuf C++ Version: 5.26.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_bag_5foperator_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_bag_5foperator_2eproto_2epb_2eh

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
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/generated_enum_reflection.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_bag_5foperator_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_bag_5foperator_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_bag_5foperator_2eproto;
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

enum bag : int {
  kBagOK = 0,
  kUseItem = 1,
  kActivityRewardItem = 2,
  kMissionRewardItem = 3,
  bag_INT_MIN_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::min(),
  bag_INT_MAX_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::max(),
};

bool bag_IsValid(int value);
extern const uint32_t bag_internal_data_[];
constexpr bag bag_MIN = static_cast<bag>(0);
constexpr bag bag_MAX = static_cast<bag>(3);
constexpr int bag_ARRAYSIZE = 3 + 1;
const ::google::protobuf::EnumDescriptor*
bag_descriptor();
template <typename T>
const std::string& bag_Name(T value) {
  static_assert(std::is_same<T, bag>::value ||
                    std::is_integral<T>::value,
                "Incorrect type passed to bag_Name().");
  return bag_Name(static_cast<bag>(value));
}
template <>
inline const std::string& bag_Name(bag value) {
  return ::google::protobuf::internal::NameOfDenseEnum<bag_descriptor,
                                                 0, 3>(
      static_cast<int>(value));
}
inline bool bag_Parse(absl::string_view name, bag* value) {
  return ::google::protobuf::internal::ParseNamedEnum<bag>(
      bag_descriptor(), name, value);
}

// ===================================================================



// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


namespace google {
namespace protobuf {

template <>
struct is_proto_enum<::bag> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::bag>() {
  return ::bag_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_bag_5foperator_2eproto_2epb_2eh
