#include "kernels/batch_matmul_kernels_cpu.h"
#include "kernels/local_cpu_allocator.h"
#include "kernels/tensor_accessor_binary_ops.h"
#include "kernels/tensor_accessor_unary_ops.h"

namespace FlexFlow {

void batch_matmul_cpu_forward_kernel(GenericTensorAccessorR const &input_lhs,
                                     GenericTensorAccessorR const &input_rhs,
                                     GenericTensorAccessorW const &output) {
  tensor_accessor_batch_matmul_to(input_lhs, input_rhs, output);
}

void batch_matmul_cpu_backward_kernel(
    GenericTensorAccessorR const &output,
    GenericTensorAccessorR const &output_grad,
    GenericTensorAccessorR const &input_lhs,
    GenericTensorAccessorW const &input_lhs_grad,
    GenericTensorAccessorR const &input_rhs,
    GenericTensorAccessorW const &input_rhs_grad) {
  TensorDims lhs_dims =
      require_same(input_lhs.shape.dims, input_lhs_grad.shape.dims);
  TensorDims rhs_dims =
      require_same(input_rhs.shape.dims, input_rhs_grad.shape.dims);
  TensorDims out_dims = require_same(output.shape.dims, output_grad.shape.dims);

  positive_int batch_size = require_same(dim_at_idx(lhs_dims, ff_dim_t{0_n}),
                                         dim_at_idx(rhs_dims, ff_dim_t{0_n}),
                                         dim_at_idx(out_dims, ff_dim_t{0_n}));

  positive_int lhs_rows = require_same(dim_at_idx(lhs_dims, ff_dim_t{1_n}),
                                       dim_at_idx(out_dims, ff_dim_t{1_n}));

  positive_int inner = require_same(dim_at_idx(lhs_dims, ff_dim_t{2_n}),
                                    dim_at_idx(rhs_dims, ff_dim_t{1_n}));

  positive_int rhs_cols = require_same(dim_at_idx(rhs_dims, ff_dim_t{2_n}),
                                       dim_at_idx(out_dims, ff_dim_t{2_n}));

  Allocator cpu_allocator = create_local_cpu_memory_allocator();

  tensor_accessor_batch_matmul_to(
      output_grad,
      tensor_accessor_batch_transpose(input_rhs, cpu_allocator),
      input_lhs_grad);

  tensor_accessor_batch_matmul_to(
      tensor_accessor_batch_transpose(input_lhs, cpu_allocator),
      output_grad,
      input_rhs_grad);
}

} // namespace FlexFlow
