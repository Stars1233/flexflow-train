#ifndef _FLEXFLOW_LIB_KERNELS_INCLUDE_KERNELS_ELEMENT_UNARY_KERNELS_CPU_H
#define _FLEXFLOW_LIB_KERNELS_INCLUDE_KERNELS_ELEMENT_UNARY_KERNELS_CPU_H

#include "kernels/accessor.h"
#include "op-attrs/ops/element_unary_attrs.dtg.h"

namespace FlexFlow {

void element_unary_cpu_forward_kernel(ElementUnaryAttrs const &attrs,
                                      GenericTensorAccessorR const &input,
                                      GenericTensorAccessorW const &output);

void element_unary_cpu_backward_kernel(
    ElementUnaryAttrs const &attrs,
    GenericTensorAccessorR const &output,
    GenericTensorAccessorR const &output_grad,
    GenericTensorAccessorR const &input,
    GenericTensorAccessorW const &input_grad);

} // namespace FlexFlow

#endif
