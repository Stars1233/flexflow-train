#include "utils/containers/lookup_in_map.h"
#include "utils/archetypes/ordered_value_type.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using K = ordered_value_type<0>;
using V = value_type<1>;

template std::function<V(K const &)> lookup_in_map(std::map<K, V> const &map);

} // namespace FlexFlow
