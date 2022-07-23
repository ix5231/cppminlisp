#include "value.hpp"

#include <memory>

#include "conscell.hpp"

Value::Value(const ConsCell &cc)
    : type(CONSCELL), value_integer(0),
      value_conscell(std::make_shared<ConsCell>(cc)) {}

Value::Value(const ConsCell &&cc)
    : type(CONSCELL), value_integer(0),
      value_conscell(std::make_shared<ConsCell>(cc)) {}

Value::Value(const int i)
    : type(INTEGER), value_integer(i), value_conscell(nullptr) {}
