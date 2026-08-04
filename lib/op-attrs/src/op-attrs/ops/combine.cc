#include "op-attrs/ops/combine.h"
#include "op-attrs/ff_dim_t.h"
#include "op-attrs/parallel_tensor_shape.h"
#include <libassert/assert.hpp>

namespace FlexFlow {

ParallelTensorShape
    combine_get_output_parallel_shape(CombineAttrs const &attrs,
                                      ParallelTensorShape const &input) {
  ShardParallelDim input_dim = shard_dim_at_idx(
      input, relative_ff_dim_t_from_ff_dim_t(attrs.combine_dim));

  ASSERT(input_dim.degree % attrs.combine_degree == 0,
         fmt::format("Combine received tensor containing parallel dim {} with "
                     "degree {}, which is not divisible by combine degree {}",
                     attrs.combine_dim,
                     input_dim.degree,
                     attrs.combine_degree),
         input);

  ParallelTensorShape output = input;
  relative_ff_dim_t combine_dim =
      relative_ff_dim_t_from_ff_dim_t(attrs.combine_dim);
  shard_dim_at_idx(output, combine_dim).degree = positive_int{
      shard_dim_at_idx(output, combine_dim).degree / attrs.combine_degree};

  return output;
}

} // namespace FlexFlow
