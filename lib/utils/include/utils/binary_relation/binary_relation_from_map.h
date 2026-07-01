#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_BINARY_RELATION_BINARY_RELATION_FROM_MAP_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_BINARY_RELATION_BINARY_RELATION_FROM_MAP_H

#include "utils/binary_relation/binary_relation.h"
#include "utils/containers/set_of.h"
#include <map>

namespace FlexFlow {

template <typename L, typename R>
BinaryRelation<L, R> binary_relation_from_map(std::map<L, R> const &m) {
  return BinaryRelation<L, R>{
      set_of(m),
  };
}

} // namespace FlexFlow

#endif
