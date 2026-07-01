#include "utils/containers/require_no_duplicates.h"
#include "test/utils/doctest/fmt/multiset.h"
#include "test/utils/doctest/fmt/set.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("require_no_duplicates(std::multiset<T>)") {
    SUBCASE("empty") {
      std::multiset<int> input = {};

      std::set<int> result = require_no_duplicates(input);
      std::set<int> correct = {};

      CHECK(result == correct);
    }

    SUBCASE("input has duplicates") {
      std::multiset<int> input = {1, 2, 2};

      CHECK_THROWS(require_no_duplicates(input));
    }

    SUBCASE("input does not have duplicates") {
      std::multiset<int> input = {1, 2, 4};

      std::set<int> result = require_no_duplicates(input);
      std::set<int> correct = {1, 2, 4};

      CHECK(result == correct);
    }
  }

  TEST_CASE("require_no_duplicates(std::multiset<T>)") {
    SUBCASE("empty") {
      std::multiset<int> input = {};

      std::set<int> result = require_no_duplicates(input);
      std::set<int> correct = {};

      CHECK(result == correct);
    }

    SUBCASE("input has duplicates") {
      std::multiset<int> input = {1, 2, 2};

      CHECK_THROWS(require_no_duplicates(input));
    }

    SUBCASE("input does not have duplicates") {
      std::multiset<int> input = {1, 2, 4};

      std::set<int> result = require_no_duplicates(input);
      std::set<int> correct = {1, 2, 4};

      CHECK(result == correct);
    }
  }
}
