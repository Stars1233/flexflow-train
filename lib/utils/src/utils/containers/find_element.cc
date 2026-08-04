#include "utils/containers/find_element.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using T = value_type<0>;
using F = std::function<bool(T const &)>;

template std::optional<T> find_element(std::vector<T> const &, F &&);

} // namespace FlexFlow
