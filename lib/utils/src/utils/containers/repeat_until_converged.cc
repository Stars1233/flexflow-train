#include "utils/containers/repeat_until_converged.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using T = value_type<0>;
using F = std::function<T(T const &)>;

template T repeat_until_converged(T const &, F &&);

} // namespace FlexFlow
