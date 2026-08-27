#ifndef _FLEXFLOW_LIB_KERNELS_INCLUDE_KERNELS_ELEMENT_BINARY_KERNELS_CPU_H
#define _FLEXFLOW_LIB_KERNELS_INCLUDE_KERNELS_ELEMENT_BINARY_KERNELS_CPU_H

#include "kernels/accessor.h"
#include "op-attrs/ops/element_binary_attrs.dtg.h"

namespace FlexFlow {

void element_binary_cpu_forward_kernel(ElementBinaryAttrs const &attrs,
                                       GenericTensorAccessorR const &lhs,
                                       GenericTensorAccessorR const &rhs,
                                       GenericTensorAccessorW const &output);

void element_binary_cpu_backward_kernel(
    ElementBinaryAttrs const &attrs,
    GenericTensorAccessorR const &output,
    GenericTensorAccessorR const &output_grad,
    GenericTensorAccessorR const &lhs,
    GenericTensorAccessorW const &lhs_grad,
    GenericTensorAccessorR const &rhs,
    GenericTensorAccessorW const &rhs_grad);

} // namespace FlexFlow

#endif
