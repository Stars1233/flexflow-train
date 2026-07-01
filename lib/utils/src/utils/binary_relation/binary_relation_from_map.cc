#include "utils/binary_relation/binary_relation_from_map.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using L = ordered_value_type<0>;
using R = ordered_value_type<1>;

template BinaryRelation<L, R> binary_relation_from_map(std::map<L, R> const &);

} // namespace FlexFlow
