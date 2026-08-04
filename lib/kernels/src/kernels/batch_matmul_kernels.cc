#include "kernels/batch_matmul_kernels.h"
#include "kernels/batch_matmul_kernels_cpu.h"
#include "kernels/batch_matmul_kernels_gpu.h"

namespace FlexFlow {

void batch_matmul_forward_kernel(device_stream_t const &stream,
                                 GenericTensorAccessorR const &input_lhs,
                                 GenericTensorAccessorR const &input_rhs,
                                 GenericTensorAccessorW const &output) {
  if (stream.is_gpu()) {
    batch_matmul_gpu_forward_kernel(
        /*stream=*/stream.require_gpu(),
        /*input_lhs=*/input_lhs,
        /*input_rhs=*/input_rhs,
        /*output=*/output);
  } else {
    ASSERT(stream.is_cpu());

    batch_matmul_cpu_forward_kernel(
        /*input_lhs=*/input_lhs,
        /*input_rhs=*/input_rhs,
        /*output=*/output);
  }
}

void batch_matmul_backward_kernel(
    device_stream_t const &stream,
    GenericTensorAccessorR const &output,
    GenericTensorAccessorR const &output_grad,
    GenericTensorAccessorR const &input_lhs,
    GenericTensorAccessorW const &input_lhs_grad,
    GenericTensorAccessorR const &input_rhs,
    GenericTensorAccessorW const &input_rhs_grad) {
  if (stream.is_gpu()) {
    batch_matmul_gpu_backward_kernel(
        /*stream=*/stream.require_gpu(),
        /*output=*/output,
        /*output_grad=*/output_grad,
        /*input_lhs=*/input_lhs,
        /*input_lhs_grad=*/input_lhs_grad,
        /*input_rhs=*/input_rhs,
        /*input_rhs_grad=*/input_rhs_grad);
  } else {
    ASSERT(stream.is_cpu());

    batch_matmul_cpu_backward_kernel(
        /*output=*/output,
        /*output_grad=*/output_grad,
        /*input_lhs=*/input_lhs,
        /*input_lhs_grad=*/input_lhs_grad,
        /*input_rhs=*/input_rhs,
        /*input_rhs_grad=*/input_rhs_grad);
  }
}

} // namespace FlexFlow
