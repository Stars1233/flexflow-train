#include "realm-execution/json/realm_event.h"

namespace nlohmann {

void adl_serializer<::FlexFlow::Realm::Event>::to_json(
    json &j, ::FlexFlow::Realm::Event const &e) {
  j["__type"] = "Realm::Event";
  j["id"] = e.id;
}

} // namespace nlohmann
