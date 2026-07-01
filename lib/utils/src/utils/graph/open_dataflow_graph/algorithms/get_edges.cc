#include "utils/graph/open_dataflow_graph/algorithms/get_edges.h"
#include "utils/graph/open_dataflow_graph/open_dataflow_edge_query.h"

namespace FlexFlow {

std::set<OpenDataflowEdge> get_edges(OpenDataflowGraphView const &g) {
  return g.query_edges(open_dataflow_edge_query_all());
}

} // namespace FlexFlow
