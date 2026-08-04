#include "op-attrs/ff_ordered/ff_ordered.h"
#include "utils/archetypes/rapidcheckable_value_type.h"
#include "utils/archetypes/value_type.h"

namespace FlexFlow {

using T = value_type<0>;

template struct FFOrdered<T>;

template std::string format_as(FFOrdered<T> const &);

template std::ostream &operator<<(std::ostream &, FFOrdered<T> const &);

} // namespace FlexFlow

namespace std {

using T = ::FlexFlow::value_type<0>;

template struct hash<::FlexFlow::FFOrdered<T>>;

} // namespace std

namespace rc {

using T = ::FlexFlow::rapidcheckable_value_type<0>;

template struct Arbitrary<::FlexFlow::FFOrdered<T>>;

} // namespace rc
