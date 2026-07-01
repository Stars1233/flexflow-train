#include "utils/graph/digraph/algorithms/complete_bipartite_composite/complete_bipartite_composite_decomposition.h"
#include "utils/containers/contains.h"
#include "utils/containers/filter.h"
#include "utils/containers/maybe_get_only.h"
#include "utils/containers/transform.h"
#include "utils/hash/set.h"
#include <cassert>

namespace FlexFlow {

std::optional<BipartiteComponent> get_component_containing_node_in_head(
    CompleteBipartiteCompositeDecomposition const &cbc, Node const &n) {
  std::set<BipartiteComponent> found =
      filter(cbc.subgraphs, [&](BipartiteComponent const &bc) {
        return contains(bc.head_nodes, n);
      });
  assert(found.size() <= 1);
  return maybe_get_only(found);
}

std::optional<BipartiteComponent> get_component_containing_node_in_tail(
    CompleteBipartiteCompositeDecomposition const &cbc, Node const &n) {
  std::set<BipartiteComponent> found =
      filter(cbc.subgraphs, [&](BipartiteComponent const &bc) {
        return contains(bc.tail_nodes, n);
      });
  assert(found.size() <= 1);
  return maybe_get_only(found);
}

std::set<std::set<Node>>
    get_head_subcomponents(CompleteBipartiteCompositeDecomposition const &cbc) {
  return transform(cbc.subgraphs,
                   [](BipartiteComponent const &bc) { return bc.head_nodes; });
}

std::set<std::set<Node>>
    get_tail_subcomponents(CompleteBipartiteCompositeDecomposition const &cbc) {
  return transform(cbc.subgraphs,
                   [](BipartiteComponent const &bc) { return bc.tail_nodes; });
}

} // namespace FlexFlow
