#ifndef _FLEXFLOW_LIB_OP_ATTRS_INCLUDE_OP_ATTRS_FF_ORDERED_SLICE_INCLUSIVE_H
#define _FLEXFLOW_LIB_OP_ATTRS_INCLUDE_OP_ATTRS_FF_ORDERED_SLICE_INCLUSIVE_H

#include "op-attrs/ff_ordered/ff_ordered.h"
#include "op-attrs/ff_ordered/ff_ordered_of.h"
#include "utils/containers/slice_inclusive.h"
#include "utils/containers/transform.h"
#include "utils/containers/vector_of.h"

namespace FlexFlow {

template <typename T>
FFOrdered<T>
    ff_dim_t_nonoverloaded_slice_inclusive(FFOrdered<T> const &d,
                                           ff_dim_t const &start,
                                           std::optional<ff_dim_t> const &end) {
  int raw_start = start.value.unwrap_nonnegative();
  std::optional<int> raw_end = transform(
      end, [](ff_dim_t const &i) { return i.value.unwrap_nonnegative(); });
  return ff_ordered_of(slice_inclusive(vector_of(d), raw_start, raw_end));
}

template <typename T>
FFOrdered<T> relative_ff_dim_t_nonoverloaded_slice_inclusive(
    FFOrdered<T> const &d,
    relative_ff_dim_t const &start,
    std::optional<relative_ff_dim_t> const &end) {
  int raw_start = start.value;
  std::optional<int> raw_end =
      transform(end, [](relative_ff_dim_t const &i) { return i.value; });

  return ff_ordered_of(slice_inclusive(vector_of(d), raw_start, raw_end));
}

template <typename T>
FFOrdered<T> ff_ordered_slice_inclusive(
    FFOrdered<T> const &d,
    ff_dim_t const &start = ff_dim_t{0_n},
    std::optional<ff_dim_t> const &end = std::nullopt) {
  return ff_dim_t_nonoverloaded_slice_inclusive(d, start, end);
}

template <typename T>
FFOrdered<T> ff_ordered_slice_inclusive(
    FFOrdered<T> const &d,
    relative_ff_dim_t const &start = relative_ff_dim_t{0},
    std::optional<relative_ff_dim_t> const &end = std::nullopt) {
  return relative_ff_dim_t_nonoverloaded_slice_inclusive(d, start, end);
}

} // namespace FlexFlow

#endif
