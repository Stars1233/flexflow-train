#include "utils/graph/digraph/algorithms/get_imm_post_dominators_map.h"
#include "utils/graph/digraph/algorithms/flipped.h"
#include "utils/graph/digraph/algorithms/get_imm_dominators_map.h"

namespace FlexFlow {

std::map<Node, std::optional<Node>>
    get_imm_post_dominators_map(DiGraphView const &g) {
  return get_imm_dominators_map(flipped(g));
}

} // namespace FlexFlow
