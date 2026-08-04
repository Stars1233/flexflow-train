#include "utils/containers/slice_inclusive.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using T = value_type<0>;

template std::vector<T>
    slice_inclusive(std::vector<T> const &, int, std::optional<int> const &);

} // namespace FlexFlow
