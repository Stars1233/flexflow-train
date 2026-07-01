#include "utils/containers/extend_vector.h"
#include "utils/archetypes/value_type.h"
#include <set>

namespace FlexFlow {

using T = value_type<0>;

template void extend_vector(std::vector<T> &, std::set<T> const &);

} // namespace FlexFlow
