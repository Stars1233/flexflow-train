#include "utils/containers/map_values2.h"
#include "utils/archetypes/ordered_value_type.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using K = value_type<0>;
using V1 = value_type<1>;
using V2 = value_type<2>;

template std::unordered_map<K, V2>
    map_values2(std::unordered_map<K, V1> const &,
                std::function<V2(K const &, V1 const &)> &&);

using O_K = ordered_value_type<0>;

template std::map<O_K, V2>
    map_values2(std::map<O_K, V1> const &,
                std::function<V2(O_K const &, V1 const &)> &&);

} // namespace FlexFlow
