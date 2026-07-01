#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_BINARY_RELATION_BINARY_RELATION_TRANSFORM_RIGHT_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_BINARY_RELATION_BINARY_RELATION_TRANSFORM_RIGHT_H

#include "utils/binary_relation/binary_relation.h"
#include <type_traits>

namespace FlexFlow {

template <typename L,
          typename R,
          typename F,
          typename R2 = std::invoke_result_t<F, R>>
BinaryRelation<L, R2>
    binary_relation_transform_right(BinaryRelation<L, R> const &rel, F &&f) {
  BinaryRelation<L, R2> result;

  for (std::pair<L, R> const &p : rel.unwrap_as_set()) {
    result.equate(p.first, f(p.second));
  }

  return result;
}

} // namespace FlexFlow

#endif
