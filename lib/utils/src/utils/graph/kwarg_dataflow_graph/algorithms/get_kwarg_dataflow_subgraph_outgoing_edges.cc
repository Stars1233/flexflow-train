#include "utils/graph/kwarg_dataflow_graph/algorithms/get_kwarg_dataflow_subgraph_outgoing_edges.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using SlotName = ordered_value_type<0>;

template std::set<KwargDataflowEdge<SlotName>>
    get_kwarg_dataflow_subgraph_outgoing_edges(
        KwargDataflowGraphView<SlotName> const &, std::set<Node> const &);

} // namespace FlexFlow
