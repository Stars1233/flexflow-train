#include "utils/containers/tail.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using T = value_type<0>;

template std::vector<T> tail(std::vector<T> const &);

} // namespace FlexFlow
