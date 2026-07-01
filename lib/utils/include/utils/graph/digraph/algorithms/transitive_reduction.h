#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_GRAPH_DIGRAPH_ALGORITHMS_TRANSITIVE_REDUCTION_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_GRAPH_DIGRAPH_ALGORITHMS_TRANSITIVE_REDUCTION_H

#include "utils/graph/digraph/digraph.h"
#include "utils/graph/digraph/digraph_view.h"

namespace FlexFlow {

struct DirectedEdgeMaskView final : public IDiGraphView {
  DirectedEdgeMaskView() = delete;
  explicit DirectedEdgeMaskView(DiGraphView const &,
                                std::set<DirectedEdge> const &);

  std::set<DirectedEdge> query_edges(DirectedEdgeQuery const &) const override;
  std::set<Node> query_nodes(NodeQuery const &) const override;

  DirectedEdgeMaskView *clone() const override;

private:
  DiGraphView g;
  std::set<DirectedEdge> edge_mask;
};

DiGraph transitive_reduction(DiGraphView const &);

} // namespace FlexFlow

#endif
