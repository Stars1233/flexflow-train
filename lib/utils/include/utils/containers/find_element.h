#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_FIND_ELEMENT_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_CONTAINERS_FIND_ELEMENT_H

#include "utils/nonnegative_int/nonnegative_range.h"
#include "utils/nonnegative_int/num_elements.h"
#include <optional>
#include <vector>

namespace FlexFlow {

template <typename T, typename F>
std::optional<T> find_element(std::vector<T> const &v, F &&f) {
  for (nonnegative_int idx : nonnegative_range(num_elements(v))) {
    T element = v.at(idx.int_from_nonnegative_int());
    bool matches_condition = f(element);
    if (matches_condition) {
      return element;
    }
  }

  return std::nullopt;
}

} // namespace FlexFlow

#endif
