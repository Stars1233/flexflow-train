#include "test/utils/doctest/fmt/map.h"
#include "test/utils/doctest/fmt/optional.h"
#include "utils/containers/try_merge_nondisjoint_maps.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("try_merge_nondisjoing_maps(std::map<K, V>, "
            "std::map<K, V>)") {
    std::map<int, std::string> d1 = {
        {0, "zero"},
        {1, "one"},
    };
    std::map<int, std::string> d2 = {
        {0, "zero"},
        {2, "two"},
    };

    SUBCASE("compatible neither superset") {
      std::optional<std::map<int, std::string>> result =
          try_merge_nondisjoint_maps(d1, d2);
      std::optional<std::map<int, std::string>> correct = {{
          {0, "zero"},
          {1, "one"},
          {2, "two"},
      }};
      CHECK(result == correct);
    }

    SUBCASE("mismatched key") {
      d1.insert({2, "three"});
      std::optional<std::map<int, std::string>> result =
          try_merge_nondisjoint_maps(d1, d2);
      std::optional<std::map<int, std::string>> correct = std::nullopt;
      CHECK(result == correct);
    }

    SUBCASE("repeated value") {
      d1.insert({3, "one"});
      std::optional<std::map<int, std::string>> result =
          try_merge_nondisjoint_maps(d1, d2);
      std::optional<std::map<int, std::string>> correct = {{
          {0, "zero"},
          {1, "one"},
          {2, "two"},
          {3, "one"},
      }};
      CHECK(result == correct);
    }

    SUBCASE("left superset") {
      d1.insert({2, "two"});
      std::optional<std::map<int, std::string>> result =
          try_merge_nondisjoint_maps(d1, d2);
      std::optional<std::map<int, std::string>> correct = d1;
      CHECK(result == correct);
    }

    SUBCASE("right superset") {
      d2.insert({1, "one"});
      std::optional<std::map<int, std::string>> result =
          try_merge_nondisjoint_maps(d1, d2);
      std::optional<std::map<int, std::string>> correct = d2;
      CHECK(result == correct);
    }

    SUBCASE("equal") {
      d1.insert({2, "two"});
      d2.insert({1, "one"});
      std::optional<std::map<int, std::string>> result =
          try_merge_nondisjoint_maps(d1, d2);
      std::optional<std::map<int, std::string>> correct = d1;
      CHECK(result == correct);
    }
  }
}
