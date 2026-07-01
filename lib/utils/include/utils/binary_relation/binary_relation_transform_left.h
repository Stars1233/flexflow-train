#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_BINARY_RELATION_BINARY_RELATION_TRANSFORM_LEFT_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_BINARY_RELATION_BINARY_RELATION_TRANSFORM_LEFT_H

#include "utils/binary_relation/binary_relation.h"
#include <type_traits>

namespace FlexFlow {

template <typename L,
          typename R,
          typename F,
          typename L2 = std::invoke_result_t<F, L>>
BinaryRelation<L2, R>
    binary_relation_transform_left(BinaryRelation<L, R> const &rel, F &&f) {
  BinaryRelation<L2, R> result;

  for (std::pair<L, R> const &p : rel.unwrap_as_set()) {
    result.equate(f(p.first), p.second);
  }

  return result;
}

} // namespace FlexFlow

#endif
