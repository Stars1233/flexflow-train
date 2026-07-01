#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_GRAPH_INSTANCES_ADJACENCY_DIGRAPH_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_GRAPH_INSTANCES_ADJACENCY_DIGRAPH_H

#include "utils/graph/digraph/digraph.h"
#include "utils/graph/node/node_source.h"
#include <map>
#include <set>

namespace FlexFlow {

class AdjacencyDiGraph : public IDiGraph {
public:
  AdjacencyDiGraph();

  Node add_node() override;
  void add_node_unsafe(Node const &) override;
  void remove_node_unsafe(Node const &) override;
  void add_edge(Edge const &) override;
  void remove_edge(Edge const &) override;
  std::set<Edge> query_edges(DirectedEdgeQuery const &) const override;
  std::set<Node> query_nodes(NodeQuery const &) const override;

  AdjacencyDiGraph *clone() const override;

private:
  AdjacencyDiGraph(NodeSource const &node_source,
                   std::map<Node, std::set<Node>> const &adjacency);

  NodeSource node_source;
  std::map<Node, std::set<Node>> adjacency;
};
CHECK_RC_COPY_VIRTUAL_COMPLIANT(AdjacencyDiGraph);

} // namespace FlexFlow

#endif
