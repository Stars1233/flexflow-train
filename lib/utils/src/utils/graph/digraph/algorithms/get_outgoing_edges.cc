#include "utils/graph/digraph/algorithms/get_outgoing_edges.h"
#include "utils/containers/group_by.h"
#include "utils/containers/map_values.h"
#include "utils/containers/set_of.h"
#include "utils/nonempty_set/nonempty_set.h"

namespace FlexFlow {

std::map<Node, std::set<DirectedEdge>>
    get_outgoing_edges(DiGraphView const &g, std::set<Node> const &ns) {

  std::map<Node, nonempty_set<DirectedEdge>> by_src =
      group_by(g.query_edges(DirectedEdgeQuery{
                   query_set<Node>::match_values_in(set_of(ns)),
                   query_set<Node>::matchall(),
               }),
               [](DirectedEdge const &e) { return e.src; })
          .l_to_r();

  std::map<Node, std::set<DirectedEdge>> result = map_values(
      by_src,
      [](nonempty_set<DirectedEdge> const &s) -> std::set<DirectedEdge> {
        return s.unwrap_as_set();
      });

  for (Node const &n : ns) {
    result[n];
  }

  return result;
}

std::set<DirectedEdge> get_outgoing_edges(DiGraphView const &g, Node const &n) {
  return g.query_edges(DirectedEdgeQuery{
      query_set<Node>::match_single_value(n),
      query_set<Node>::matchall(),
  });
}

} // namespace FlexFlow
