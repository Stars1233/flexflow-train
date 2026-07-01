#include "utils/bidict/algorithms/bidict_from_unstructured_relation.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using L = ordered_value_type<0>;
using R = ordered_value_type<1>;

template bidict<L, R>
    bidict_from_unstructured_relation(std::set<std::pair<L, R>> const &);

} // namespace FlexFlow
