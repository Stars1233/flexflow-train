#ifndef _FLEXFLOW_LIB_OP_ATTRS_INCLUDE_OP_ATTRS_OPS_BATCH_MATMUL_H
#define _FLEXFLOW_LIB_OP_ATTRS_INCLUDE_OP_ATTRS_OPS_BATCH_MATMUL_H

#include "op-attrs/ops/batch_matmul_attrs.dtg.h"
#include "op-attrs/parallel_tensor_dim_degrees.dtg.h"
#include "op-attrs/parallel_tensor_shape.dtg.h"
#include "op-attrs/tensor_shape.dtg.h"

namespace FlexFlow {

TensorShape batch_matmul_get_output_shape(BatchMatmulAttrs const &,
                                          TensorShape const &lhs,
                                          TensorShape const &rhs);

ParallelTensorDimDegrees batch_matmul_get_output_parallel_dim_degrees(
    BatchMatmulAttrs const &attrs,
    ParallelTensorDimDegrees const &lhs,
    ParallelTensorDimDegrees const &rhs);

ParallelTensorShape
    batch_matmul_get_output_parallel_shape(BatchMatmulAttrs const &,
                                           ParallelTensorShape const &lhs,
                                           ParallelTensorShape const &rhs);

} // namespace FlexFlow

#endif
