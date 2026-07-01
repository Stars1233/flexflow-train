#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_VALUES_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_VALUES_H

#include <set>

namespace FlexFlow {

template <typename C>
std::multiset<typename C::mapped_type> values(C const &c) {
  std::multiset<typename C::mapped_type> result;
  for (auto const &kv : c) {
    result.insert(kv.second);
  }
  return result;
}

} // namespace FlexFlow

#endif
