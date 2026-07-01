#include "utils/archetypes/ordered_value_type.h"
#include "utils/archetypes/value_type.h"
#include "utils/containers/keys.h"

namespace FlexFlow {

using K = ordered_value_type<0>;
using V = value_type<1>;

template std::set<K> keys(std::map<K, V> const &);
std::set<K> keys(std::map<K, V> const &);

} // namespace FlexFlow
