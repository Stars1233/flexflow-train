#include "utils/bidict/algorithms/bidict_from_keys_and_values.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using L = ordered_value_type<0>;
using R = ordered_value_type<1>;

template bidict<L, R> bidict_from_keys_and_values(std::vector<L> const &,
                                                  std::vector<R> const &);

} // namespace FlexFlow
