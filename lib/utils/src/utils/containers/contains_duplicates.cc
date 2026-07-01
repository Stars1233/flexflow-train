#include "utils/containers/contains_duplicates.h"
#include "utils/archetypes/ordered_value_type.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using T = value_type<0>;
using O_T = ordered_value_type<0>;

template bool contains_duplicates(std::vector<T> const &);

template bool contains_duplicates(std::unordered_multiset<T> const &);

template bool contains_duplicates(std::multiset<O_T> const &);

} // namespace FlexFlow
