#include "utils/containers/unordered_map_from_pairs.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using K = value_type<0>;
using V = value_type<1>;

template std::unordered_map<K, V>
    unordered_map_from_pairs(std::vector<std::pair<K, V>> const &);

} // namespace FlexFlow
