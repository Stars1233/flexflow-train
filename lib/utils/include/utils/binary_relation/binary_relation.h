#ifndef _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_BINARY_RELATION_BINARY_RELATION_H
#define _FLEXFLOW_LIB_UTILS_INCLUDE_UTILS_BINARY_RELATION_BINARY_RELATION_H

#include "utils/containers/filtrans.h"
#include "utils/containers/multiset_of.h"
#include "utils/containers/transform.h"
#include "utils/fmt/pair.h"
#include "utils/fmt/set.h"
#include "utils/hash-utils.h"
#include "utils/hash/pair.h"
#include "utils/hash/set.h"
#include "utils/hash/tuple.h"
#include "utils/json/check_is_json_deserializable.h"
#include "utils/json/check_is_json_serializable.h"
#include <fmt/format.h>
#include <nlohmann/json.hpp>
#include <set>

namespace FlexFlow {

template <typename L, typename R>
struct BinaryRelation {
  BinaryRelation() : raw{} {}

  BinaryRelation(std::set<std::pair<L, R>> const &raw) : raw(raw) {}

  BinaryRelation(std::initializer_list<std::pair<L, R>> init)
      : BinaryRelation(init.begin(), init.end()) {}

  template <typename InputIt>
  BinaryRelation(InputIt first, InputIt last) {
    for (auto it = first; it != last; it++) {
      this->equate(it->first, it->second);
    }
  }

  bool operator==(BinaryRelation const &other) const {
    return this->tie() == other.tie();
  }

  bool operator!=(BinaryRelation const &other) const {
    return this->tie() != other.tie();
  }

  bool operator<(BinaryRelation const &other) const {
    return this->tie() < other.tie();
  }

  bool operator<=(BinaryRelation const &other) const {
    return this->tie() <= other.tie();
  }

  bool operator>(BinaryRelation const &other) const {
    return this->tie() > other.tie();
  }

  bool operator>=(BinaryRelation const &other) const {
    return this->tie() >= other.tie();
  }

  void equate(L const &l, R const &r) {
    this->raw.insert({l, r});
  }

  void equate(std::pair<L, R> const &lr) {
    this->raw.insert(lr);
  }

  std::set<R> at_l(L const &l) const {
    return filtrans(this->raw,
                    [&](std::pair<L, R> const &p) -> std::optional<R> {
                      if (p.first == l) {
                        return p.second;
                      } else {
                        return std::nullopt;
                      }
                    });
  }

  std::set<L> at_r(R const &r) const {
    return filtrans(this->raw,
                    [&](std::pair<L, R> const &p) -> std::optional<L> {
                      if (p.second == r) {
                        return p.first;
                      } else {
                        return std::nullopt;
                      }
                    });
  }

  std::multiset<L> left_value_occurences() const {
    return transform(multiset_of(this->raw),
                     [&](std::pair<L, R> const &p) -> L { return p.first; });
  }

  std::multiset<R> right_value_occurences() const {
    return transform(multiset_of(this->raw),
                     [&](std::pair<L, R> const &p) -> R { return p.second; });
  }

  std::set<L> left_values() const {
    return transform(this->raw,
                     [&](std::pair<L, R> const &p) -> L { return p.first; });
  }

  std::set<R> right_values() const {
    return transform(this->raw,
                     [&](std::pair<L, R> const &p) -> R { return p.second; });
  }

  std::size_t size() const {
    return this->raw.size();
  }

  bool empty() const {
    return this->raw.empty();
  }

  std::set<std::pair<L, R>> const &unwrap_as_set() const {
    return this->raw;
  }

private:
  std::set<std::pair<L, R>> raw;

private:
  std::tuple<decltype(raw) const &> tie() const {
    return std::tie(this->raw);
  }

  friend struct std::hash<BinaryRelation<L, R>>;
};

template <typename L, typename R>
std::set<std::pair<L, R>> format_as(BinaryRelation<L, R> const &m) {
  return m.unwrap_as_set();
}

template <typename L, typename R>
std::ostream &operator<<(std::ostream &s, BinaryRelation<L, R> const &m) {
  return (s << fmt::to_string(m));
}

} // namespace FlexFlow

namespace nlohmann {

template <typename L, typename R>
struct adl_serializer<::FlexFlow::BinaryRelation<L, R>> {
  static ::FlexFlow::BinaryRelation<L, R> from_json(json const &j) {
    CHECK_IS_JSON_DESERIALIZABLE(L);
    CHECK_IS_JSON_DESERIALIZABLE(R);

    std::set<std::pair<L, R>> s = j;

    return ::FlexFlow::BinaryRelation<L, R>(s.cbegin(), s.cend());
  }

  static void to_json(json &j, ::FlexFlow::BinaryRelation<L, R> const &m) {
    CHECK_IS_JSON_SERIALIZABLE(L);
    CHECK_IS_JSON_SERIALIZABLE(R);

    j = m.unwrap_as_set();
  }
};

} // namespace nlohmann

namespace std {

template <typename L, typename R>
struct hash<::FlexFlow::BinaryRelation<L, R>> {
  size_t operator()(::FlexFlow::BinaryRelation<L, R> const &m) const {
    return ::FlexFlow::get_std_hash(m.tie());
  }
};

} // namespace std

#endif
