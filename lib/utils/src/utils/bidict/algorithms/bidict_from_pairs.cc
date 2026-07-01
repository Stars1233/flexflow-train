#include "utils/bidict/algorithms/bidict_from_pairs.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using L = ordered_value_type<0>;
using R = ordered_value_type<1>;

template bidict<L, R> bidict_from_pairs(std::vector<std::pair<L, R>> const &);

} // namespace FlexFlow
