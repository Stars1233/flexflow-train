#include "utils/containers/slice.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using T = value_type<0>;

template std::vector<T>
    slice(std::vector<T> const &, int, std::optional<int> const &);

} // namespace FlexFlow
