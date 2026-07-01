#include "utils/bidict/algorithms/bidict_filtrans_keys.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using K = ordered_value_type<0>;
using V = ordered_value_type<1>;
using K2 = ordered_value_type<2>;
using F = std::function<std::optional<K2>(K)>;

template bidict<K2, V> bidict_filtrans_keys(bidict<K, V> const &, F &&);

} // namespace FlexFlow
