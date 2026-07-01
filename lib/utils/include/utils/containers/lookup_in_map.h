#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_LOOKUP_IN_MAP_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_LOOKUP_IN_MAP_H

#include "utils/containers/contains_key.h"
#include "utils/fmt/map.h"
#include <functional>
#include <libassert/assert.hpp>
#include <map>
#include <string>

namespace FlexFlow {

template <typename K, typename V>
std::function<V(K const &)> lookup_in_map(std::map<K, V> const &m) {
  return [m](K const &key) -> V {
    if (!contains_key(m, key)) {
      PANIC("Key {} is not present in the underlying map {}", key, m);
    }
    return m.at(key);
  };
}

} // namespace FlexFlow

#endif
