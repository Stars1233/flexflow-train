#include "test/utils/doctest/fmt/set.h"
#include "utils/containers/set_of.h"
#include <doctest/doctest.h>
#include <vector>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("set_of") {
    std::vector<int> input = {1, 2, 3, 3, 2, 3};
    std::set<int> result = set_of(input);
    std::set<int> correct = {1, 2, 3};
    CHECK(result == correct);
  }
}
