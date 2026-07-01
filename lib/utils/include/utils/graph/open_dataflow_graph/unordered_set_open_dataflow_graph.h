#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_GRAPH_OPEN_DATAFLOW_GRAPH_UNORDERED_SET_OPEN_DATAFLOW_GRAPH_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_GRAPH_OPEN_DATAFLOW_GRAPH_UNORDERED_SET_OPEN_DATAFLOW_GRAPH_H

#include "utils/graph/node/node_source.h"
#include "utils/graph/open_dataflow_graph/dataflow_graph_input_source.h"
#include "utils/graph/open_dataflow_graph/i_open_dataflow_graph.h"

namespace FlexFlow {

struct UnorderedSetOpenDataflowGraph : public IOpenDataflowGraph {
public:
  UnorderedSetOpenDataflowGraph();

  NodeAddedResult add_node(std::vector<OpenDataflowValue> const &inputs,
                           nonnegative_int num_outputs) override;

  std::set<Node> query_nodes(NodeQuery const &) const override;
  std::set<OpenDataflowEdge>
      query_edges(OpenDataflowEdgeQuery const &) const override;
  std::set<DataflowOutput>
      query_outputs(DataflowOutputQuery const &) const override;
  std::set<DataflowGraphInput> get_inputs() const override;

  DataflowGraphInput add_input() override;
  UnorderedSetOpenDataflowGraph *clone() const override;

private:
  UnorderedSetOpenDataflowGraph(
      NodeSource const &node_source,
      DataflowGraphInputSource const &input_source,
      std::set<Node> const &nodes,
      std::set<DataflowEdge> const &standard_edges,
      std::set<DataflowInputEdge> const &input_edges,
      std::set<DataflowOutput> const &outputs,
      std::set<DataflowGraphInput> const &graph_inputs);

private:
  NodeSource node_source;
  DataflowGraphInputSource input_source;
  std::set<Node> nodes;
  std::set<DataflowEdge> standard_edges;
  std::set<DataflowInputEdge> input_edges;
  std::set<DataflowOutput> outputs;
  std::set<DataflowGraphInput> graph_inputs;
};
CHECK_RC_COPY_VIRTUAL_COMPLIANT(UnorderedSetOpenDataflowGraph);

} // namespace FlexFlow

#endif
