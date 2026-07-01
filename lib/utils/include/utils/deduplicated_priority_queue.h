#ifndef _FLEXFLOW_UTILS_DEDUPLICATED_PRIORITY_QUEUE_H
#define _FLEXFLOW_UTILS_DEDUPLICATED_PRIORITY_QUEUE_H

#include "utils/containers/contains.h"
#include <queue>
#include <set>
#include <vector>

namespace FlexFlow {

template <typename Elem,
          typename Container = std::vector<Elem>,
          typename Compare = std::less<typename Container::value_type>>
class DeduplicatedPriorityQueue {
public:
  Elem const &top() const {
    return impl.top();
  }

  bool empty() const {
    return impl.empty();
  }

  size_t size() const {
    return impl.size();
  }

  void push(Elem const &e) {
    if (!contains(seen, e)) {
      impl.push(e);
      seen.insert(e);
    }
  }

  void pop() {
    seen.erase(impl.top());
    impl.pop();
  }

  std::set<Elem, Compare> contents() const {
    auto temp = impl;
    std::set<Elem, Compare> result;
    while (!temp.empty()) {
      result.insert(temp.top());
      temp.pop();
    }
    return result;
  }

private:
  std::priority_queue<Elem, Container, Compare> impl;
  std::set<Elem, Compare> seen;
};

} // namespace FlexFlow

#endif /* _FLEXFLOW_UTILS_DEDUPLICATED_PRIORITY_QUEUE_H */
