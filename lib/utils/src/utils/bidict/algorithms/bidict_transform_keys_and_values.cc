#include "utils/bidict/algorithms/bidict_transform_keys_and_values.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using K = ordered_value_type<0>;
using V = ordered_value_type<1>;
using K2 = ordered_value_type<2>;
using V2 = ordered_value_type<3>;
using KF = std::function<K2(K const &)>;
using VF = std::function<V2(V const &)>;

template bidict<K2, V2>
    bidict_transform_keys_and_values(bidict<K, V> const &, KF &&, VF &&);

} // namespace FlexFlow
