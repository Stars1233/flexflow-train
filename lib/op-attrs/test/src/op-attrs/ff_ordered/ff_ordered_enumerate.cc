#include "op-attrs/ff_ordered/ff_ordered_enumerate.h"
#include "test/utils/doctest/fmt/map.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("ff_ordered_enumerate(FFOrdered<T>)") {
    FFOrdered<std::string> input = FFOrdered<std::string>{"zero", "one", "two"};

    std::map<ff_dim_t, std::string> result = ff_ordered_enumerate(input);
    std::map<ff_dim_t, std::string> correct = {
        {ff_dim_t{nonnegative_int{0}}, "zero"},
        {ff_dim_t{nonnegative_int{1}}, "one"},
        {ff_dim_t{nonnegative_int{2}}, "two"},
    };

    CHECK(result == correct);
  }
}
