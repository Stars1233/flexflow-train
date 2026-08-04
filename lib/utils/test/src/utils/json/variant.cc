#include "utils/json/variant.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("json serialization for std::variant") {
    SUBCASE("variant entry 0") {
      std::variant<int, std::string> x = 5;

      nlohmann::json result = x;

      nlohmann::json correct = {
          {"index", 0},
          {"value", 5},
      };

      CHECK(result == correct);
    }

    SUBCASE("variant entry 1") {
      std::variant<int, std::string> x = "hello";

      nlohmann::json result = x;

      nlohmann::json correct = {
          {"index", 1},
          {"value", "hello"},
      };

      CHECK(result == correct);
    }
  }
}
