#ifndef _FLEXFLOW_OPS_KERNELS_ELEMENT_BINARY_KERNELS_H
#define _FLEXFLOW_OPS_KERNELS_ELEMENT_BINARY_KERNELS_H

#include "kernels/accessor.h"
#include "kernels/device_handle_t.dtg.h"
#include "kernels/device_stream_t.dtg.h"
#include "kernels/element_binary_per_device_state.dtg.h"
#include "op-attrs/ops/element_binary_attrs.dtg.h"
#include "op-attrs/tensor_shape.dtg.h"
#include "pcg/device_type.dtg.h"

namespace FlexFlow {

std::optional<ElementBinaryPerDeviceState>
    element_binary_init_kernel(DeviceType device_type,
                               ElementBinaryAttrs const &attrs,
                               TensorShape const &lhs_shape,
                               TensorShape const &rhs_shape,
                               TensorShape const &output_shape);

void element_binary_forward_kernel(
    device_stream_t const &stream,
    device_handle_t const &handle,
    std::optional<ElementBinaryPerDeviceState> const &per_device_state,
    ElementBinaryAttrs const &attrs,
    GenericTensorAccessorR const &lhs,
    GenericTensorAccessorR const &rhs,
    GenericTensorAccessorW const &output);

void element_binary_backward_kernel(
    device_stream_t const &stream,
    device_handle_t const &handle,
    std::optional<ElementBinaryPerDeviceState> const &per_device_state,
    ElementBinaryAttrs const &attrs,
    GenericTensorAccessorR const &output,
    GenericTensorAccessorR const &output_grad,
    GenericTensorAccessorR const &lhs,
    GenericTensorAccessorW const &lhs_grad,
    GenericTensorAccessorR const &rhs,
    GenericTensorAccessorW const &rhs_grad);

void element_binary_cleanup_kernel(
    DeviceType device_type,
    std::optional<ElementBinaryPerDeviceState> const &per_device_state);

} // namespace FlexFlow

#endif
