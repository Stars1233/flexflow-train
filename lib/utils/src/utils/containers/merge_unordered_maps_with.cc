#include "utils/archetypes/value_type.h"
#include "utils/containers/merge_maps_with.h"

namespace FlexFlow {

using K = value_type<0>;
using V = value_type<1>;
using F = std::function<V(V const &, V const &)>;

std::map<K, V> merge_maps_with(std::vector<std::map<K, V>> const &, F &&);

} // namespace FlexFlow
