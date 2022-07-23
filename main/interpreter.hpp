#if !defined(INTERPRETER_HPP)
#define INTERPRETER_HPP

#include <string>
#include <vector>

#include "lexer.hpp"
#include "value.hpp"

class Interpreter {
private:
  Lexer lexer;
  Value evalProcedure();
  std::vector<Value> evalArgs();
  static Value evalPlus(std::vector<Value> args);

public:
  Interpreter(const std::string &_source);
  Value eval();
};

#endif // INTERPRETER_HPP