#include "utils/containers/find_element.h"
#include "test/utils/doctest/fmt/optional.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("find_element") {
    SUBCASE("input vector is empty") {
      std::vector<int> input_vector = {};

      std::optional<int> result =
          find_element(input_vector, [](int) { return true; });
      std::optional<int> correct = std::nullopt;

      CHECK(result == correct);
    }

    SUBCASE("no element matches condition") {
      std::vector<int> input_vector = {1, 3, 2, 3};

      std::optional<int> result =
          find_element(input_vector, [](int) { return false; });
      std::optional<int> correct = std::nullopt;

      CHECK(result == correct);
    }

    SUBCASE("multiple elements match condition") {
      std::vector<int> input_vector = {1, 3, 2, 3};

      std::optional<int> result =
          find_element(input_vector, [](int x) { return x > 2; });
      std::optional<int> correct = 3;

      CHECK(result == correct);
    }
  }
}
