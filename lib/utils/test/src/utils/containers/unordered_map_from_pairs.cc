#include "test/utils/doctest/fmt/map.h"
#include "utils/containers/contains.h"
#include "utils/containers/map_from_pairs.h"
#include <doctest/doctest.h>
#include <string>
#include <vector>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("map_from_pairs") {
    SUBCASE("nonempty input") {
      std::vector<std::pair<int, std::string>> input = {
          {1, "hello"},
          {3, "world"},
      };

      std::map<int, std::string> result = map_from_pairs(input);
      std::map<int, std::string> correct = {
          {1, "hello"},
          {3, "world"},
      };

      CHECK(result == correct);
    }

    SUBCASE("empty input") {
      std::vector<std::pair<int, std::string>> input = {};

      std::map<int, std::string> result = map_from_pairs(input);
      std::map<int, std::string> correct = {};

      CHECK(result == correct);
    }

    SUBCASE("input with duplicate keys") {
      std::vector<std::pair<int, std::string>> input = {
          {1, "a"},
          {2, "c"},
          {1, "b"},
      };

      std::map<int, std::string> result = map_from_pairs(input);

      std::vector<std::map<int, std::string>> possible_correct_values = {
          {{1, "a"}, {2, "c"}},
          {{1, "b"}, {2, "c"}},
      };

      CHECK(contains(possible_correct_values, result));
    }
  }
}
