#include "utils/containers/at_idx.h"
#include "utils/archetypes/ordered_value_type.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using E = value_type<0>;

template E at_idx(std::vector<E> const &, nonnegative_int);

using O_E = ordered_value_type<0>;

template O_E at_idx(std::set<O_E> const &, nonnegative_int);

} // namespace FlexFlow
