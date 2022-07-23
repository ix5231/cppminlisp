#if !defined(INTERPRETER_HPP)
#define INTERPRETER_HPP

#include <string>

#include "lexer.hpp"

class Interpreter {
private:
  Lexer lexer;

public:
  Interpreter(const std::string &_source);
  int eval();
};

#endif // INTERPRETER_HPP