#include "utils/containers/map_keys2.h"
#include "utils/archetypes/ordered_value_type.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using K = ordered_value_type<0>;
using V = value_type<1>;
using K2 = ordered_value_type<2>;
using F = std::function<K2(K const &, V const &)>;

template std::map<K2, V> map_keys2(std::map<K, V> const &, F const &);

} // namespace FlexFlow
