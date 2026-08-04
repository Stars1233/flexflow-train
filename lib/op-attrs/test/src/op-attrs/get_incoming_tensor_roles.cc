#include "op-attrs/get_incoming_tensor_roles.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE(
      "get_incoming_tensor_roles(ComputationGraphOpAttrs, int num_incoming)") {
    SUBCASE("Concat") {
      ComputationGraphOpAttrs attrs = ComputationGraphOpAttrs{
          ConcatAttrs{
              /*axis=*/ff_dim_t{0_n},
              /*num_inputs=*/3_ge2,
          },
      };

      std::map<TensorSlotName, IncomingTensorRole> result =
          get_incoming_tensor_roles(attrs);
      std::map<TensorSlotName, IncomingTensorRole> correct = {
          {
              TensorSlotName::INPUT_00,
              IncomingTensorRole::INPUT,
          },
          {
              TensorSlotName::INPUT_01,
              IncomingTensorRole::INPUT,
          },
          {
              TensorSlotName::INPUT_02,
              IncomingTensorRole::INPUT,
          },
      };

      CHECK(result == correct);
    }
  }
}
