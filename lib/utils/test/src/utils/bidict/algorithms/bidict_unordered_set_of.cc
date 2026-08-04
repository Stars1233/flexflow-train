#include "utils/bidict/algorithms/bidict_unordered_set_of.h"
#include "test/utils/doctest/fmt/pair.h"
#include "test/utils/doctest/fmt/unordered_set.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("bidict_unordered_set_of(bidict<K, V>)") {
    bidict<int, std::string> b = {
        {1, "one"},
        {2, "two"},
    };

    std::unordered_set<std::pair<int, std::string>> result =
        bidict_unordered_set_of(b);

    std::unordered_set<std::pair<int, std::string>> correct = {
        {1, "one"},
        {2, "two"},
    };

    CHECK(result == correct);
  }
}
