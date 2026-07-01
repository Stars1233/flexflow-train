#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_GRAPH_DIGRAPH_ALGORITHMS_GET_SUCCESSORS_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_GRAPH_DIGRAPH_ALGORITHMS_GET_SUCCESSORS_H

#include "utils/graph/digraph/digraph_view.h"

namespace FlexFlow {

std::map<Node, std::set<Node>> get_successors(DiGraphView const &);
std::set<Node> get_successors(DiGraphView const &, Node const &);
std::map<Node, std::set<Node>> get_successors(DiGraphView const &,
                                              std::set<Node> const &);

} // namespace FlexFlow

#endif
