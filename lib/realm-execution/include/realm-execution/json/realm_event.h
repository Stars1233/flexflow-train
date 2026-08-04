#ifndef _FLEXFLOW_LIB_REALM_EXECUTION_INCLUDE_REALM_EXECUTION_JSON_REALM_EVENT_H
#define _FLEXFLOW_LIB_REALM_EXECUTION_INCLUDE_REALM_EXECUTION_JSON_REALM_EVENT_H

#include "realm-execution/realm.h"
#include <nlohmann/json.hpp>

namespace nlohmann {

template <>
struct adl_serializer<::FlexFlow::Realm::Event> {
  static void to_json(json &, ::FlexFlow::Realm::Event const &);
};

} // namespace nlohmann

#endif
