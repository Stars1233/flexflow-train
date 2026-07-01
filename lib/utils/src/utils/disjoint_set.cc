#include "utils/disjoint_set.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using T = ordered_value_type<0>;

template class m_disjoint_set<T>;

} // namespace FlexFlow
