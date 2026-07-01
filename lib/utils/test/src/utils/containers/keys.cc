#include "utils/containers/keys.h"
#include "test/utils/doctest/fmt/set.h"
#include <doctest/doctest.h>
#include <map>
#include <set>
#include <string>

using namespace FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("keys") {
    std::map<int, std::string> m = {{1, "one"}, {2, "two"}, {3, "three"}};
    std::set<int> result = keys(m);
    std::set<int> expected = {1, 2, 3};
    CHECK(result == expected);
  }
}
