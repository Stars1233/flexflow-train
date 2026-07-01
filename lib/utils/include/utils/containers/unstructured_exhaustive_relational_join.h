#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_UNSTRUCTURED_EXHAUSTIVE_RELATIONAL_JOIN_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_UNSTRUCTURED_EXHAUSTIVE_RELATIONAL_JOIN_H

#include "utils/containers/transform.h"
#include "utils/hash/pair.h"
#include <libassert/assert.hpp>
#include <set>

namespace FlexFlow {

template <typename L, typename C, typename R>
std::set<std::pair<L, R>> unstructured_exhaustive_relational_join(
    std::set<std::pair<L, C>> const &lhs,
    std::set<std::pair<C, R>> const &rhs) {
  std::set<std::pair<L, R>> result;

  std::set<L> lhs_ls =
      transform(lhs, [](std::pair<L, C> const &lc) { return lc.first; });
  std::set<C> lhs_cs =
      transform(lhs, [](std::pair<L, C> const &lc) { return lc.second; });
  std::set<C> rhs_cs =
      transform(rhs, [](std::pair<C, R> const &cr) { return cr.first; });
  std::set<R> rhs_rs =
      transform(rhs, [](std::pair<C, R> const &cr) { return cr.second; });

  ASSERT(lhs_cs == rhs_cs);

  std::set<L> result_ls;
  std::set<R> result_rs;

  for (auto const &[l, c1] : lhs) {
    for (auto const &[c2, r] : rhs) {
      if (c1 == c2) {
        result.insert({l, r});
        result_ls.insert(l);
        result_rs.insert(r);
      }
    }
  }

  ASSERT(result_ls == lhs_ls);
  ASSERT(result_rs == rhs_rs);

  return result;
}

} // namespace FlexFlow

#endif
