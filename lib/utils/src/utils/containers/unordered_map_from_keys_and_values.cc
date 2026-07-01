#include "utils/containers/unordered_map_from_keys_and_values.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using K = value_type<0>;
using V = value_type<1>;

template std::unordered_map<K, V>
    unordered_map_from_keys_and_values(std::vector<K> const &,
                                       std::vector<V> const &);

} // namespace FlexFlow
