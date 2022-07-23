#include "conscell.hpp"

#include <memory>

#include "value.hpp"

ConsCell::ConsCell(const Value &_car, const Value &_cdr)
    : car(std::make_shared<Value>(_car)), cdr(std::make_shared<Value>(_cdr)) {}

ConsCell::ConsCell(const Value &&_car, const Value &&_cdr)
    : car(std::make_shared<Value>(_car)), cdr(std::make_shared<Value>(_cdr)) {}