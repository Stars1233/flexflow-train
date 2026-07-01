#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_BINARY_RELATION_REQUIRE_BINARY_RELATION_IS_LEFT_UNIQUE_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_BINARY_RELATION_REQUIRE_BINARY_RELATION_IS_LEFT_UNIQUE_H

#include "utils/binary_relation/binary_relation.h"
#include "utils/many_to_one/many_to_one.h"

namespace FlexFlow {

template <typename L, typename R>
ManyToOne<L, R>
    require_binary_relation_is_right_unique(BinaryRelation<L, R> const &rel) {
  ManyToOne<L, R> result;

  for (std::pair<L, R> const &p : rel.unwrap_as_set()) {
    result.insert(p);
  }

  return result;
}

} // namespace FlexFlow

#endif
