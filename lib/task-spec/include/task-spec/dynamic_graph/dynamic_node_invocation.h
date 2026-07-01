#ifndef _FLEXFLOW_LIB_TASK_SPEC_INCLUDE_TASK_SPEC_DYNAMIC_GRAPH_DYNAMIC_NODE_INVOCATION_H
#define _FLEXFLOW_LIB_TASK_SPEC_INCLUDE_TASK_SPEC_DYNAMIC_GRAPH_DYNAMIC_NODE_INVOCATION_H

#include "pcg/tensor_direction.dtg.h"
#include "task-spec/dynamic_graph/dynamic_node_invocation.dtg.h"
#include "task-spec/dynamic_graph/dynamic_slot_site.dtg.h"
#include "task-spec/dynamic_graph/training_op_type.dtg.h"

namespace FlexFlow {

bool invocation_fully_satisfies(
    DynamicNodeInvocation const &,
    std::function<bool(DynamicNodeAttrs const &)> const &node_condition,
    std::function<bool(DynamicValueAttrs const &)> const &value_condition,
    std::function<bool(DynamicTensorSlot const &)> const &slot_condition);

void require_invocation_fully_satisfies(
    DynamicNodeInvocation const &,
    std::function<void(DynamicNodeAttrs const &)> const &require_node_condition,
    std::function<void(DynamicValueAttrs const &)> const
        &require_value_condition,
    std::function<void(DynamicTensorSlot const &)> const
        &require_slot_condition);

std::map<DynamicTensorSlot, DynamicValueAttrs>
    get_slot_map_for_direction(DynamicNodeInvocation const &, TensorDirection);

TrainingOpType
    dynamic_node_invocation_get_op_type(DynamicNodeInvocation const &);

std::set<InternalDynamicSlotSite>
    get_incoming_dynamic_slot_sites_for_invocation(
        dynamic_invocation_id_t const &, DynamicNodeInvocation const &);

std::set<InternalDynamicSlotSite> get_output_dynamic_slot_sites_for_invocation(
    dynamic_invocation_id_t const &, DynamicNodeInvocation const &);

std::set<InternalDynamicSlotSite>
    get_dynamic_slot_sites_for_invocation(dynamic_invocation_id_t const &,
                                          DynamicNodeInvocation const &);

} // namespace FlexFlow

#endif
