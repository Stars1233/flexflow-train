#include "utils/containers/recurse_n.h"
#include <doctest/doctest.h>
#include <string>

using namespace FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("recurse_n") {
    auto append_bar = [](std::string const &x) {
      return x + std::string("Bar");
    };

    SUBCASE("n = 0") {
      std::string result = recurse_n(append_bar, 0_n, std::string("Foo"));
      std::string correct = "Foo";
      CHECK(result == correct);
    }

    SUBCASE("n = 3") {
      std::string result = recurse_n(append_bar, 3_n, std::string("Foo"));
      std::string correct = "FooBarBarBar";
      CHECK(result == correct);
    }
  }
}
