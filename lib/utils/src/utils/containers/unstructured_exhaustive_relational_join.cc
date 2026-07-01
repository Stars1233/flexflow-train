#include "utils/containers/unstructured_exhaustive_relational_join.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using L = ordered_value_type<0>;
using C = ordered_value_type<1>;
using R = ordered_value_type<2>;

template std::set<std::pair<L, R>>
    unstructured_exhaustive_relational_join(std::set<std::pair<L, C>> const &,
                                            std::set<std::pair<C, R>> const &);

} // namespace FlexFlow
