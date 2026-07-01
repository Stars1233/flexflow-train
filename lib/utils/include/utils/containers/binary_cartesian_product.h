#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_BINARY_CARTESIAN_PRODUCT_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_BINARY_CARTESIAN_PRODUCT_H

#include <set>

namespace FlexFlow {

template <typename A, typename B>
std::set<std::pair<A, B>> binary_cartesian_product(std::set<A> const &lhs,
                                                   std::set<B> const &rhs) {
  std::set<std::pair<A, B>> result;

  for (A const &a : lhs) {
    for (B const &b : rhs) {
      result.insert({a, b});
    }
  }

  return result;
}

} // namespace FlexFlow

#endif
