#include "utils/graph/open_kwarg_dataflow_graph/algorithms/get_all_open_kwarg_dataflow_edges.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using GraphInputName = ordered_value_type<0>;
using SlotName = ordered_value_type<1>;

template std::set<OpenKwargDataflowEdge<GraphInputName, SlotName>>
    get_all_open_kwarg_dataflow_edges(
        OpenKwargDataflowGraphView<GraphInputName, SlotName> const &);

} // namespace FlexFlow
