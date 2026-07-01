#include "utils/bidict/algorithms/bidict_filter_keys.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using K = ordered_value_type<0>;
using V = ordered_value_type<1>;
using F = std::function<bool(K)>;

template bidict<K, V> bidict_filter_keys(bidict<K, V> const &, F &&);

} // namespace FlexFlow
