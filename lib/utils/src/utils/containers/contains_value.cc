#include "utils/containers/contains_value.h"
#include "utils/archetypes/ordered_value_type.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using K = value_type<0>;
using V = value_type<1>;

template bool contains_value(std::unordered_map<K, V> const &, V const &);

using O_K = ordered_value_type<0>;

template bool contains_value(std::map<O_K, V> const &, V const &);

} // namespace FlexFlow
