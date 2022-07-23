#if !defined(VALUE_HPP)
#define VALUE_HPP

#include <memory>

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
  std::unique_ptr<ConsCell> value_conscell;

  Value(const Value &v);
  ~Value();
  static inline Value integer(const int i) { return Value(i); }

  Value &operator=(const Value &v);
};

#endif // VALUE_HPP
