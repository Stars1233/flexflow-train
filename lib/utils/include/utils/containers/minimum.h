#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_MINIMUM_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_MINIMUM_H

#include <algorithm>
#include <libassert/assert.hpp>

namespace FlexFlow {

template <typename C>
typename C::value_type minimum(C const &c) {
  ASSERT(
      c.size() > 0, "minimum expected non-empty container but received {}", c);

  return *std::min_element(c.begin(), c.end());
}

} // namespace FlexFlow

#endif
