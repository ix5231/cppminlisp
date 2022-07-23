#if !defined(VALUE_HPP)
#define VALUE_HPP

#include <memory>

#include "gc.hpp"

struct ConsCell;

enum ValueType {
  INTEGER,
  CONSCELL,
};

struct Value {
private:
  Value();
  Value(const int i);

public:
  ValueType type;
  int value_integer;
  Gc<ConsCell> value_conscell;

  ~Value();
  static inline Value integer(const int i) { return Value(i); }

  Value &operator=(const Value &v);
};

#endif // VALUE_HPP
