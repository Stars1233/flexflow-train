#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_INVERT_MAP_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_INVERT_MAP_H

#include <map>
#include <set>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

namespace FlexFlow {

template <typename K, typename V>
std::map<V, std::set<K>> invert_map(std::map<K, V> const &m) {
  std::map<V, std::set<K>> result;
  for (auto const &[key, value] : m) {
    result[value].insert(key);
  }
  return result;
}

} // namespace FlexFlow

#endif
