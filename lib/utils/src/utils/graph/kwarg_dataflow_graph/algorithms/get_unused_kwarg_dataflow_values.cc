#include "utils/graph/kwarg_dataflow_graph/algorithms/get_unused_kwarg_dataflow_values.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using SlotName = ordered_value_type<0>;

template std::set<KwargDataflowOutput<SlotName>>
    get_unused_kwarg_dataflow_values(KwargDataflowGraphView<SlotName> const &);

} // namespace FlexFlow
