#include "op-attrs/ff_ordered/ff_ordered_get_idxs.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using T = value_type<0>;

template std::set<ff_dim_t> ff_ordered_get_idxs(FFOrdered<T> const &);

} // namespace FlexFlow
