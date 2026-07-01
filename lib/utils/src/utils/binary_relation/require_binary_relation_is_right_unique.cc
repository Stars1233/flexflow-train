#include "utils/binary_relation/require_binary_relation_is_right_unique.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using L = ordered_value_type<0>;
using R = ordered_value_type<1>;

template ManyToOne<L, R>
    require_binary_relation_is_right_unique(BinaryRelation<L, R> const &);

} // namespace FlexFlow
