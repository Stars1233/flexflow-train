#ifndef _FLEXFLOW_LIB_KERNELS_INCLUDE_KERNELS_ELEMENT_BINARY_KERNELS_GPU_H
#define _FLEXFLOW_LIB_KERNELS_INCLUDE_KERNELS_ELEMENT_BINARY_KERNELS_GPU_H

#include "kernels/accessor.h"
#include "kernels/device.h"
#include "kernels/element_binary_per_device_state.dtg.h"
#include "op-attrs/ops/element_binary_attrs.dtg.h"

namespace FlexFlow {

ElementBinaryPerDeviceState
    element_binary_gpu_init_kernel(ElementBinaryAttrs const &attrs,
                                   TensorShape const &lhs_shape,
                                   TensorShape const &rhs_shape,
                                   TensorShape const &output_shape);

void element_binary_gpu_forward_kernel(
    ffStream_t stream,
    PerDeviceFFHandle const &handle,
    ElementBinaryPerDeviceState const &per_device_state,
    ElementBinaryAttrs const &attrs,
    GenericTensorAccessorR const &lhs,
    GenericTensorAccessorR const &rhs,
    GenericTensorAccessorW const &output);

void element_binary_gpu_backward_kernel(
    ffStream_t stream,
    PerDeviceFFHandle const &handle,
    ElementBinaryPerDeviceState const &per_device_state,
    ElementBinaryAttrs const &attrs,
    GenericTensorAccessorR const &output,
    GenericTensorAccessorR const &output_grad,
    GenericTensorAccessorR const &lhs,
    GenericTensorAccessorW const &lhs_grad,
    GenericTensorAccessorR const &rhs,
    GenericTensorAccessorW const &rhs_grad);

void element_binary_gpu_cleanup_kernel(
    ElementBinaryPerDeviceState const &per_device_state);

} // namespace FlexFlow

#endif
