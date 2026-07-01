#include "utils/graph/undirected/algorithms/get_connected_components.h"
#include "utils/graph/algorithms.h"
#include "utils/graph/node/algorithms.h"
#include "utils/hash/set.h"

namespace FlexFlow {

std::set<std::set<Node>>
    get_connected_components(UndirectedGraphView const &g) {
  std::set<std::set<Node>> components;
  std::set<Node> visited;

  for (Node const &node : get_nodes(g)) {
    std::set<Node> component = set_of(get_bfs_ordering(as_digraph(g), {node}));
    components.insert(component);
    visited = set_union(visited, component);
  }
  return components;
}

} // namespace FlexFlow
