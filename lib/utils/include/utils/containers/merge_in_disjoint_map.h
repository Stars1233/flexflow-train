#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_MERGE_IN_DISJOINT_MAP_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_MERGE_IN_DISJOINT_MAP_H

#include <libassert/assert.hpp>
#include <map>

namespace FlexFlow {

template <typename K, typename V>
void merge_in_disjoint_map(std::map<K, V> const &m, std::map<K, V> &result) {
  for (auto const &kv : m) {
    bool inserted = result.insert(kv).second;
    ASSERT(inserted);
  }
}

} // namespace FlexFlow

#endif
