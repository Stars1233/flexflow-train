#include "utils/containers/are_disjoint.h"
#include <doctest/doctest.h>
#include <set>

using namespace FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("are_disjoint") {
    SUBCASE("disjoint") {
      std::set<int> l = {1, 2, 3};
      std::set<int> r = {4, 5, 6};
      CHECK(are_disjoint(l, r));
    }
    SUBCASE("not disjoint") {
      std::set<int> l = {1, 2, 3, 4};
      std::set<int> r = {3, 4, 5, 6};
      CHECK_FALSE(are_disjoint(l, r));
    }

    SUBCASE("one empty set") {
      std::set<int> l = {1, 2};
      std::set<int> r = {};
      CHECK(are_disjoint(l, r));
    }
    SUBCASE("both empty sets") {
      std::set<int> l = {};
      std::set<int> r = {};
      CHECK(are_disjoint(l, r));
    }
  }
}
