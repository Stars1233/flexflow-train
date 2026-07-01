#include "utils/containers/get_all_permutations.h"
#include "test/utils/doctest/fmt/multiset.h"
#include "test/utils/doctest/fmt/vector.h"
#include "utils/containers/multiset_of.h"
#include "utils/hash/vector.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("get_all_permutations") {
    SUBCASE("input size 1") {
      std::vector<int> input = {1};

      std::multiset<std::vector<int>> result =
          multiset_of(get_all_permutations(input));
      std::multiset<std::vector<int>> correct = {{1}};

      CHECK(result == correct);
    }

    SUBCASE("input size 3") {
      std::vector<int> input = {2, 1, 3};

      std::multiset<std::vector<int>> result =
          multiset_of(get_all_permutations(input));
      std::multiset<std::vector<int>> correct = {
          {1, 2, 3},
          {1, 3, 2},
          {2, 1, 3},
          {2, 3, 1},
          {3, 1, 2},
          {3, 2, 1},
      };

      CHECK(result == correct);
    }

    SUBCASE("elements repeated") {
      std::vector<int> input = {1, 2, 2};

      std::multiset<std::vector<int>> result =
          multiset_of(get_all_permutations(input));
      std::multiset<std::vector<int>> correct = {
          {1, 2, 2},
          {2, 1, 2},
          {2, 2, 1},
      };

      CHECK(result == correct);
    }
  }
}
