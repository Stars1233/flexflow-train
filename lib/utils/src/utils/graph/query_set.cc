#include "utils/graph/query_set.h"
#include "utils/archetypes/jsonable_ordered_value_type.h"

namespace FlexFlow {

using T = jsonable_ordered_value_type<0>;

template struct query_set<T>;

template query_set<T> matchall();

template bool includes(query_set<T> const &, T const &);

template std::set<T> apply_query(query_set<T> const &, std::set<T> const &);

using K = jsonable_ordered_value_type<1>;
using V = jsonable_ordered_value_type<2>;

template std::map<K, V> query_keys(query_set<K> const &,
                                   std::map<K, V> const &);
template std::map<K, V> query_values(query_set<V> const &q,
                                     std::map<K, V> const &);

template query_set<T> query_intersection(query_set<T> const &,
                                         query_set<T> const &);

template query_set<T> query_union(query_set<T> const &, query_set<T> const &);

template void to_json(nlohmann::json &, query_set<T> const &);

} // namespace FlexFlow

namespace std {

using T = ::FlexFlow::jsonable_ordered_value_type<0>;

template struct hash<::FlexFlow::query_set<T>>;

} // namespace std
