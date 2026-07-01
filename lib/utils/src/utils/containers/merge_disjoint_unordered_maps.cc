#include "utils/containers/merge_disjoint_unordered_maps.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using K = value_type<0>;
using V = value_type<1>;

template std::unordered_map<K, V> merge_disjoint_unordered_maps(
    std::vector<std::unordered_map<K, V>> const &);

} // namespace FlexFlow
