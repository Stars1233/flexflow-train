#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_ITERATE_N_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_ITERATE_N_H

#include "utils/nonnegative_int/nonnegative_int.h"
#include <vector>

namespace FlexFlow {

template <typename F, typename T>
std::vector<T> iterate_n(nonnegative_int n, T const &initial_value, F &&f) {
  std::vector<T> result = {initial_value};
  for (int i = 0; i < n; i++) {
    result.push_back(f(result.back()));
  }
  return result;
}

} // namespace FlexFlow

#endif
