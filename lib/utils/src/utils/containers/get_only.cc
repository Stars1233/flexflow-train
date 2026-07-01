#include "utils/containers/get_only.h"
#include "utils/archetypes/ordered_value_type.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using T = value_type<0>;
using O_T = ordered_value_type<0>;

template T get_only(std::vector<T> const &);
template T get_only(std::unordered_set<T> const &);
template O_T get_only(std::set<O_T> const &);

using K = value_type<1>;
using V = value_type<2>;

template std::pair<K, V> get_only(std::unordered_map<K, V> const &);

using O_K = ordered_value_type<1>;

template std::pair<K, V> get_only(std::map<K, V> const &);

} // namespace FlexFlow
