#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_BIDICT_ALGORITHMS_BIDICT_FROM_UNSTRUCTURED_RELATION_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_BIDICT_ALGORITHMS_BIDICT_FROM_UNSTRUCTURED_RELATION_H

#include "utils/bidict/bidict.h"
#include "utils/containers/filter_values.h"
#include "utils/containers/get_element_counts.h"
#include "utils/containers/multiset_of.h"
#include "utils/containers/transform.h"
#include <libassert/assert.hpp>

namespace FlexFlow {

template <typename L, typename R>
bidict<L, R> bidict_from_unstructured_relation(
    std::set<std::pair<L, R>> const &relation) {

  {
    std::multiset<L> l_values =
        transform(multiset_of(relation),
                  [](std::pair<L, R> const &p) -> L { return p.first; });

    std::map<L, positive_int> l_value_counts = get_element_counts(l_values);

    std::map<L, positive_int> duplicated_element_counts =
        filter_values(l_value_counts, [](positive_int num_occurences) -> bool {
          return num_occurences > 1;
        });

    ASSERT(duplicated_element_counts.empty(), duplicated_element_counts);
  }

  {
    std::multiset<R> r_values =
        transform(multiset_of(relation),
                  [](std::pair<L, R> const &p) -> R { return p.second; });

    std::map<R, positive_int> r_value_counts = get_element_counts(r_values);

    std::map<R, positive_int> duplicated_element_counts =
        filter_values(r_value_counts, [](positive_int num_occurences) -> bool {
          return num_occurences > 1;
        });

    ASSERT(duplicated_element_counts.empty(), duplicated_element_counts);
  }

  return bidict<L, R>{relation.begin(), relation.end()};
}

} // namespace FlexFlow

#endif
