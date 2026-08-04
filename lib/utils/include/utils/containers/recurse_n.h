#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_RECURSE_N_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_RECURSE_N_H

#include "utils/nonnegative_int/nonnegative_int.h"

namespace FlexFlow {

/**
 * @brief
 * Applies function `f` to value `initial_value` n times recursively.
 *
 * @example
 *   auto add_three = [](int x) { return x + 3; };
 *   int result = recurse_n(add_three, 3, 5);
 *   result -> f(f(f(5))) = ((5+3)+3)+3 = 14
 *
 * @throws RuntimeError if n is negative
 */
template <typename F, typename T>
T recurse_n(F const &f, nonnegative_int n, T const &initial_value) {
  T t = initial_value;
  for (int i = 0; i < n; i++) {
    t = f(t);
  }
  return t;
}

} // namespace FlexFlow

#endif
