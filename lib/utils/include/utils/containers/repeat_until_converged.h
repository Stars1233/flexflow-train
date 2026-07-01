#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_REPEAT_UNTIL_CONVERGED_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_REPEAT_UNTIL_CONVERGED_H

namespace FlexFlow {

template <typename T, typename F>
T repeat_until_converged(T const &initial, F &&f) {
  T previous = initial;
  T current = initial;
  do {
    previous = current;
    current = f(current);
  } while (current != previous);

  return current;
}

} // namespace FlexFlow

#endif
