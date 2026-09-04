#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_MERGE_IN_DISJOINT_UNORDERED_MAP_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_MERGE_IN_DISJOINT_UNORDERED_MAP_H

#include <libassert/assert.hpp>
#include <unordered_map>

namespace FlexFlow {

template <typename K, typename V>
void merge_in_disjoint_unordered_map(std::unordered_map<K, V> const &m,
                                     std::unordered_map<K, V> &result) {
  for (auto const &kv : m) {
    bool inserted = result.insert(kv).second;
    ASSERT(inserted);
  }
}

} // namespace FlexFlow

#endif
