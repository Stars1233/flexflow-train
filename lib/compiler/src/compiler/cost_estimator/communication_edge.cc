#include "compiler/cost_estimator/communication_edge.h"
#include "utils/hash-utils.h"
#include "utils/hash/tuple.h"
#include <libassert/assert.hpp>

namespace FlexFlow {

CommunicationEdge::CommunicationEdge(MachineSpaceCoordinate const &src,
                                     MachineSpaceCoordinate const &dst)
    : src(src), dst(dst) {
  ASSERT(src != dst);
}

bool CommunicationEdge::operator==(CommunicationEdge const &other) const {
  return this->tie() == other.tie();
}

bool CommunicationEdge::operator!=(CommunicationEdge const &other) const {
  return this->tie() != other.tie();
}

bool CommunicationEdge::operator<(CommunicationEdge const &other) const {
  return this->tie() < other.tie();
}

bool CommunicationEdge::operator>(CommunicationEdge const &other) const {
  return this->tie() > other.tie();
}

bool CommunicationEdge::operator<=(CommunicationEdge const &other) const {
  return this->tie() <= other.tie();
}

bool CommunicationEdge::operator>=(CommunicationEdge const &other) const {
  return this->tie() >= other.tie();
}

MachineSpaceCoordinate const &CommunicationEdge::get_src() const {
  return this->src;
}

MachineSpaceCoordinate const &CommunicationEdge::get_dst() const {
  return this->dst;
}

std::tuple<MachineSpaceCoordinate const &, MachineSpaceCoordinate const &>
    CommunicationEdge::tie() const {
  return std::tie(this->src, this->dst);
}

std::string format_as(CommunicationEdge const &e) {
  ::nlohmann::json j = e;
  return j.dump();
}

std::ostream &operator<<(std::ostream &s, CommunicationEdge const &e) {
  return (s << fmt::to_string(e));
}

} // namespace FlexFlow

namespace nlohmann {

::FlexFlow::CommunicationEdge
    adl_serializer<::FlexFlow::CommunicationEdge>::from_json(json const &j) {
  ASSERT(j.at("__type").template get<std::string>() == "CommunicationEdge");
  return ::FlexFlow::CommunicationEdge{
      /*src=*/j.at("src").template get<::FlexFlow::MachineSpaceCoordinate>(),
      /*dst=*/j.at("dst").template get<::FlexFlow::MachineSpaceCoordinate>(),
  };
}

void adl_serializer<::FlexFlow::CommunicationEdge>::to_json(
    json &j, ::FlexFlow::CommunicationEdge const &e) {
  j["__type"] = "CommunicationEdge";
  j["src"] = e.get_src();
  j["dst"] = e.get_dst();
}

} // namespace nlohmann

namespace std {

size_t hash<::FlexFlow::CommunicationEdge>::operator()(
    ::FlexFlow::CommunicationEdge const &e) const {
  return get_std_hash(e.tie());
}

} // namespace std
