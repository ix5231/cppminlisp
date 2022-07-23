#if !defined(CONSCELL_HPP)
#define CONSCELL_HPP

#include <memory>

#include "gc.hpp"

struct Value;

struct ConsCell {
  Gc<Value> car;
  Gc<Value> cdr;

  ConsCell(const Value &_car, const Value &_cdr);
  ConsCell(const Value &&_car, const Value &&_cdr);
};

#endif // CONSCELL_HPP
