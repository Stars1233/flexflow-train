#include "utils/json/variant.h"
#include <string>

namespace nlohmann {

template struct adl_serializer<std::variant<int, std::string>>;

} // namespace nlohmann
