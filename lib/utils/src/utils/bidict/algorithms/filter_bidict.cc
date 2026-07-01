#include "utils/bidict/algorithms/filter_bidict.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using L = ordered_value_type<0>;
using R = ordered_value_type<1>;
using F = std::function<bool(L const &, R const &)>;

template bidict<L, R> filter_bidict(bidict<L, R> const &, F &&);

} // namespace FlexFlow
