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
  Value(const int i);
  Value(const ConsCell &cc);
  Value(const ConsCell &&cc);

public:
  ValueType type;
  int value_integer;
  Gc<ConsCell> value_conscell;

  static inline Value integer(const int i) { return Value(i); }
  static inline Value cons(const ConsCell &cc) { return Value(cc); }
  static inline Value cons(const ConsCell &&cc) { return Value(cc); }
};

#endif // VALUE_HPP
