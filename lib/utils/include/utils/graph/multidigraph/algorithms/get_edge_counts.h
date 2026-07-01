#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_GRAPH_MULTIDIGRAPH_ALGORITHMS_GET_EDGE_COUNTS_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_GRAPH_MULTIDIGRAPH_ALGORITHMS_GET_EDGE_COUNTS_H

#include "utils/graph/multidigraph/multidigraph_view.h"
#include "utils/positive_int/positive_int.h"

namespace FlexFlow {

std::map<DirectedEdge, positive_int> get_edge_counts(MultiDiGraphView const &);

} // namespace FlexFlow

#endif
