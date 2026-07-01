#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_BIDICT_ALGORITHMS_UNSTRUCTURED_RELATION_FROM_BIDICT_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_BIDICT_ALGORITHMS_UNSTRUCTURED_RELATION_FROM_BIDICT_H

#include "utils/bidict/bidict.h"

namespace FlexFlow {

template <typename L, typename R>
std::set<std::pair<L, R>>
    unstructured_relation_from_bidict(bidict<L, R> const &b) {

  std::set<std::pair<L, R>> result;

  for (auto const &lr : b) {
    result.insert(lr);
  }

  return result;
}

} // namespace FlexFlow

#endif
