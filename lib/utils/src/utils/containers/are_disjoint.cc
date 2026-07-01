#include "utils/containers/are_disjoint.h"
#include "utils/archetypes/ordered_value_type.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using T = value_type<0>;

template bool are_disjoint(std::unordered_set<T> const &,
                           std::unordered_set<T> const &);

using R = ordered_value_type<0>;

template bool are_disjoint(std::set<R> const &, std::set<R> const &);

} // namespace FlexFlow
