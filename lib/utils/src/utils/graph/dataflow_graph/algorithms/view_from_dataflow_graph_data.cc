#include "utils/graph/dataflow_graph/algorithms/view_from_dataflow_graph_data.h"
#include "utils/containers/filter.h"
#include "utils/graph/dataflow_graph/dataflow_edge_query.h"
#include "utils/graph/dataflow_graph/dataflow_output_query.h"
#include "utils/graph/node/node_query.h"

namespace FlexFlow {

ViewFromDataflowGraphData::ViewFromDataflowGraphData(
    DataflowGraphData const &data)
    : data(data) {}

std::set<Node>
    ViewFromDataflowGraphData::query_nodes(NodeQuery const &query) const {
  return apply_node_query(query, set_of(this->data.nodes));
}

std::set<DataflowEdge> ViewFromDataflowGraphData::query_edges(
    DataflowEdgeQuery const &query) const {
  return filter(set_of(this->data.edges), [&](DataflowEdge const &e) {
    return dataflow_edge_query_includes_dataflow_edge(query, e);
  });
}

std::set<DataflowOutput> ViewFromDataflowGraphData::query_outputs(
    DataflowOutputQuery const &query) const {
  return filter(set_of(this->data.outputs), [&](DataflowOutput const &o) {
    return dataflow_output_query_includes_dataflow_output(query, o);
  });
}

ViewFromDataflowGraphData *ViewFromDataflowGraphData::clone() const {
  return new ViewFromDataflowGraphData{this->data};
}

DataflowGraphView view_from_dataflow_graph_data(DataflowGraphData const &data) {
  return DataflowGraphView::create<ViewFromDataflowGraphData>(data);
}

} // namespace FlexFlow
