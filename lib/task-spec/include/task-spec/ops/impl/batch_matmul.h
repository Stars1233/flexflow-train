#ifndef _FLEXFLOW_LIB_TASK_SPEC_INCLUDE_TASK_SPEC_OPS_IMPL_BATCH_MATMUL_H
#define _FLEXFLOW_LIB_TASK_SPEC_INCLUDE_TASK_SPEC_OPS_IMPL_BATCH_MATMUL_H

#include "task-spec/task_impl_function.dtg.h"

namespace FlexFlow {

TaskImplFunction get_batch_matmul_fwd_task_impl();
TaskImplFunction get_batch_matmul_bwd_task_impl();

} // namespace FlexFlow

#endif
