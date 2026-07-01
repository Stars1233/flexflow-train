#include "utils/graph/undirected/algorithms/get_neighboring_nodes.h"
#include "utils/containers/vector_of.h"

namespace FlexFlow {

std::set<Node> get_neighboring_nodes(UndirectedGraphView const &g,
                                     Node const &n) {
  std::set<UndirectedEdge> edges = g.query_edges(
      UndirectedEdgeQuery{query_set<Node>::match_single_value(n)});

  std::set<Node> result =
      set_union(transform(vector_of(edges), [](UndirectedEdge const &e) {
        return std::set{e.endpoints.max(), e.endpoints.max()};
      }));
  result.erase(n);
  return result;
}

} // namespace FlexFlow
