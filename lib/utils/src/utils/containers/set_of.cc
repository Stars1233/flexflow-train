#include "utils/containers/set_of.h"
#include "utils/archetypes/ordered_value_type.h"
#include <unordered_set>

namespace FlexFlow {

using T = ordered_value_type<0>;

template std::set<T> set_of(std::vector<T> const &);
template std::set<T> set_of(std::multiset<T> const &);
template std::set<T> set_of(std::unordered_set<T> const &);

using K = ordered_value_type<0>;
using V = ordered_value_type<1>;

template std::set<std::pair<K, V>> set_of(std::map<K, V> const &);

} // namespace FlexFlow
