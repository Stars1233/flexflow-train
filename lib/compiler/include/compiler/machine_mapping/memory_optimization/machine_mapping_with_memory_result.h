#ifndef _FLEXFLOW_COMPILER_MACHINE_MAPPING_MEMORY_OPTIMIZATION_MACHINE_MAPPING_RESULT_WITH_MEMORY_H
#define _FLEXFLOW_COMPILER_MACHINE_MAPPING_MEMORY_OPTIMIZATION_MACHINE_MAPPING_RESULT_WITH_MEMORY_H

#include "compiler/machine_mapping/machine_resource_split.dtg.h"
#include "compiler/machine_mapping/memory_optimization/pareto_optimal_machine_mapping.dtg.h"
#include "compiler/machine_mapping/parallel_split_transformation.dtg.h"
#include <optional>

namespace FlexFlow {

struct MachineMappingWithMemoryResult {
  MachineMappingWithMemoryResult() = delete;

  explicit MachineMappingWithMemoryResult(
      std::set<ParetoOptimalMachineMapping> const &);

  [[nodiscard]] bool operator==(MachineMappingWithMemoryResult const &) const;
  [[nodiscard]] bool operator!=(MachineMappingWithMemoryResult const &) const;

  [[nodiscard]] bool operator<(MachineMappingWithMemoryResult const &) const;
  [[nodiscard]] bool operator>(MachineMappingWithMemoryResult const &) const;
  [[nodiscard]] bool operator<=(MachineMappingWithMemoryResult const &) const;
  [[nodiscard]] bool operator>=(MachineMappingWithMemoryResult const &) const;

  [[nodiscard]] std::set<ParetoOptimalMachineMapping> const &
      get_pareto_frontier() const;

private:
  std::set<ParetoOptimalMachineMapping> m_pareto_frontier;

private:
  std::tuple<decltype(m_pareto_frontier) const &> tie() const;

  friend struct ::std::hash<MachineMappingWithMemoryResult>;
};

std::string format_as(MachineMappingWithMemoryResult const &);
std::ostream &operator<<(std::ostream &,
                         MachineMappingWithMemoryResult const &);

[[nodiscard]] MachineMappingWithMemoryResult
    empty_machine_mapping_with_memory_result();
[[nodiscard]] bool is_empty(MachineMappingWithMemoryResult const &);

[[nodiscard]] MachineMappingWithMemoryResult get_mapping_with_minimal_runtime(
    std::set<MachineMappingWithMemoryResult> const &);

[[nodiscard]] MachineMappingWithMemoryResult
    series_combine(milliseconds_t comm_cost,
                   MachineMappingWithMemoryResult const &pre_result,
                   MachineMappingWithMemoryResult const &post_result,
                   std::optional<ParallelSplitTransformation> const
                       &parallel_split_transformation);
[[nodiscard]] MachineMappingWithMemoryResult
    parallel_combine(MachineResourceSplit const &split,
                     MachineMappingWithMemoryResult const &lhs_result,
                     MachineMappingWithMemoryResult const &rhs_result);

[[nodiscard]] MachineMappingWithMemoryResult
    minimize_runtime(MachineMappingWithMemoryResult const &m1,
                     MachineMappingWithMemoryResult const &m2);

[[nodiscard]] MachineMappingWithMemoryResult
    make_singleton_machine_mapping_with_memory_result(
        OpCostMetrics cost, MachineView const &machine_view);

} // namespace FlexFlow

namespace nlohmann {

template <>
struct adl_serializer<::FlexFlow::MachineMappingWithMemoryResult> {
  static ::FlexFlow::MachineMappingWithMemoryResult from_json(json const &);
  static void to_json(json &,
                      ::FlexFlow::MachineMappingWithMemoryResult const &);
};

} // namespace nlohmann

namespace std {

template <>
struct hash<::FlexFlow::MachineMappingWithMemoryResult> {
  size_t operator()(::FlexFlow::MachineMappingWithMemoryResult const &) const;
};

} // namespace std

#endif
