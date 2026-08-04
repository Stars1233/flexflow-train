#include "op-attrs/ff_ordered/ff_ordered_enumerate.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using T = value_type<0>;

template std::map<ff_dim_t, T> ff_ordered_enumerate(FFOrdered<T> const &);

} // namespace FlexFlow
