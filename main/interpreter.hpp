#if !defined(INTERPRETER_HPP)
#define INTERPRETER_HPP

#include <string>

#include "lexer.hpp"
#include "value.hpp"

class Interpreter {
private:
  Lexer lexer;

public:
  Interpreter(const std::string &_source);
  Value eval();
};

#endif // INTERPRETER_HPP