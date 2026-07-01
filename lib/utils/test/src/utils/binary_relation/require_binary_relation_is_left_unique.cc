#include "utils/binary_relation/require_binary_relation_is_left_unique.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("require_binary_relation_is_left_unique") {
    SUBCASE("relation is left unique") {
      BinaryRelation<int, std::string> rel = BinaryRelation<int, std::string>{
          {
              1,
              "one",
          },
          {
              2,
              "two",
          },
          {
              2,
              "TWO",
          },
      };

      OneToMany<int, std::string> result =
          require_binary_relation_is_left_unique(rel);
      OneToMany<int, std::string> correct = {
          {1, {"one"}},
          {2, {"two", "TWO"}},
      };

      CHECK(result == correct);
    }

    SUBCASE("relation is not left unique") {
      BinaryRelation<int, std::string> rel = BinaryRelation<int, std::string>{
          {
              1,
              "odd",
          },
          {
              2,
              "even",
          },
          {
              3,
              "odd",
          },
      };

      CHECK_THROWS(require_binary_relation_is_left_unique(rel));
    }
  }
}
