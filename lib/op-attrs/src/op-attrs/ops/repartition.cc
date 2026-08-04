#include "op-attrs/ops/repartition.h"
#include <libassert/assert.hpp>

namespace FlexFlow {

ParallelTensorShape repartition_get_output_parallel_shape(
    RepartitionAttrs const &attrs, ParallelTensorShape const &input_shape) {
  ASSERT(input_shape.dims.shard_dims.idx_is_valid(attrs.repartition_dim),
         attrs,
         input_shape);

  ParallelTensorShape output_shape = input_shape;
  output_shape.dims.shard_dims
      .at(relative_ff_dim_t_from_ff_dim_t(attrs.repartition_dim))
      .degree *= attrs.repartition_degree;
  return output_shape;
}

} // namespace FlexFlow
