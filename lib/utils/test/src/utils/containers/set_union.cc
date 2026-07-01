#include "utils/containers/set_union.h"
#include "test/utils/doctest/fmt/set.h"
#include <doctest/doctest.h>
#include <set>

using namespace FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("set_union") {
    std::set<int> s1 = {1, 2, 3};
    std::set<int> s2 = {2, 3, 4};
    std::set<int> result = set_union(s1, s2);
    std::set<int> correct = {1, 2, 3, 4};
    CHECK(result == correct);
  }
}
