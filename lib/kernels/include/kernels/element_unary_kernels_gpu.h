#ifndef _FLEXFLOW_LIB_KERNELS_INCLUDE_KERNELS_ELEMENT_UNARY_KERNELS_GPU_H
#define _FLEXFLOW_LIB_KERNELS_INCLUDE_KERNELS_ELEMENT_UNARY_KERNELS_GPU_H

#include "kernels/accessor.h"
#include "kernels/device.h"
#include "kernels/element_unary_per_device_state.dtg.h"
#include "op-attrs/ops/element_unary_attrs.dtg.h"

namespace FlexFlow {

ElementUnaryPerDeviceState
    element_unary_gpu_init_kernel(ElementUnaryAttrs const &attrs,
                                  TensorShape const &input_shape,
                                  TensorShape const &output_shape);

void element_unary_gpu_forward_kernel(
    ffStream_t stream,
    PerDeviceFFHandle const &handle,
    ElementUnaryPerDeviceState const &per_device_state,
    ElementUnaryAttrs const &attrs,
    GenericTensorAccessorR const &input,
    GenericTensorAccessorW const &output);

void element_unary_gpu_backward_kernel(
    ffStream_t stream,
    PerDeviceFFHandle const &handle,
    ElementUnaryPerDeviceState const &per_device_state,
    ElementUnaryAttrs const &attrs,
    GenericTensorAccessorR const &output,
    GenericTensorAccessorR const &output_grad,
    GenericTensorAccessorR const &input,
    GenericTensorAccessorW const &input_grad);

void element_unary_gpu_cleanup_kernel(
    ElementUnaryPerDeviceState &per_device_state);

} // namespace FlexFlow

#endif
