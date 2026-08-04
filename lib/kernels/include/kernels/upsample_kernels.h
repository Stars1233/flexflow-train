#ifndef _FLEXFLOW_LIB_KERNELS_INCLUDE_KERNELS_UPSAMPLE_KERNELS_H
#define _FLEXFLOW_LIB_KERNELS_INCLUDE_KERNELS_UPSAMPLE_KERNELS_H

#include "kernels/accessor.h"
#include "kernels/device_stream_t.dtg.h"
#include "op-attrs/ops/upsample_attrs.dtg.h"

namespace FlexFlow {

void upsample_forward_kernel(device_stream_t const &stream,
                             UpsampleAttrs const &attrs,
                             GenericTensorAccessorR const &input,
                             GenericTensorAccessorW const &output);

void upsample_backward_kernel(device_stream_t const &stream,
                              UpsampleAttrs const &attrs,
                              GenericTensorAccessorR const &output,
                              GenericTensorAccessorR const &output_grad,
                              GenericTensorAccessorR const &input,
                              GenericTensorAccessorW const &input_grad);

} // namespace FlexFlow

#endif
