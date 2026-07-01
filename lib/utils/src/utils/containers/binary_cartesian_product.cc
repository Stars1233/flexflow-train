#include "utils/containers/binary_cartesian_product.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using A = ordered_value_type<0>;
using B = ordered_value_type<1>;

template std::set<std::pair<A, B>>
    binary_cartesian_product(std::set<A> const &, std::set<B> const &);

} // namespace FlexFlow
