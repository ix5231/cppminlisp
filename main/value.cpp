#include "value.hpp"
#include "conscell.hpp"

Value::Value(const int i)
    : type(INTEGER), value_integer(i), value_conscell(nullptr) {}
