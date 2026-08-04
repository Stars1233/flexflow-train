#include "kernels/element_unary_kernels_cpu.h"
#include "internal/test_utils.h"
#include "kernels/create_accessor_with_contents.h"
#include "kernels/format_accessor_contents.h"
#include "kernels/local_cpu_allocator.h"
#include "op-attrs/ops/element_unary.h"
#include "test/utils/doctest/check_kv.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("element_unary_cpu_forward_kernel") {
    SUBCASE("relu") {
      Allocator cpu_allocator = create_local_cpu_memory_allocator();

      ElementUnaryAttrs attrs = make_relu_attrs();

      GenericTensorAccessorR input = create_2d_accessor_r_with_contents<float>(
          {
              {3, -3, 6},
              {0, 1, 5},
              {1, 2, -2},
              {-8, 0.5, -3},
          },
          cpu_allocator);

      GenericTensorAccessorW result =
          create_zero_filled_accessor_w(input.shape, cpu_allocator);

      element_unary_cpu_forward_kernel(
          /*attrs=*/attrs,
          /*input=*/input,
          /*output=*/result);

      GenericTensorAccessorR correct =
          create_2d_accessor_r_with_contents<float>(
              {
                  {3, 0, 6},
                  {0, 1, 5},
                  {1, 2, 0},
                  {0, 0.5, 0},
              },
              cpu_allocator);

      CHECK_MESSAGE(accessors_are_equal(result, correct),
                    check_kv("result", format_accessor_w_contents(result)));
    }
  }

  TEST_CASE("element_unary_cpu_backward_kernel") {
    SUBCASE("relu") {
      Allocator cpu_allocator = create_local_cpu_memory_allocator();

      ElementUnaryAttrs attrs = make_relu_attrs();

      GenericTensorAccessorR input = create_2d_accessor_r_with_contents<float>(
          {
              {3, -3, 6},
              {0, 1, 5},
              {1, 2, -2},
              {-8, 0.5, -3},
          },
          cpu_allocator);

      GenericTensorAccessorW input_grad =
          cpu_allocator.allocate_tensor(get_tensor_shape_for_accessor_r(input));

      GenericTensorAccessorR output = create_2d_accessor_r_with_contents<float>(
          {
              {3, 0, 6},
              {0, 1, 5},
              {1, 2, -2},
              {0, 0.5, 0},
          },
          cpu_allocator);

      GenericTensorAccessorR output_grad =
          create_2d_accessor_r_with_contents<float>(
              {
                  {1, 2, -1},
                  {6, 4, 2},
                  {0.5, 0.1, -2},
                  {0, 0.5, 0},
              },
              cpu_allocator);

      element_unary_cpu_backward_kernel(
          /*attrs=*/attrs,
          /*output=*/output,
          /*output_grad=*/output_grad,
          /*input=*/input,
          /*input_grad=*/input_grad);

      GenericTensorAccessorR correct_input_grad =
          create_2d_accessor_r_with_contents<float>(
              {
                  {1.0f, 0.0f, -1.0f},
                  {0.0f, 4.0f, 2.0f},
                  {0.5f, 0.1f, 0.0f},
                  {0.0f, 0.5f, 0.0f},
              },
              cpu_allocator);

      CHECK_MESSAGE(
          accessors_are_equal(input_grad, correct_input_grad),
          check_kv("input_grad", format_accessor_w_contents(input_grad)));
    }
  }
}
