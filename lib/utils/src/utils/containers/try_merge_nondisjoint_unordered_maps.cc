#include "utils/containers/try_merge_nondisjoint_unordered_maps.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using K = value_type<0>;
using V = value_type<1>;

template std::optional<std::unordered_map<K, V>>
    try_merge_nondisjoint_unordered_maps(std::unordered_map<K, V> const &,
                                         std::unordered_map<K, V> const &);

} // namespace FlexFlow
