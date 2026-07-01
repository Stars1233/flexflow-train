#include "utils/binary_relation/binary_relation_transform_left2.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using L = ordered_value_type<0>;
using L2 = ordered_value_type<1>;
using R = ordered_value_type<2>;
using F = std::function<L2(L const &, R const &)>;

template BinaryRelation<L2, R>
    binary_relation_transform_left2(BinaryRelation<L, R> const &, F &&);

} // namespace FlexFlow
