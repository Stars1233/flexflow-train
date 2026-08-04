#include "utils/containers/are_all_distinct.h"
#include "utils/archetypes/ordered_value_type.h"
#include <vector>

namespace FlexFlow {

using T = ordered_value_type<0>;

template bool are_all_distinct(std::vector<T> const &);

} // namespace FlexFlow
