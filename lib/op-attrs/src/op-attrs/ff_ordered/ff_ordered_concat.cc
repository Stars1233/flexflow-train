#include "op-attrs/ff_ordered/ff_ordered_concat.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using T = value_type<0>;

template FFOrdered<T> ff_ordered_concat(FFOrdered<T> const &,
                                        FFOrdered<T> const &);

template FFOrdered<T> ff_ordered_concat(std::vector<FFOrdered<T>> const &);

} // namespace FlexFlow
