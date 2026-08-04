#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_FMT_MAP_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_FMT_MAP_H

#include "utils/fmt/pair.h"
#include "utils/join_strings.h"
#include "utils/json/check_is_json_serializable.h"
#include <fmt/format.h>
#include <map>
#include <nlohmann/json.hpp>

namespace fmt {

template <typename K, typename V, typename Char>
struct formatter<
    ::std::map<K, V>,
    Char,
    std::enable_if_t<!detail::has_format_as<::std::map<K, V>>::value>>
    : formatter<::std::string> {
  template <typename FormatContext>
  auto format(::std::map<K, V> const &m, FormatContext &ctx) const
      -> decltype(ctx.out()) {
    CHECK_IS_JSON_SERIALIZABLE(K);
    CHECK_IS_JSON_SERIALIZABLE(V);

    ::nlohmann::json j = m;
    return formatter<std::string>::format(j.dump(), ctx);
  }
};

} // namespace fmt

namespace FlexFlow {

template <typename K, typename V>
std::ostream &operator<<(std::ostream &s, std::map<K, V> const &m) {
  CHECK_IS_JSON_SERIALIZABLE(K);
  CHECK_IS_JSON_SERIALIZABLE(V);

  return s << fmt::to_string(m);
}

} // namespace FlexFlow

#endif
