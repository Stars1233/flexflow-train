#include "utils/containers/get_all_assignments.h"
#include "test/utils/doctest/fmt/map.h"
#include "test/utils/doctest/fmt/set.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("get_all_assignments") {
    SUBCASE("empty input") {
      std::map<std::string, std::set<int>> input = {};

      std::set<std::map<std::string, int>> result = get_all_assignments(input);
      std::set<std::map<std::string, int>> correct = {{}};

      CHECK(result == correct);
    }

    SUBCASE("non-empty input") {
      std::map<std::string, std::set<int>> input = {
          {"a", {1, 2, 3}},
          {"b", {2, 3}},
      };

      std::set<std::map<std::string, int>> result = get_all_assignments(input);
      std::set<std::map<std::string, int>> correct = {
          {{"a", 1}, {"b", 2}},
          {{"a", 1}, {"b", 3}},
          {{"a", 2}, {"b", 2}},
          {{"a", 2}, {"b", 3}},
          {{"a", 3}, {"b", 2}},
          {{"a", 3}, {"b", 3}},
      };

      CHECK(result == correct);
    }

    SUBCASE("one possible-values set is empty") {
      std::map<std::string, std::set<int>> input = {
          {"a", {}},
          {"b", {2, 3}},
      };

      std::set<std::map<std::string, int>> result = get_all_assignments(input);
      std::set<std::map<std::string, int>> correct = {};

      CHECK(result == correct);
    }
  }
}
