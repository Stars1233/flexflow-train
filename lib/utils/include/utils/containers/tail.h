#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_TAIL_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_TAIL_H

#include "utils/containers/slice.h"
#include <libassert/assert.hpp>
#include <vector>

namespace FlexFlow {

template <typename T>
std::vector<T> tail(std::vector<T> const &v) {
  ASSERT(v.size() >= 1);

  return slice(v, 1, std::nullopt);
}

} // namespace FlexFlow

#endif
