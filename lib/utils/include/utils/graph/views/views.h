#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_GRAPH_VIEWS_VIEWS_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_GRAPH_VIEWS_VIEWS_H

#include "utils/graph/digraph/digraph_view.h"
#include "utils/graph/instances/adjacency_digraph.h"
#include "utils/graph/undirected/undirected_graph_view.h"
#include "utils/graph/views/join_node_key.dtg.h"

namespace FlexFlow {

struct UndirectedSubgraphView : public IUndirectedGraphView {
public:
  UndirectedSubgraphView() = delete;
  UndirectedSubgraphView(UndirectedGraphView const &, std::set<Node> const &);

  std::set<UndirectedEdge>
      query_edges(UndirectedEdgeQuery const &) const override;
  std::set<Node> query_nodes(NodeQuery const &) const override;

  UndirectedSubgraphView *clone() const override;

private:
  UndirectedGraphView g;
  std::set<Node> subgraph_nodes;
};

struct DiSubgraphView : public IDiGraphView {
public:
  DiSubgraphView() = delete;
  DiSubgraphView(DiGraphView const &, std::set<Node> const &);

  std::set<DirectedEdge> query_edges(DirectedEdgeQuery const &) const override;
  std::set<Node> query_nodes(NodeQuery const &) const override;

  DiSubgraphView *clone() const override;

private:
  DiGraphView g;
  std::set<Node> subgraph_nodes;
};

UndirectedGraphView view_subgraph(UndirectedGraphView const &,
                                  std::set<Node> const &);

DiGraphView view_subgraph(DiGraphView const &, std::set<Node> const &);

UndirectedEdge to_undirected_edge(DirectedEdge const &);
std::set<UndirectedEdge> to_undirected_edges(std::set<DirectedEdge> const &);

std::set<DirectedEdge> to_directed_edges(UndirectedEdge const &);
std::set<DirectedEdge> to_directed_edges(std::set<UndirectedEdge> const &);

struct ViewDiGraphAsUndirectedGraph : public IUndirectedGraphView {
public:
  explicit ViewDiGraphAsUndirectedGraph(DiGraphView const &);

  std::set<UndirectedEdge>
      query_edges(UndirectedEdgeQuery const &) const override;
  std::set<Node> query_nodes(NodeQuery const &) const override;

  ViewDiGraphAsUndirectedGraph *clone() const override;

private:
  DiGraphView g;
};

struct ViewUndirectedGraphAsDiGraph : public IDiGraphView {
public:
  explicit ViewUndirectedGraphAsDiGraph(UndirectedGraphView const &);

  std::set<DirectedEdge> query_edges(DirectedEdgeQuery const &) const override;
  std::set<Node> query_nodes(NodeQuery const &) const override;

  ViewUndirectedGraphAsDiGraph *clone() const override;

private:
  UndirectedGraphView g;
};

} // namespace FlexFlow

#endif
