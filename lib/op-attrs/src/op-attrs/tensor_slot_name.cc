#include "op-attrs/tensor_slot_name.h"

namespace FlexFlow {

std::vector<TensorSlotName> get_variadic_inputs_slot_name_sequence() {
  return std::vector{
      TensorSlotName::INPUT_00,
      TensorSlotName::INPUT_01,
      TensorSlotName::INPUT_02,
      TensorSlotName::INPUT_03,
      TensorSlotName::INPUT_04,
      TensorSlotName::INPUT_05,
      TensorSlotName::INPUT_06,
      TensorSlotName::INPUT_07,
      TensorSlotName::INPUT_08,
      TensorSlotName::INPUT_09,
      TensorSlotName::INPUT_10,
      TensorSlotName::INPUT_11,
      TensorSlotName::INPUT_12,
      TensorSlotName::INPUT_13,
      TensorSlotName::INPUT_14,
      TensorSlotName::INPUT_15,
  };
};

std::vector<TensorSlotName> get_variadic_outputs_slot_name_sequence() {
  return std::vector{
      TensorSlotName::OUTPUT_00,
      TensorSlotName::OUTPUT_01,
      TensorSlotName::OUTPUT_02,
      TensorSlotName::OUTPUT_03,
      TensorSlotName::OUTPUT_04,
      TensorSlotName::OUTPUT_05,
  };
}

} // namespace FlexFlow
