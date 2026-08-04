#include "utils/containers/find_index.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using T = value_type<0>;
using F = std::function<bool(T const &)>;

template std::optional<nonnegative_int> find_index(std::vector<T> const &,
                                                   F &&);

} // namespace FlexFlow
