#include "utils/containers/get_all_assignments.h"
#include "utils/archetypes/ordered_value_type.h"
#include "utils/archetypes/value_type.h"
#include "utils/hash/unordered_map.h"

namespace FlexFlow {

using K = ordered_value_type<0>;
using V = ordered_value_type<1>;

template std::unordered_set<std::unordered_map<K, V>>
    get_all_assignments(std::unordered_map<K, std::unordered_set<V>> const &);

template std::set<std::map<K, V>>
    get_all_assignments(std::map<K, std::set<V>> const &);

} // namespace FlexFlow
