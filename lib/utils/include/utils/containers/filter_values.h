#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_FILTER_VALUES_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_FILTER_VALUES_H

#include <map>

namespace FlexFlow {

template <typename K, typename V, typename F>
std::map<K, V> filter_values(std::map<K, V> const &m, F const &f) {
  std::map<K, V> result;
  for (auto const &kv : m) {
    if (f(kv.second)) {
      result.insert(kv);
    }
  }
  return result;
}

} // namespace FlexFlow

#endif
