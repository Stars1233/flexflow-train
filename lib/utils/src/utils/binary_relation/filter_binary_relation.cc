#include "utils/binary_relation/filter_binary_relation.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using L = ordered_value_type<0>;
using R = ordered_value_type<1>;
using F = std::function<bool(L const &, R const &)>;

template BinaryRelation<L, R>
    filter_binary_relation(BinaryRelation<L, R> const &, F &&);

} // namespace FlexFlow
