#include "utils/bidict/algorithms/bidict_filter_values.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using K = ordered_value_type<0>;
using V = ordered_value_type<1>;
using F = std::function<bool(V)>;

template bidict<K, V> bidict_filter_values(bidict<K, V> const &, F &&);

} // namespace FlexFlow
