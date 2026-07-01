#include "utils/containers/invert_map.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using O_K = ordered_value_type<0>;
using O_V = ordered_value_type<1>;

template std::map<O_V, std::set<O_K>> invert_map(std::map<O_K, O_V> const &);

} // namespace FlexFlow
