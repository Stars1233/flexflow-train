#include "op-attrs/ff_ordered/ff_ordered_slice_inclusive.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("ff_ordered_slice_inclusive(FFOrdered<T>, ..., ...") {
    FFOrdered<size_t> d = FFOrdered<size_t>{
        1,
        2,
        3,
        4,
    };

    SUBCASE("ff_dim_t, ff_dim_t") {
      FFOrdered<size_t> result =
          ff_ordered_slice_inclusive(d, ff_dim_t{1_n}, ff_dim_t{2_n});
      FFOrdered<size_t> correct = FFOrdered<size_t>{2, 3};

      CHECK(result == correct);
    }

    SUBCASE("ff_dim_t, std::nullopt_t") {
      FFOrdered<size_t> result =
          ff_ordered_slice_inclusive(d, ff_dim_t{1_n}, std::nullopt);
      FFOrdered<size_t> correct = FFOrdered<size_t>{2, 3, 4};

      CHECK(result == correct);
    }

    SUBCASE("relative_ff_dim_t, relative_ff_dim_t") {
      FFOrdered<size_t> result = ff_ordered_slice_inclusive(
          d, relative_ff_dim_t{1}, relative_ff_dim_t{-1});
      FFOrdered<size_t> correct = FFOrdered<size_t>{2, 3, 4};

      CHECK(result == correct);
    }

    SUBCASE("relative_ff_dim_t, std::nullopt_t") {
      FFOrdered<size_t> result =
          ff_ordered_slice_inclusive(d, relative_ff_dim_t{-3}, std::nullopt);
      FFOrdered<size_t> correct = FFOrdered<size_t>{2, 3, 4};

      CHECK(result == correct);
    }

    SUBCASE("start index = stop index") {
      FFOrdered<size_t> result = ff_ordered_slice_inclusive(
          d, relative_ff_dim_t{1}, relative_ff_dim_t{1});
      FFOrdered<size_t> correct = FFOrdered<size_t>{2};

      CHECK(result == correct);
    }

    SUBCASE("start index = stop index + 1") {
      FFOrdered<size_t> result = ff_ordered_slice_inclusive(
          d, relative_ff_dim_t{2}, relative_ff_dim_t{1});
      FFOrdered<size_t> correct = FFOrdered<size_t>{};

      CHECK(result == correct);
    }

    SUBCASE("start index = stop index (using negative indexing)") {
      FFOrdered<size_t> result = ff_ordered_slice_inclusive(
          d, relative_ff_dim_t{1}, relative_ff_dim_t{-3});
      FFOrdered<size_t> correct = FFOrdered<size_t>{2};

      CHECK(result == correct);
    }

    SUBCASE("start index = stop index + 1 (using negative indexing)") {
      FFOrdered<size_t> result = ff_ordered_slice_inclusive(
          d, relative_ff_dim_t{1}, relative_ff_dim_t{-4});
      FFOrdered<size_t> correct = FFOrdered<size_t>{};

      CHECK(result == correct);
    }

    SUBCASE("start index > stop index") {
      FFOrdered<size_t> result = ff_ordered_slice_inclusive(
          d, relative_ff_dim_t{1}, relative_ff_dim_t{0});
      FFOrdered<size_t> correct = FFOrdered<size_t>{};

      CHECK(result == correct);
    }

    SUBCASE("start index > stop index (using negative indexing)") {
      FFOrdered<size_t> result = ff_ordered_slice_inclusive(
          d, relative_ff_dim_t{1}, relative_ff_dim_t{-4});
      FFOrdered<size_t> correct = FFOrdered<size_t>{};

      CHECK(result == correct);
    }

    SUBCASE("start index out of bounds (too low)") {
      CHECK_THROWS(
          ff_ordered_slice_inclusive(d, relative_ff_dim_t{-5}, std::nullopt));
    }

    SUBCASE("start index out of bounds (too high)") {
      CHECK_THROWS(
          ff_ordered_slice_inclusive(d, relative_ff_dim_t{4}, std::nullopt));
    }

    SUBCASE("stop index out of bounds (too low)") {
      CHECK_THROWS(ff_ordered_slice_inclusive(
          d, relative_ff_dim_t{0}, relative_ff_dim_t{-5}));
    }

    SUBCASE("stop index out of bounds (too high)") {
      CHECK_THROWS(ff_ordered_slice_inclusive(
          d, relative_ff_dim_t{0}, relative_ff_dim_t{4}));
    }
  }
}
