#include "realm-execution/json/realm_instance.h"

namespace nlohmann {

void adl_serializer<::FlexFlow::Realm::RegionInstance>::to_json(
    json &j, ::FlexFlow::Realm::RegionInstance const &i) {
  j["__type"] = "Realm::RegionInstance";
  j["id"] = i.id;
}

} // namespace nlohmann
