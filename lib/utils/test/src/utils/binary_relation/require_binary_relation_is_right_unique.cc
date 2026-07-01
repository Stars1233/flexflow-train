#include "utils/binary_relation/require_binary_relation_is_right_unique.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("require_binary_relation_is_right_unique") {
    SUBCASE("relation is right unique") {
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

      ManyToOne<int, std::string> result =
          require_binary_relation_is_right_unique(rel);
      ManyToOne<int, std::string> correct = {
          {{1, 3}, "odd"},
          {{2}, "even"},
      };

      CHECK(result == correct);
    }

    SUBCASE("relation is not right unique") {
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

      CHECK_THROWS(require_binary_relation_is_right_unique(rel));
    }
  }
}
