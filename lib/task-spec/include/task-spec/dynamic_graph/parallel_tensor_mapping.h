#ifndef _FLEXFLOW_LIB_TASK_SPEC_INCLUDE_TASK_SPEC_DYNAMIC_GRAPH_PARALLEL_TENSOR_MAPPING_H
#define _FLEXFLOW_LIB_TASK_SPEC_INCLUDE_TASK_SPEC_DYNAMIC_GRAPH_PARALLEL_TENSOR_MAPPING_H

#include "task-spec/dynamic_graph/parallel_tensor_mapping.dtg.h"

namespace FlexFlow {

global_device_id_t
    pt_mapping_get_device_for_coord(ParallelTensorMapping const &,
                                    ParallelTensorSpaceCoordinate const &);
ParallelTensorSpaceCoordinate
    pt_mapping_get_coord_for_device(ParallelTensorMapping const &,
                                    global_device_id_t const &);

std::set<ParallelTensorSpaceCoordinate>
    pt_mapping_get_coord_set(ParallelTensorMapping const &);
std::set<global_device_id_t>
    pt_mapping_get_device_set(ParallelTensorMapping const &);

} // namespace FlexFlow

#endif
