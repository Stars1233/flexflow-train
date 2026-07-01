#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_BINARY_RELATION_FILTER_BINARY_RELATION_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_BINARY_RELATION_FILTER_BINARY_RELATION_H

#include "utils/binary_relation/binary_relation.h"
#include "utils/containers/filter.h"

namespace FlexFlow {

template <typename L, typename R, typename F>
BinaryRelation<L, R> filter_binary_relation(BinaryRelation<L, R> const &rel,
                                            F &&f) {
  return BinaryRelation<L, R>{
      filter(rel.unwrap_as_set(),
             [&](std::pair<L, R> const &p) -> bool {
               return f(p.first, p.second);
             }),
  };
}

} // namespace FlexFlow

#endif
