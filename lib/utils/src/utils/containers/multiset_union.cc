#include "utils/containers/multiset_union.h"
#include "utils/archetypes/ordered_value_type.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using T = value_type<0>;

template std::unordered_multiset<T>
    multiset_union(std::unordered_multiset<T> const &,
                   std::unordered_multiset<T> const &);

using O_T = ordered_value_type<0>;

template std::multiset<O_T> multiset_union(std::multiset<O_T> const &,
                                           std::multiset<O_T> const &);

template std::multiset<O_T>
    multiset_union(std::vector<std::multiset<O_T>> const &);

} // namespace FlexFlow
