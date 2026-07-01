#include "utils/fmt/expected.h"
#include <doctest/doctest.h>
#include <fmt/format.h>
#include <map>
#include <set>
#include <sstream>
#include <tl/expected.hpp>
#include <vector>

using namespace FlexFlow;

namespace doctest {

#define CHECK_WITHOUT_STRINGIFY(...)                                           \
  do {                                                                         \
    bool result = __VA_ARGS__;                                                 \
    CHECK(result);                                                             \
  } while (0);

#define CHECK_FALSE_WITHOUT_STRINGIFY(...)                                     \
  do {                                                                         \
    bool result = __VA_ARGS__;                                                 \
    CHECK_FALSE(result);                                                       \
  } while (0);

} // namespace doctest
