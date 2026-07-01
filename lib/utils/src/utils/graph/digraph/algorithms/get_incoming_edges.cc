#include "utils/graph/digraph/algorithms/get_incoming_edges.h"
#include "utils/containers/group_by.h"
#include "utils/containers/map_values.h"
#include "utils/containers/set_of.h"
#include "utils/nonempty_set/nonempty_set.h"

namespace FlexFlow {

std::set<DirectedEdge> get_incoming_edges(DiGraphView const &g, Node const &n) {
  return g.query_edges(DirectedEdgeQuery{
      query_set<Node>::matchall(),
      query_set<Node>::match_single_value(n),
  });
}

std::map<Node, std::set<DirectedEdge>>
    get_incoming_edges(DiGraphView const &g, std::set<Node> const &ns) {

  std::map<Node, nonempty_set<DirectedEdge>> by_dst =
      group_by(g.query_edges(DirectedEdgeQuery{
                   query_set<Node>::matchall(),
                   query_set<Node>::match_values_in(set_of(ns)),
               }),
               [](DirectedEdge const &e) { return e.dst; })
          .l_to_r();

  std::map<Node, std::set<DirectedEdge>> result = map_values(
      by_dst,
      [](nonempty_set<DirectedEdge> const &s) -> std::set<DirectedEdge> {
        return s.unwrap_as_set();
      });

  for (Node const &n : ns) {
    result[n];
  }

  return result;
}

} // namespace FlexFlow
