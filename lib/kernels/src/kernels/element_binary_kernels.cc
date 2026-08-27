#include "kernels/element_binary_kernels.h"
#include "kernels/element_binary_kernels_cpu.h"
#include "kernels/element_binary_kernels_gpu.h"
#include "utils/optional.h"

namespace FlexFlow {

std::optional<ElementBinaryPerDeviceState>
    element_binary_init_kernel(DeviceType device_type,
                               ElementBinaryAttrs const &attrs,
                               TensorShape const &lhs_shape,
                               TensorShape const &rhs_shape,
                               TensorShape const &output_shape) {
  if (device_type == DeviceType::GPU) {
    return element_binary_gpu_init_kernel(
        /*attrs=*/attrs,
        /*lhs_shape=*/lhs_shape,
        /*rhs_shape=*/rhs_shape,
        /*output_shape=*/output_shape);
  } else {
    ASSERT(device_type == DeviceType::CPU);
    return std::nullopt;
  }
}

void element_binary_forward_kernel(
    device_stream_t const &stream,
    device_handle_t const &handle,
    std::optional<ElementBinaryPerDeviceState> const &per_device_state,
    ElementBinaryAttrs const &attrs,
    GenericTensorAccessorR const &lhs,
    GenericTensorAccessorR const &rhs,
    GenericTensorAccessorW const &output) {
  if (stream.is_gpu()) {
    element_binary_gpu_forward_kernel(
        /*stream=*/stream.require_gpu(),
        /*handle=*/handle.require_for_gpu(),
        /*per_device_state=*/assert_unwrap(per_device_state),
        /*attrs=*/attrs,
        /*lhs=*/lhs,
        /*rhs=*/rhs,
        /*output=*/output);
  } else {
    ASSERT(stream.is_cpu());
    ASSERT(handle.is_for_cpu());
    ASSERT(!per_device_state.has_value());
    element_binary_cpu_forward_kernel(
        /*attrs=*/attrs,
        /*lhs=*/lhs,
        /*lhs=*/rhs,
        /*output=*/output);
  }
}

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
    GenericTensorAccessorW const &rhs_grad) {
  if (stream.is_gpu()) {
    element_binary_gpu_backward_kernel(
        /*stream=*/stream.require_gpu(),
        /*handle=*/handle.require_for_gpu(),
        /*per_device_state=*/assert_unwrap(per_device_state),
        /*attrs=*/attrs,
        /*output=*/output,
        /*output_grad=*/output_grad,
        /*lhs=*/lhs,
        /*lhs_grad=*/lhs_grad,
        /*rhs=*/rhs,
        /*rhs_grad=*/rhs_grad);
  } else {
    ASSERT(stream.is_cpu());
    ASSERT(handle.is_for_cpu());
    ASSERT(!per_device_state.has_value());
    element_binary_cpu_backward_kernel(
        /*attrs=*/attrs,
        /*output=*/output,
        /*output_grad=*/output_grad,
        /*lhs=*/lhs,
        /*lhs_grad=*/lhs_grad,
        /*rhs=*/rhs,
        /*rhs_grad=*/rhs_grad);
  }
}

void element_binary_cleanup_kernel(
    DeviceType device_type,
    std::optional<ElementBinaryPerDeviceState> const &per_device_state) {
  if (device_type == DeviceType::GPU) {
    element_binary_gpu_cleanup_kernel(per_device_state.value());
  } else {
    ASSERT(device_type == DeviceType::CPU);
    ASSERT(!per_device_state.has_value());
  }
}

} // namespace FlexFlow
