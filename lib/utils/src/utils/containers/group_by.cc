#include "utils/containers/group_by.h"
#include "utils/archetypes/ordered_value_type.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using K = ordered_value_type<0>;
using V = ordered_value_type<1>;
using F = std::function<K(V)>;

template OneToMany<K, V> group_by(std::set<V> const &, F &&);
template OneToMany<K, V> group_by(std::unordered_set<V> const &, F &&);

template std::map<K, std::vector<V>> group_by(std::vector<V> const &, F &&);

} // namespace FlexFlow
