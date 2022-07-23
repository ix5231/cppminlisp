#include "interpreter.hpp"

#include <stdexcept>

#include "lexer.hpp"
#include "token.hpp"
#include "util.hpp"

Interpreter::Interpreter(const std::string &_source) : lexer(_source) {}

int Interpreter::eval() {
  auto t = lexer.next_token();
  if (t.type != DELIM_BRACKET_START) {
    throw std::logic_error("Expected DELIM_BRACKET_START");
  }

  t = lexer.next_token();
  if (t.type != OPERATOR) {
    throw std::logic_error("Expected OPERATOR");
  }
  if (t.value_symbol != "+") {
    throw NotImplemented();
  }

  t = lexer.next_token();
  if (t.type != LITERAL_INTEGER) {
    throw std::logic_error("Expected LITERAL_INTEGER");
  }
  int left = t.value_integer;

  t = lexer.next_token();
  if (t.type != LITERAL_INTEGER) {
    throw std::logic_error("Expected LITERAL_INTEGER");
  }
  int right = t.value_integer;

  t = lexer.next_token();
  if (t.type != DELIM_BRACKET_END) {
    throw std::logic_error("Expected DELIM_BRACKET_END");
  }

  return left + right;
}