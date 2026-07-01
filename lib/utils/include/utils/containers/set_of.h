#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_SET_OF_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_SET_OF_H

#include <map>
#include <set>

namespace FlexFlow {

template <typename C, typename T = typename C::value_type>
std::set<T> set_of(C const &c) {
  std::set<T> result;
  for (T const &t : c) {
    result.insert(t);
  }
  return result;
}

template <typename K, typename V>
std::set<std::pair<K, V>> set_of(std::map<K, V> const &m) {
  std::set<std::pair<K, V>> result;
  for (auto const &[k, v] : m) {
    result.insert({k, v});
  }
  return result;
}

} // namespace FlexFlow

#endif
