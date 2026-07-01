#include "utils/graph/digraph/algorithms/get_strict_dominators_map.h"
#include "utils/containers/transform.h"
#include "utils/graph/digraph/algorithms/get_dominators_map.h"

namespace FlexFlow {

std::map<Node, std::set<Node>> get_strict_dominators_map(DiGraphView const &g) {
  return transform(get_dominators_map(g),
                   [](Node const &n, std::set<Node> const &doms) {
                     std::set<Node> result = doms;
                     result.erase(n);
                     return std::make_pair(n, result);
                   });
}

} // namespace FlexFlow
