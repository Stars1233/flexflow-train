#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_GRAPH_KWARG_DATAFLOW_GRAPH_ALGORITHMS_KWARG_DATAFLOW_GRAPH_DATA_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_GRAPH_KWARG_DATAFLOW_GRAPH_ALGORITHMS_KWARG_DATAFLOW_GRAPH_DATA_H

#include "utils/containers/flatmap.h"
#include "utils/containers/is_subseteq_of.h"
#include "utils/containers/transform.h"
#include "utils/graph/kwarg_dataflow_graph/algorithms/kwarg_dataflow_graph_data.dtg.h"
#include <optional>

namespace FlexFlow {

template <typename SlotName>
void require_kwarg_dataflow_graph_data_is_valid(
    KwargDataflowGraphData<SlotName> const &data) {

  std::set<Node> nodes_from_edges = flatmap(
      data.edges, [](KwargDataflowEdge<SlotName> const &e) -> std::set<Node> {
        return std::set{
            e.src.node,
            e.dst.node,
        };
      });

  ASSERT(is_subseteq_of(nodes_from_edges, data.nodes));

  std::set<Node> nodes_from_outputs = transform(
      data.outputs,
      [](KwargDataflowOutput<SlotName> const &o) -> Node { return o.node; });

  ASSERT(is_subseteq_of(nodes_from_outputs, data.nodes));

  std::set<KwargDataflowOutput<SlotName>> outputs_from_edges =
      transform(data.edges,
                [](KwargDataflowEdge<SlotName> const &e)
                    -> KwargDataflowOutput<SlotName> { return e.src; });

  ASSERT(is_subseteq_of(outputs_from_edges, data.outputs));
}

} // namespace FlexFlow

#endif
