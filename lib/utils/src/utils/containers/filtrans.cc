#include "utils/containers/filtrans.h"
#include "utils/archetypes/ordered_value_type.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using In = value_type<0>;
using Out = value_type<1>;
using F = std::function<std::optional<Out>(In const &)>;

template std::vector<Out> filtrans(std::vector<In> const &, F &&);
template std::unordered_set<Out> filtrans(std::unordered_set<In> const &, F &&);
template std::unordered_multiset<Out>
    filtrans(std::unordered_multiset<In> const &, F &&);

using O_In = ordered_value_type<0>;
using O_Out = ordered_value_type<0>;
using O_F = std::function<std::optional<O_Out>(O_In const &)>;

template std::set<O_Out> filtrans(std::set<O_In> const &, O_F &&);
template std::multiset<O_Out> filtrans(std::multiset<O_In> const &, O_F &&);

} // namespace FlexFlow
