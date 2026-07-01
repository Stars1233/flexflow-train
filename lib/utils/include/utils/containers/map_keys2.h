#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_MAP_KEYS2_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_MAP_KEYS2_H

#include "utils/containers/keys.h"
#include <libassert/assert.hpp>
#include <map>

namespace FlexFlow {

template <typename K,
          typename V,
          typename F,
          typename K2 = std::invoke_result_t<F, K, V>>
std::map<K2, V> map_keys2(std::map<K, V> const &m, F const &f) {

  std::map<K2, V> result;
  for (auto const &kv : m) {
    result.insert({f(kv.first, kv.second), kv.second});
  }

  ASSERT(m.size() == result.size(),
         "keys passed to map_keys must be transformed into distinct keys");

  return result;
}

} // namespace FlexFlow

#endif
