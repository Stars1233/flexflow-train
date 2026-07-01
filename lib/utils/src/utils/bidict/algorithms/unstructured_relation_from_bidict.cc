#include "utils/bidict/algorithms/unstructured_relation_from_bidict.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using L = ordered_value_type<0>;
using R = ordered_value_type<1>;

template std::set<std::pair<L, R>>
    unstructured_relation_from_bidict(bidict<L, R> const &);

} // namespace FlexFlow
