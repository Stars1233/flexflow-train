#include "task-spec/dynamic_graph/parallel_tensor_mapping.h"

namespace FlexFlow {

global_device_id_t pt_mapping_get_device_for_coord(
    ParallelTensorMapping const &m,
    ParallelTensorSpaceCoordinate const &coord) {
  return m.raw.at_l(coord);
}

ParallelTensorSpaceCoordinate
    pt_mapping_get_coord_for_device(ParallelTensorMapping const &m,
                                    global_device_id_t const &device) {
  return m.raw.at_r(device);
}

std::set<ParallelTensorSpaceCoordinate>
    pt_mapping_get_coord_set(ParallelTensorMapping const &m) {
  return m.raw.left_values();
}

std::set<global_device_id_t>
    pt_mapping_get_device_set(ParallelTensorMapping const &m) {
  return m.raw.right_values();
}

} // namespace FlexFlow
