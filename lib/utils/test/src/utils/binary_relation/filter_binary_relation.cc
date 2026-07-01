#include "utils/binary_relation/filter_binary_relation.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("filter_binary_relation") {
    BinaryRelation<int, std::string> rel = BinaryRelation<int, std::string>{
        {
            2,
            "even",
        },
        {
            2,
            "EVEN",
        },
        {
            3,
            "odd",
        },
        {
            1,
            "odd",
        },
    };

    BinaryRelation<int, std::string> result =
        filter_binary_relation(rel, [](int l, std::string const &r) -> bool {
          return l > 1 && r != "EVEN";
        });

    BinaryRelation<int, std::string> correct = BinaryRelation<int, std::string>{
        {
            2,
            "even",
        },
        {
            3,
            "odd",
        },
    };

    CHECK(result == correct);
  }
}
