#ifndef _FLEXFLOW_LIB_KERNELS_INCLUDE_KERNELS_BATCH_MATMUL_KERNELS_CPU_H
#define _FLEXFLOW_LIB_KERNELS_INCLUDE_KERNELS_BATCH_MATMUL_KERNELS_CPU_H

#include "kernels/accessor.h"
#include "op-attrs/ops/batch_matmul_attrs.dtg.h"

namespace FlexFlow {

void batch_matmul_cpu_forward_kernel(GenericTensorAccessorR const &input_lhs,
                                     GenericTensorAccessorR const &input_rhs,
                                     GenericTensorAccessorW const &output);

void batch_matmul_cpu_backward_kernel(
    GenericTensorAccessorR const &output,
    GenericTensorAccessorR const &output_grad,
    GenericTensorAccessorR const &input_lhs,
    GenericTensorAccessorW const &input_lhs_grad,
    GenericTensorAccessorR const &input_rhs,
    GenericTensorAccessorW const &input_rhs_grad);

} // namespace FlexFlow

#endif
