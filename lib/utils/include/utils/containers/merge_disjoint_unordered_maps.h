#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_MERGE_DISJOINT_UNORDERED_MAPS_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_MERGE_DISJOINT_UNORDERED_MAPS_H

#include "utils/containers/merge_in_disjoint_unordered_map.h"

namespace FlexFlow {

template <typename C,
          typename K = typename C::value_type::key_type,
          typename V = typename C::value_type::mapped_type>
std::unordered_map<K, V> merge_disjoint_unordered_maps(C const &c) {
  std::unordered_map<K, V> result;
  for (auto const &m : c) {
    merge_in_disjoint_unordered_map(m, result);
  }
  return result;
}

} // namespace FlexFlow

#endif
