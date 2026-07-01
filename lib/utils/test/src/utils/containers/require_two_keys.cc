#include "utils/containers/require_two_keys.h"
#include "test/utils/doctest/fmt/pair.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("require_two_keys") {
    SUBCASE("input is too small") {
      std::map<int, std::string> m = {
          {2, "a"},
      };

      CHECK_THROWS(require_two_keys(m, 2, 3));
    }

    SUBCASE("input is too large") {
      std::map<int, std::string> m = {
          {2, "a"},
          {3, "b"},
          {4, "c"},
      };

      CHECK_THROWS(require_two_keys(m, 2, 3));
    }

    SUBCASE("input is correct size, but keys don't match") {
      std::map<int, std::string> m = {
          {2, "a"},
          {4, "c"},
      };

      CHECK_THROWS(require_two_keys(m, 2, 3));
    }

    SUBCASE("input is correct size and both keys are the same") {
      std::map<int, std::string> m = {
          {2, "a"},
          {3, "b"},
      };

      CHECK_THROWS(require_two_keys(m, 2, 2));
    }

    SUBCASE("input is correct size and keys match") {
      std::map<int, std::string> m = {
          {2, "a"},
          {4, "c"},
      };

      std::pair<std::string, std::string> result = require_two_keys(m, 2, 4);
      std::pair<std::string, std::string> correct = {"a", "c"};

      CHECK(result == correct);
    }
  }
}
