#include "utils/graph/kwarg_dataflow_graph/algorithms/dataflow_graph_from_kwarg_dataflow_graph.h"
#include "utils/archetypes/jsonable_ordered_value_type.h"

namespace FlexFlow {

using SlotName = jsonable_ordered_value_type<0>;

template DataflowGraphView dataflow_graph_from_kwarg_dataflow_graph(
    KwargDataflowGraphView<SlotName> const &,
    std::function<std::vector<SlotName>(std::set<SlotName> const &)> const &);

} // namespace FlexFlow
