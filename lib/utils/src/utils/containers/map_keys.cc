#include "utils/containers/map_keys.h"
#include "utils/archetypes/ordered_value_type.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using K1 = value_type<0>;
using K2 = value_type<1>;
using V = value_type<2>;

template std::unordered_map<K2, V> map_keys(std::unordered_map<K1, V> const &,
                                            std::function<K2(K1 const &)> &&);

using O_K1 = ordered_value_type<0>;
using O_K2 = ordered_value_type<1>;

template std::map<O_K2, V> map_keys(std::map<O_K1, V> const &m,
                                    std::function<O_K2(O_K1 const &)> &&);

} // namespace FlexFlow
