#include "utils/containers/get_all_permutations_with_repetition.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using T = ordered_value_type<0>;

template std::multiset<std::vector<T>>
    get_all_permutations_with_repetition(std::vector<T> const &,
                                         nonnegative_int n);

} // namespace FlexFlow
