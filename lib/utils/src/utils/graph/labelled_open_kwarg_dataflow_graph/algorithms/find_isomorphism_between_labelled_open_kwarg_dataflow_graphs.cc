#include "utils/graph/labelled_open_kwarg_dataflow_graph/algorithms/find_isomorphism_between_labelled_open_kwarg_dataflow_graphs.h"
#include "utils/archetypes/jsonable_ordered_value_type.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using NodeLabel = value_type<0>;
using ValueLabel = value_type<1>;
using GraphInputName = jsonable_ordered_value_type<2>;
using SlotName = jsonable_ordered_value_type<3>;

template std::optional<OpenKwargDataflowGraphIsomorphism<GraphInputName>>
    find_isomorphism_between_labelled_open_kwarg_dataflow_graphs(
        LabelledOpenKwargDataflowGraphView<NodeLabel,
                                           ValueLabel,
                                           GraphInputName,
                                           SlotName> const &,
        LabelledOpenKwargDataflowGraphView<NodeLabel,
                                           ValueLabel,
                                           GraphInputName,
                                           SlotName> const &);

} // namespace FlexFlow
