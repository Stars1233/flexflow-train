#ifndef _FLEXFLOW_OPS_KERNELS_ELEMENT_UNARY_KERNELS_H
#define _FLEXFLOW_OPS_KERNELS_ELEMENT_UNARY_KERNELS_H

#include "kernels/accessor.h"
#include "kernels/device_handle_t.dtg.h"
#include "kernels/device_stream_t.dtg.h"
#include "kernels/element_unary_per_device_state.dtg.h"
#include "op-attrs/ops/element_unary_attrs.dtg.h"
#include "op-attrs/tensor_shape.dtg.h"
#include "pcg/device_type.dtg.h"

namespace FlexFlow {

std::optional<ElementUnaryPerDeviceState>
    element_unary_init_kernel(DeviceType device_type,
                              ElementUnaryAttrs const &attrs,
                              TensorShape const &input_shape,
                              TensorShape const &output_shape);

void element_unary_forward_kernel(
    device_stream_t const &stream,
    device_handle_t const &handle,
    std::optional<ElementUnaryPerDeviceState> const &per_device_state,
    ElementUnaryAttrs const &attrs,
    GenericTensorAccessorR const &input,
    GenericTensorAccessorW const &output);

void element_unary_backward_kernel(
    device_stream_t const &stream,
    device_handle_t const &handle,
    std::optional<ElementUnaryPerDeviceState> const &per_device_state,
    ElementUnaryAttrs const &attrs,
    GenericTensorAccessorR const &output,
    GenericTensorAccessorR const &output_grad,
    GenericTensorAccessorR const &input,
    GenericTensorAccessorW const &input_grad);

void element_unary_cleanup_kernel(
    DeviceType device_type,
    std::optional<ElementUnaryPerDeviceState> &per_device_state);

} // namespace FlexFlow

#endif
