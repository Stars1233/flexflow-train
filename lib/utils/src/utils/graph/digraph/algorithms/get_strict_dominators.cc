#include "utils/graph/digraph/algorithms/get_strict_dominators.h"
#include "utils/graph/digraph/algorithms/get_dominators.h"
#include "utils/graph/node/algorithms.h"

namespace FlexFlow {

std::set<Node> get_strict_dominators(DiGraphView const &g, Node const &n) {
  std::set<Node> result = get_dominators(g, {n});
  result.erase(n);
  return result;
}

} // namespace FlexFlow
