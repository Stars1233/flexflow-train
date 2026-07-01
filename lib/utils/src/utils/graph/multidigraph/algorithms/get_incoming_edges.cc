#include "utils/graph/multidigraph/algorithms/get_incoming_edges.h"
#include "utils/containers/group_by.h"
#include "utils/containers/map_values.h"
#include "utils/containers/set_of.h"
#include "utils/graph/multidigraph/algorithms/get_edges.h"
#include "utils/graph/multidigraph/multidiedge.dtg.h"
#include "utils/graph/multidigraph/multidiedge_query.dtg.h"
#include "utils/graph/node/algorithms.h"
#include "utils/graph/query_set.h"

namespace FlexFlow {

std::set<MultiDiEdge> get_incoming_edges(MultiDiGraphView const &g,
                                         Node const &n) {
  MultiDiEdgeQuery query = MultiDiEdgeQuery{
      query_set<Node>::matchall(),
      query_set<Node>::match_single_value(n),
  };

  return g.query_edges(query);
}

std::map<Node, std::set<MultiDiEdge>>
    get_incoming_edges(MultiDiGraphView const &g, std::set<Node> const &ns) {
  MultiDiEdgeQuery query = MultiDiEdgeQuery{
      query_set<Node>::matchall(),
      query_set<Node>::match_values_in(set_of(ns)),
  };

  std::map<Node, std::set<MultiDiEdge>> result = map_values(
      group_by(g.query_edges(query),
               [&](MultiDiEdge const &e) { return g.get_multidiedge_dst(e); })
          .l_to_r(),
      [](nonempty_set<MultiDiEdge> const &s) -> std::set<MultiDiEdge> {
        return s.unwrap_as_set();
      });

  for (Node const &n : ns) {
    result[n];
  }

  return result;
}

} // namespace FlexFlow
