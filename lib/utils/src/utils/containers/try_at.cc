#include "utils/containers/try_at.h"
#include "utils/archetypes/ordered_value_type.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using O_K = ordered_value_type<0>;
using K = value_type<0>;
using V = value_type<1>;

template std::optional<V> try_at(std::unordered_map<K, V> const &, K const &);

template std::optional<V> try_at(std::map<O_K, V> const &, O_K const &);

} // namespace FlexFlow
