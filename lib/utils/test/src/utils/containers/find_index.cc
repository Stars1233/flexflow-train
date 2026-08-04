#include "utils/containers/find_index.h"
#include "test/utils/doctest/fmt/optional.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("find_index") {
    SUBCASE("input vector is empty") {
      std::vector<int> input_vector = {};

      std::optional<nonnegative_int> result =
          find_index(input_vector, [](int) { return true; });
      std::optional<nonnegative_int> correct = std::nullopt;

      CHECK(result == correct);
    }

    SUBCASE("no element matches condition") {
      std::vector<int> input_vector = {1, 3, 2, 3};

      std::optional<nonnegative_int> result =
          find_index(input_vector, [](int) { return false; });
      std::optional<nonnegative_int> correct = std::nullopt;

      CHECK(result == correct);
    }

    SUBCASE("multiple elements match condition") {
      std::vector<int> input_vector = {1, 3, 2, 3};

      std::optional<nonnegative_int> result =
          find_index(input_vector, [](int x) { return x > 2; });
      std::optional<nonnegative_int> correct = 1_n;

      CHECK(result == correct);
    }
  }
}
