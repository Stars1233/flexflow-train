#include "utils/containers/map_values.h"
#include "test/utils/doctest/fmt/map.h"
#include <doctest/doctest.h>
#include <map>
#include <string>

using namespace FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("map_values") {
    std::map<int, std::string> m = {{1, "one"}, {3, "three"}};
    auto f = [](std::string const &s) { return s.size(); };
    std::map<int, size_t> result = map_values(m, f);
    std::map<int, size_t> correct = {{1, 3}, {3, 5}};
    CHECK(result == correct);
  }
}
