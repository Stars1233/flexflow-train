#include "utils/containers/get_one_of.h"
#include "utils/containers/contains.h"
#include <doctest/doctest.h>
#include <set>
using namespace FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("get_one_of") {
    SUBCASE("non-empty set") {
      std::set<int> s = {1, 2, 3};
      CHECK(contains(s, get_one_of(s)));
    }

    SUBCASE("empty set") {
      std::set<int> s = {};
      CHECK_THROWS(get_one_of(s));
    }
  }
}
