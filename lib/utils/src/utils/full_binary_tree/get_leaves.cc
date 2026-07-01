#include "utils/full_binary_tree/get_leaves.h"
#include "utils/archetypes/ordered_value_type.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using Tree = value_type<0>;
using Parent = value_type<1>;
using Leaf = ordered_value_type<2>;

template std::multiset<Leaf>
    get_leaves(Tree const &,
               FullBinaryTreeImplementation<Tree, Parent, Leaf> const &);

} // namespace FlexFlow
