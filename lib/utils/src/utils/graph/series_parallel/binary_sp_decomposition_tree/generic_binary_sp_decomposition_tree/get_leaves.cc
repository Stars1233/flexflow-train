#include "utils/graph/series_parallel/binary_sp_decomposition_tree/generic_binary_sp_decomposition_tree/get_leaves.h"
#include "utils/archetypes/ordered_value_type.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using Tree = value_type<0>;
using Series = ordered_value_type<1>;
using Parallel = ordered_value_type<2>;
using Leaf = ordered_value_type<3>;

template std::multiset<Leaf>
    get_leaves(Tree const &,
               GenericBinarySPDecompositionTreeImplementation<Tree,
                                                              Series,
                                                              Parallel,
                                                              Leaf> const &);

} // namespace FlexFlow
