#include "utils/graph/labelled_open_kwarg_dataflow_graph/algorithms/labelled_open_kwarg_dataflow_graph_view_as_dot.h"
#include "utils/archetypes/jsonable_ordered_value_type.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using NodeLabel = value_type<0>;
using ValueLabel = value_type<1>;
using GraphInputName = jsonable_ordered_value_type<2>;
using SlotName = jsonable_ordered_value_type<3>;

template std::string labelled_open_kwarg_dataflow_graph_view_as_dot(
    LabelledOpenKwargDataflowGraphView<NodeLabel,
                                       ValueLabel,
                                       GraphInputName,
                                       SlotName> const &,
    std::function<nlohmann::json(NodeLabel const &)> const &,
    std::function<nlohmann::json(ValueLabel const &)> const &,
    std::function<nlohmann::json(SlotName const &)> const &,
    std::function<std::vector<SlotName>(std::set<SlotName> const &)> const &);

} // namespace FlexFlow
