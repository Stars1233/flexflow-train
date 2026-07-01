#include "utils/binary_relation/binary_relation_transform_right2.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using L = ordered_value_type<0>;
using R = ordered_value_type<1>;
using R2 = ordered_value_type<2>;
using F = std::function<R2(L const &, R const &)>;

template BinaryRelation<L, R2>
    binary_relation_transform_right2(BinaryRelation<L, R> const &, F &&);

} // namespace FlexFlow
