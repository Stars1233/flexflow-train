#include "utils/many_to_one/many_to_one_from_bidict.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using L = ordered_value_type<0>;
using R = ordered_value_type<1>;

template ManyToOne<L, R> many_to_one_from_bidict(bidict<L, R> const &);

} // namespace FlexFlow
