#include "op-attrs/ff_ordered/ff_ordered_reversed.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using T = value_type<0>;

template FFOrdered<T> ff_ordered_reversed(FFOrdered<T> const &);

} // namespace FlexFlow
