#include "interpreter.hpp"

#include <stdexcept>
#include <vector>

#include "lexer.hpp"
#include "util.hpp"
#include "value.hpp"

Interpreter::Interpreter(const std::string &_source) : lexer(_source) {}

Value Interpreter::eval() { return evalProcedure(); }

Value Interpreter::evalProcedure() {
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

  return evalPlus(evalArgs());
}

std::vector<Value> Interpreter::evalArgs() {
  std::vector<Value> args;

  auto t = lexer.next_token();
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

  args.emplace_back(Value::integer(left));
  args.emplace_back(Value::integer(right));

  return args;
}

Value Interpreter::evalPlus(std::vector<Value> args) {
  int ret = 0;
  for (const Value &v : args) {
    if (v.type != INTEGER) {
      throw std::logic_error("+ expects INTEGER");
    }
    ret += v.value_integer;
  }
  return Value::integer(ret);
}