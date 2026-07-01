#include "utils/containers/flatmap.h"
#include "test/utils/doctest/fmt/map.h"
#include "test/utils/doctest/fmt/pair.h"
#include "test/utils/doctest/fmt/set.h"
#include "test/utils/doctest/fmt/vector.h"
#include "utils/containers/map_keys.h"
#include "utils/hash/pair.h"
#include <doctest/doctest.h>
#include <string>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("flatmap(std::vector<T>, F)") {
    SUBCASE("same data-type") {
      auto get_factors = [](int x) -> std::vector<int> {
        // Returns a vector of factors of x
        std::vector<int> factors;
        for (int i = 1; i <= x; i++) {
          if (x % i == 0) {
            factors.push_back(i);
          }
        }
        return factors;
      };

      std::vector<int> input = {2, 3, 4, 5};
      std::vector<int> result = flatmap(input, get_factors);
      std::vector<int> correct = {1, 2, 1, 3, 1, 2, 4, 1, 5};
      CHECK(result == correct);
    }

    SUBCASE("different data-type") {
      auto get_string_sequence = [](int x) -> std::vector<std::string> {
        return {
            std::to_string(x - 1), std::to_string(x), std::to_string(2 * x)};
      };

      std::vector<int> input = {2, 4, 10};
      std::vector<std::string> result = flatmap(input, get_string_sequence);
      std::vector<std::string> correct = {
          "1", "2", "4", "3", "4", "8", "9", "10", "20"};
      CHECK(result == correct);
    }
  }

  TEST_CASE("flatmap(std::set<T>, F)") {
    auto get_chars = [](std::string const &s) {
      std::set<char> result;
      for (char c : s) {
        result.insert(c);
      }
      return result;
    };

    SUBCASE("type changing") {
      std::set<std::string> input = {"hello", " ", "", "world", "!"};

      std::set<char> result = flatmap(input, get_chars);
      std::set<char> correct = {'h', 'e', 'l', 'o', ' ', 'w', 'r', 'd', '!'};

      CHECK(result == correct);
    }

    SUBCASE("input is empty") {
      std::set<std::string> input = {};

      std::set<char> result = flatmap(input, get_chars);
      std::set<char> correct = {};

      CHECK(result == correct);
    }
  }

  TEST_CASE("flatmap(std::string, F)") {
    std::string input = "aBabcBc";

    SUBCASE("replacement length > 1") {
      std::string result = flatmap(input, [](char c) -> std::string {
        if (c == 'B') {
          return "..";
        } else {
          return std::string{c};
        }
      });

      std::string correct = "a..abc..c";

      CHECK(result == correct);
    }

    SUBCASE("replacement length == 0") {
      std::string result = flatmap(input, [](char c) -> std::string {
        if (c == 'B') {
          return "";
        } else {
          return std::string{c};
        }
      });

      std::string correct = "aabcc";

      CHECK(result == correct);
    }
  }

  TEST_CASE("flatmap(std::map<K, V>, F)") {
    auto de_nest_keys = [](int k1, std::map<int, std::string> const &v) {
      return map_keys(v, [&](int k2) { return std::pair{k1, k2}; });
    };

    SUBCASE("input is empty") {
      std::map<int, std::map<int, std::string>> input = {};

      std::map<std::pair<int, int>, std::string> result =
          flatmap(input, de_nest_keys);
      std::map<std::pair<int, int>, std::string> correct = {};

      CHECK(result == correct);
    }

    SUBCASE("input is not empty") {
      std::map<int, std::map<int, std::string>> input = {
          {
              1,
              {
                  {2, "a"},
                  {3, "b"},
              },
          },
          {
              2,
              {},
          },
          {
              3,
              {
                  {3, "a"},
              },
          },
      };

      std::map<std::pair<int, int>, std::string> result =
          flatmap(input, de_nest_keys);
      std::map<std::pair<int, int>, std::string> correct = {
          {{1, 2}, "a"},
          {{1, 3}, "b"},
          {{3, 3}, "a"},
      };

      CHECK(result == correct);
    }

    SUBCASE("duplicate result keys") {
      auto always_return_same_map = [](int, std::string const &) {
        return std::map<std::string, int>{
            {"mykey", 10000},
        };
      };

      std::map<int, std::string> input = {
          {1, "a"},
          {2, "b"},
      };

      CHECK_THROWS(flatmap(input, always_return_same_map));
    }
  }
}
