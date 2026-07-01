#include "utils/binary_relation/binary_relation.h"
#include "test/utils/doctest/fmt/multiset.h"
#include "test/utils/doctest/fmt/pair.h"
#include "test/utils/doctest/fmt/set.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("BinaryRelation") {
    SUBCASE("default constructor") {
      BinaryRelation<int, std::string> b;

      CHECK(b.empty());
      CHECK(b.size() == 0);

      std::set<std::pair<int, std::string>> raw = b.unwrap_as_set();
      std::set<std::pair<int, std::string>> correct_raw = {};

      CHECK(raw == correct_raw);
    }

    SUBCASE("initializer_list constuctor") {
      BinaryRelation<int, std::string> b = BinaryRelation<int, std::string>{
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

      CHECK(b.size() == 4);
      CHECK(!b.empty());

      std::set<std::pair<int, std::string>> raw = b.unwrap_as_set();
      std::set<std::pair<int, std::string>> correct_raw = {
          {2, "even"},
          {2, "EVEN"},
          {3, "odd"},
          {1, "odd"},
      };

      CHECK(raw == correct_raw);
    }

    BinaryRelation<int, std::string> empty_rel;

    BinaryRelation<int, std::string> b = BinaryRelation<int, std::string>{
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

    SUBCASE("left_values") {
      std::set<int> result = b.left_values();
      std::set<int> correct = {1, 2, 3};

      CHECK(result == correct);
    }

    SUBCASE("right_values") {
      std::set<std::string> result = b.right_values();
      std::set<std::string> correct = {"odd", "even", "EVEN"};

      CHECK(result == correct);
    }

    SUBCASE("left_value_occurences") {
      std::multiset<int> result = b.left_value_occurences();
      std::multiset<int> correct = {1, 2, 2, 3};

      CHECK(result == correct);
    }

    SUBCASE("right_value_occurences") {
      std::multiset<std::string> result = b.right_value_occurences();
      std::multiset<std::string> correct = {
          "odd",
          "odd",
          "even",
          "EVEN",
      };

      CHECK(result == correct);
    }

    SUBCASE("at_l") {
      std::set<std::string> result = b.at_l(2);
      std::set<std::string> correct = {"even", "EVEN"};

      CHECK(result == correct);
    }

    SUBCASE("at_r") {
      std::set<int> result = b.at_r("odd");
      std::set<int> correct = {1, 3};

      CHECK(result == correct);
    }
  }
}
