#include "utils/graph/open_kwarg_dataflow_graph/algorithms/find_isomorphisms_between_open_kwarg_dataflow_graphs.h"
#include "utils/archetypes/jsonable_ordered_value_type.h"

namespace FlexFlow {

using GraphInputName = jsonable_ordered_value_type<0>;
using SlotName = jsonable_ordered_value_type<1>;

template std::set<OpenKwargDataflowGraphIsomorphism<GraphInputName>>
    find_isomorphisms_between_open_kwarg_dataflow_graphs(
        OpenKwargDataflowGraphView<GraphInputName, SlotName> const &,
        OpenKwargDataflowGraphView<GraphInputName, SlotName> const &);

} // namespace FlexFlow
