#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_GRAPH_MULTIDIGRAPH_ALGORITHMS_GET_OUTGOING_EDGES_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_GRAPH_MULTIDIGRAPH_ALGORITHMS_GET_OUTGOING_EDGES_H

#include "utils/graph/multidigraph/multidigraph_view.h"
#include <set>

namespace FlexFlow {

std::set<MultiDiEdge> get_outgoing_edges(MultiDiGraphView const &,
                                         Node const &);

std::map<Node, std::set<MultiDiEdge>>
    get_outgoing_edges(MultiDiGraphView const &g, std::set<Node> const &ns);

} // namespace FlexFlow

#endif
