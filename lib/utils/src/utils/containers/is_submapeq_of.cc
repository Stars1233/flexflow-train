#include "utils/containers/is_submapeq_of.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using K = value_type<0>;
using V = value_type<1>;

bool is_submapeq_of(std::map<K, V> const &, std::map<K, V> const &);

} // namespace FlexFlow
