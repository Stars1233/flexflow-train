#include "utils/containers/iterate_n.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using T = value_type<0>;
using F = std::function<T(T const &)>;

template std::vector<T> iterate_n(nonnegative_int, T const &, F &&);

} // namespace FlexFlow
