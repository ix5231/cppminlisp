#include "value.hpp"
#include "conscell.hpp"

Value::Value() : type(INTEGER), value_integer(0), value_conscell(nullptr) {}

Value::Value(const int i)
    : type(INTEGER), value_integer(i), value_conscell(nullptr) {}

Value::~Value() = default;
