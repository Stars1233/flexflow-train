#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_GRAPH_KWARG_DATAFLOW_GRAPH_ALGORITHMS_GET_UNUSED_KWARG_DATAFLOW_VALUES_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_GRAPH_KWARG_DATAFLOW_GRAPH_ALGORITHMS_GET_UNUSED_KWARG_DATAFLOW_VALUES_H

#include "utils/graph/kwarg_dataflow_graph/algorithms/get_all_kwarg_dataflow_outputs.h"
#include "utils/graph/kwarg_dataflow_graph/algorithms/get_kwarg_dataflow_value_uses.h"

namespace FlexFlow {

template <typename SlotName>
std::set<KwargDataflowOutput<SlotName>> get_unused_kwarg_dataflow_values(
    KwargDataflowGraphView<SlotName> const &g) {
  return filter(get_all_kwarg_dataflow_outputs(g),
                [&](KwargDataflowOutput<SlotName> const &o) {
                  return get_kwarg_dataflow_value_uses(g, o).empty();
                });
}

} // namespace FlexFlow

#endif
