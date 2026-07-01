#include "utils/containers/repeat_until_converged.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("repeat_until_converged") {
    SUBCASE("standard case") {
      int result = repeat_until_converged(500, [](int x) { return x / 2; });
      int correct = 0;

      CHECK(result == correct);
    }

    SUBCASE("value is already converged") {
      int result = repeat_until_converged(500, [](int x) { return x; });
      int correct = 500;

      CHECK(result == correct);
    }
  }
}
