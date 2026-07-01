#ifndef _FLEXFLOW_UTILS_INCLUDE_UTILS_CONTAINERS_ARE_ALL_DISTINCT_H
#define _FLEXFLOW_UTILS_INCLUDE_UTILS_CONTAINERS_ARE_ALL_DISTINCT_H

#include "utils/containers/multiset_of.h"
#include "utils/containers/set_of.h"

namespace FlexFlow {

template <typename C>
bool are_all_distinct(C const &c) {
  return set_of(c).size() == multiset_of(c).size();
}

} // namespace FlexFlow

#endif
