#include "utils/binary_relation/binary_relation.h"
#include "utils/archetypes/jsonable_ordered_value_type.h"
#include "utils/archetypes/ordered_value_type.h"

namespace FlexFlow {

using L = jsonable_ordered_value_type<0>;
using R = jsonable_ordered_value_type<1>;

template struct BinaryRelation<L, R>;

template std::set<std::pair<L, R>> format_as(BinaryRelation<L, R> const &);

template std::ostream &operator<<(std::ostream &, BinaryRelation<L, R> const &);

} // namespace FlexFlow

namespace nlohmann {

using L = ::FlexFlow::jsonable_ordered_value_type<0>;
using R = ::FlexFlow::jsonable_ordered_value_type<1>;

template struct adl_serializer<::FlexFlow::BinaryRelation<L, R>>;

} // namespace nlohmann

namespace std {

using L = ::FlexFlow::ordered_value_type<0>;
using R = ::FlexFlow::ordered_value_type<1>;

template struct hash<::FlexFlow::BinaryRelation<L, R>>;

} // namespace std
