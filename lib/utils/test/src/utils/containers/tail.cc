#include "utils/containers/tail.h"
#include "test/utils/doctest/fmt/vector.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("tail") {
    SUBCASE("input vector is empty") {
      std::vector<int> input = {};

      CHECK_THROWS(tail(input));
    }

    SUBCASE("input vector is not empty") {
      std::vector<int> input = {1, 3, 2, 3};

      std::vector<int> result = tail(input);
      std::vector<int> correct = {3, 2, 3};

      CHECK(result == correct);
    }
  }
}
