#include "kernels/element_binary_kernels_cpu.h"
#include "kernels/map_tensor_accessors.h"
#include "kernels/tensor_accessor_binary_ops.h"
#include "utils/exception.h"

namespace FlexFlow {

void element_binary_cpu_forward_kernel(ElementBinaryAttrs const &attrs,
                                       GenericTensorAccessorR const &lhs,
                                       GenericTensorAccessorR const &rhs,
                                       GenericTensorAccessorW const &output) {
  std::function<float(float, float)> element_function =
      [&]() -> std::function<float(float, float)> {
    switch (attrs.type) {
      case OperatorType::EW_ADD:
        return [](float x, float y) -> float { return x + y; };
      case OperatorType::EW_SUB:
        return [](float x, float y) -> float { return x - y; };
      case OperatorType::EW_MUL:
        return [](float x, float y) -> float { return x * y; };
      case OperatorType::EW_DIV:
        return [](float x, float y) -> float { return x / y; };
      case OperatorType::EW_MAX:
        return [](float x, float y) -> float { return std::max(x, y); };
      case OperatorType::EW_MIN:
        return [](float x, float y) -> float { return std::min(x, y); };
      default:
        PANIC("Unhandled OperatorType {}", attrs.type);
    }
  }();

  map_tensor_accessors2_to(
      /*lhs=*/lhs,
      /*rhs=*/rhs,
      /*output_data_type=*/
      require_same(lhs.shape.data_type, rhs.shape.data_type),
      /*f=*/element_function,
      /*output=*/output);
}

void element_binary_cpu_backward_kernel(
    ElementBinaryAttrs const &attrs,
    GenericTensorAccessorR const &output,
    GenericTensorAccessorR const &output_grad,
    GenericTensorAccessorR const &lhs,
    GenericTensorAccessorW const &lhs_grad,
    GenericTensorAccessorR const &rhs,
    GenericTensorAccessorW const &rhs_grad) {

  std::function<float(float, float, float)> lhs_grad_update_function =
      [&]() -> std::function<float(float, float, float)> {
    switch (attrs.type) {
      case OperatorType::EW_ADD:
        return [](float og, float l, float r) -> float { return og; };
      case OperatorType::EW_SUB:
        return [](float og, float l, float r) -> float { return og; };
      case OperatorType::EW_MUL:
        return [](float og, float l, float r) -> float { return og * r; };
      case OperatorType::EW_DIV:
        return [](float og, float l, float r) -> float { return og / r; };
      case OperatorType::EW_MAX:
        NOT_IMPLEMENTED();
      case OperatorType::EW_MIN:
        NOT_IMPLEMENTED();
      default:
        PANIC("Unhandled OperatorType {}", attrs.type);
    }
  }();

  std::function<float(float, float, float)> rhs_grad_update_function =
      [&]() -> std::function<float(float, float, float)> {
    switch (attrs.type) {
      case OperatorType::EW_ADD:
        return [](float og, float l, float r) -> float { return og; };
      case OperatorType::EW_SUB:
        return [](float og, float l, float r) -> float { return -og; };
      case OperatorType::EW_MUL:
        return [](float og, float l, float r) -> float { return og * l; };
      case OperatorType::EW_DIV:
        return [](float og, float l, float r) -> float {
          return -(og * l) / (r * r);
        };
      case OperatorType::EW_MAX:
        NOT_IMPLEMENTED();
      case OperatorType::EW_MIN:
        NOT_IMPLEMENTED();
      default:
        PANIC("Unhandled OperatorType {}", attrs.type);
    }
  }();

  Allocator cpu_allocator = create_local_cpu_memory_allocator();

  GenericTensorAccessorR lhs_grad_update =
      read_only_accessor_from_write_accessor(map_tensor_accessors3(
          /*lhs=*/output_grad,
          /*chs=*/lhs,
          /*rhs=*/rhs,
          /*output_data_type=*/
          require_same(output_grad.shape.data_type,
                       lhs.shape.data_type,
                       rhs.shape.data_type),
          /*f=*/lhs_grad_update_function,
          /*output_allocator=*/cpu_allocator));

  GenericTensorAccessorR rhs_grad_update =
      read_only_accessor_from_write_accessor(map_tensor_accessors3(
          /*lhs=*/output_grad,
          /*chs=*/lhs,
          /*rhs=*/rhs,
          /*output_data_type=*/
          require_same(output_grad.shape.data_type,
                       lhs.shape.data_type,
                       rhs.shape.data_type),
          /*f=*/rhs_grad_update_function,
          /*output_allocator=*/cpu_allocator));

  tensor_accessor_elementwise_add_to(lhs_grad, lhs_grad_update, lhs_grad);

  tensor_accessor_elementwise_add_to(rhs_grad, rhs_grad_update, rhs_grad);
}

} // namespace FlexFlow
