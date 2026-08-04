#ifndef _FLEXFLOW_LIB_REALM_EXECUTION_INCLUDE_REALM_EXECUTION_FMT_INSTANCE_H
#define _FLEXFLOW_LIB_REALM_EXECUTION_INCLUDE_REALM_EXECUTION_FMT_INSTANCE_H

#include "realm-execution/json/realm_event.h"
#include "realm-execution/realm.h"
#include <fmt/format.h>
#include <utility>

namespace fmt {

template <typename Char>
struct formatter<
    ::FlexFlow::Realm::Event,
    Char,
    std::enable_if_t<!detail::has_format_as<::FlexFlow::Realm::Event>::value>>
    : formatter<::std::string> {
  template <typename FormatContext>
  auto format(::FlexFlow::Realm::Event const &m, FormatContext &ctx)
      -> decltype(ctx.out()) {
    ::nlohmann::json j = m;

    return formatter<std::string>::format(j.dump(), ctx);
  }
};

} // namespace fmt

namespace FlexFlow {

std::ostream &operator<<(std::ostream &s, ::FlexFlow::Realm::Event const &m);

} // namespace FlexFlow

#endif
