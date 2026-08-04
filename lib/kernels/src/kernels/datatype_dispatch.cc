#include "kernels/datatype_dispatch.h"

namespace FlexFlow {

template <DataType DT>
struct F1;
template <DataType IT, DataType OT>
struct F2;
template <DataType IT, DataType CT, DataType OT>
struct F3;

template struct DataTypeDispatch1<F1>;
template struct DataTypeDispatch2<F2>;
template struct DataTypeDispatch3<F3>;

} // namespace FlexFlow
