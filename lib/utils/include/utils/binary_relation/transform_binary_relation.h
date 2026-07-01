#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_BINARY_RELATION_TRANSFORM_BINARY_RELATION_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_BINARY_RELATION_TRANSFORM_BINARY_RELATION_H

#include "utils/binary_relation/binary_relation.h"
#include <type_traits>

namespace FlexFlow {

template <typename L,
          typename R,
          typename F,
          typename L2 = typename std::invoke_result_t<F, L, R>::first_type,
          typename R2 = typename std::invoke_result_t<F, L, R>::second_type>
BinaryRelation<L2, R2>
    binary_relation_transform_left(BinaryRelation<L, R> const &rel, F &&f) {
  BinaryRelation<L2, R2> result;

  for (std::pair<L, R> const &p : rel.unwrap_as_set()) {
    result.equate(f(p.first, p.second));
  }

  return result;
}

} // namespace FlexFlow

#endif
