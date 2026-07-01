#include "utils/containers/multiset_union.h"
#include "test/utils/doctest/fmt/multiset.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("multiset_union(std::multiset<T>, "
            "std::multiset<T>)") {
    std::multiset<int> input_lhs = {1, 2, 2, 3};
    std::multiset<int> input_rhs = {1, 2, 5};

    std::multiset<int> result = multiset_union(input_lhs, input_rhs);
    std::multiset<int> correct = {1, 1, 2, 2, 2, 3, 5};

    CHECK(result == correct);
  }

  TEST_CASE("multiset_union(std::multiset<T>, std::multiset<T>)") {
    std::multiset<int> input_lhs = {1, 2, 2, 3};
    std::multiset<int> input_rhs = {1, 2, 5};

    std::multiset<int> result = multiset_union(input_lhs, input_rhs);
    std::multiset<int> correct = {1, 1, 2, 2, 2, 3, 5};

    CHECK(result == correct);
  }
}
