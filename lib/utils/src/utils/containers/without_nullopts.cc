#include "utils/containers/without_nullopts.h"

namespace FlexFlow {

template std::set<int> without_nullopts(std::set<std::optional<int>> const &);
template std::vector<int>
    without_nullopts(std::vector<std::optional<int>> const &);

} // namespace FlexFlow
