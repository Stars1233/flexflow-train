#include "utils/containers/unordered_multiset_of.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using T = value_type<0>;

template std::unordered_multiset<T>
    unordered_multiset_of(std::vector<T> const &);
template std::unordered_multiset<T>
    unordered_multiset_of(std::unordered_set<T> const &);

} // namespace FlexFlow
