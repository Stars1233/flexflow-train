#include "utils/bidict/algorithms/bidict_transform_values.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using K = ordered_value_type<0>;
using V = ordered_value_type<1>;
using V2 = ordered_value_type<2>;
using F = std::function<V2(V)>;

template bidict<K, V2> bidict_transform_values(bidict<K, V> const &, F &&);

} // namespace FlexFlow
