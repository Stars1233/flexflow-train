#include "utils/containers/set_union.h"
#include "utils/archetypes/ordered_value_type.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using T = value_type<0>;

template std::unordered_set<T> set_union(std::unordered_set<T> const &,
                                         std::unordered_set<T> const &);

using O_T = ordered_value_type<0>;

template std::set<O_T> set_union(std::set<O_T> const &, std::set<O_T> const &);

template std::set<O_T> set_union(std::vector<std::set<O_T>> const &);

} // namespace FlexFlow
