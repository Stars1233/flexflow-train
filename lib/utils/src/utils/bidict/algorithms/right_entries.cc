#include "utils/bidict/algorithms/right_entries.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using L = ordered_value_type<0>;
using R = ordered_value_type<1>;

template std::set<R> right_entries(bidict<L, R> const &);

} // namespace FlexFlow
