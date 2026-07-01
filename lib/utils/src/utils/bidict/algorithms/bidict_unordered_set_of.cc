#include "utils/bidict/algorithms/bidict_unordered_set_of.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using K = ordered_value_type<0>;
using V = ordered_value_type<1>;

std::unordered_set<std::pair<K, V>>
    bidict_unordered_set_of(bidict<K, V> const &);

} // namespace FlexFlow
