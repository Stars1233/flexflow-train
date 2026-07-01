#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_BIDICT_ALGORITHMS_BIDICT_TRANSFORM_KEYS_AND_VALUES_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_BIDICT_ALGORITHMS_BIDICT_TRANSFORM_KEYS_AND_VALUES_H

#include "utils/bidict/bidict.h"

namespace FlexFlow {

template <typename K,
          typename V,
          typename KF,
          typename VF,
          typename K2 = std::invoke_result_t<KF, K>,
          typename V2 = std::invoke_result_t<VF, V>>
bidict<K2, V2>
    bidict_transform_keys_and_values(bidict<K, V> const &m, KF &&kf, VF &&vf) {
  bidict<K2, V2> result;
  for (auto const &kv : m) {
    result.equate_strict(kf(kv.first), vf(kv.second));
  }
  return result;
}

} // namespace FlexFlow

#endif
