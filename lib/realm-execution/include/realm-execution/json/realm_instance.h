#ifndef _FLEXFLOW_LIB_REALM_EXECUTION_INCLUDE_REALM_EXECUTION_JSON_REALM_INSTANCE_H
#define _FLEXFLOW_LIB_REALM_EXECUTION_INCLUDE_REALM_EXECUTION_JSON_REALM_INSTANCE_H

#include "realm-execution/realm.h"
#include <nlohmann/json.hpp>

namespace nlohmann {

template <>
struct adl_serializer<::FlexFlow::Realm::RegionInstance> {
  static void to_json(json &, ::FlexFlow::Realm::RegionInstance const &);
};

} // namespace nlohmann

#endif
