#include "utils/containers/contains_key.h"
#include "utils/archetypes/ordered_value_type.h"
#include "utils/archetypes/value_type.h"
#include <map>
#include <unordered_map>

namespace FlexFlow {

using K = value_type<0>;
using O_K = ordered_value_type<0>;
using V = value_type<1>;

template bool contains_key(std::map<O_K, V> const &, O_K const &);
template bool contains_key(std::unordered_map<K, V> const &, K const &);

} // namespace FlexFlow
