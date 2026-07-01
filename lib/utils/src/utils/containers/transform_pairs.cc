#include "utils/containers/transform_pairs.h"
#include "utils/archetypes/ordered_value_type.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using L = value_type<0>;
using R = value_type<1>;
using Out = value_type<2>;
using F = std::function<Out(L const &, R const &)>;

template std::vector<Out> transform_pairs(std::vector<std::pair<L, R>> const &,
                                          F &&);

using O_L = ordered_value_type<0>;
using O_R = ordered_value_type<1>;
using O_Out = ordered_value_type<2>;
using O_F = std::function<O_Out(O_L const &, O_R const &)>;

template std::set<O_Out> transform_pairs(std::set<std::pair<O_L, O_R>> const &,
                                         O_F &&);

} // namespace FlexFlow
