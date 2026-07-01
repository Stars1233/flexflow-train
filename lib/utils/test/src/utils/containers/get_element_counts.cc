#include "utils/containers/get_element_counts.h"
#include "test/utils/doctest/fmt/map.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("get_element_counts") {
    std::vector<int> input = {1, 2, 3, 2, 3, 3, 2, 3};
    std::map<int, positive_int> result = get_element_counts(input);
    std::map<int, positive_int> correct = {{1, 1_p}, {2, 3_p}, {3, 4_p}};
    CHECK(result == correct);
  }
}
