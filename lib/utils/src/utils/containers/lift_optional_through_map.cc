#include "utils/containers/lift_optional_through_map.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using K = ordered_value_type<0>;
using V = ordered_value_type<1>;

template std::optional<std::map<K, V>>
    lift_optional_through_map(std::map<K, std::optional<V>> const &);

} // namespace FlexFlow
