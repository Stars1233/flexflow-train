#include "utils/containers/filter_keys.h"
#include "test/utils/doctest/fmt/map.h"
#include <doctest/doctest.h>
#include <map>
#include <string>

using namespace FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("filter_keys") {
    std::map<int, std::string> m = {{1, "one"}, {2, "two"}, {3, "three"}};
    auto f = [](int x) { return x % 2 == 1; };
    std::map<int, std::string> result = filter_keys(m, f);
    std::map<int, std::string> correct = {{1, "one"}, {3, "three"}};
    CHECK(result == correct);
  }
}
