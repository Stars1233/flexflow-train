#include "utils/graph/digraph/algorithms/get_imm_dominators_map.h"
#include "utils/containers/concat_vectors.h"
#include "utils/containers/filter_values.h"
#include "utils/containers/generate_map.h"
#include "utils/containers/get_element_counts.h"
#include "utils/containers/get_only.h"
#include "utils/containers/keys.h"
#include "utils/containers/transform.h"
#include "utils/containers/vector_of.h"
#include "utils/graph/digraph/algorithms/get_dominators_map.h"
#include "utils/graph/node/algorithms.h"

namespace FlexFlow {

std::map<Node, std::optional<Node>>
    get_imm_dominators_map(DiGraphView const &g) {

  std::map<Node, std::set<Node>> node_to_its_dominators = get_dominators_map(g);

  auto get_imm_dominator = [&](Node const &n) {
    std::set<Node> n_dominators = node_to_its_dominators.at(n);
    n_dominators.erase(n);
    std::vector<Node> recursive_dominator_list = concat_vectors(
        transform(vector_of(n_dominators), [&](Node const &dominator) {
          return vector_of(node_to_its_dominators.at(dominator));
        }));
    std::map<Node, positive_int> dominator_counts =
        get_element_counts(recursive_dominator_list);
    std::set<Node> imm_dominators = keys(filter_values(
        dominator_counts, [](positive_int count) { return count <= 1; }));
    ASSERT(imm_dominators.size() <= 1);

    return maybe_get_only(imm_dominators);
  };

  return generate_map(get_nodes(g), get_imm_dominator);
}

} // namespace FlexFlow
