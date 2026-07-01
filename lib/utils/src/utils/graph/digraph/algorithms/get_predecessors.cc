#include "utils/graph/digraph/algorithms/get_predecessors.h"
#include "utils/containers/map_values.h"
#include "utils/containers/transform.h"
#include "utils/graph/digraph/algorithms/get_incoming_edges.h"
#include "utils/graph/node/algorithms.h"

namespace FlexFlow {

std::map<Node, std::set<Node>> get_predecessors(DiGraphView const &g) {
  return get_predecessors(g, get_nodes(g));
}

std::set<Node> get_predecessors(DiGraphView const &g, Node const &n) {
  return get_predecessors(g, std::set<Node>{n}).at(n);
}

std::map<Node, std::set<Node>> get_predecessors(DiGraphView const &g,
                                                std::set<Node> const &ns) {
  return map_values(
      get_incoming_edges(g, ns), [](std::set<DirectedEdge> const &es) {
        return transform(es, [](DirectedEdge const &e) { return e.src; });
      });
}

} // namespace FlexFlow
