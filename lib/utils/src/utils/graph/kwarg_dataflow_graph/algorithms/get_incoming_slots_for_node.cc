#include "utils/graph/kwarg_dataflow_graph/algorithms/get_incoming_slots_for_node.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using SlotName = ordered_value_type<0>;

template std::set<SlotName>
    get_incoming_slots_for_node(KwargDataflowGraphView<SlotName> const &, Node);

} // namespace FlexFlow
