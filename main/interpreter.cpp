#include "interpreter.hpp"

#include <stdexcept>
#include <vector>

#include "conscell.hpp"
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
  if (t.value_symbol == "cons") {
    return evalCons(evalArgs());
  } else if (t.value_symbol == "+") {
    return evalPlus(evalArgs());
  } else {
    throw NotImplemented();
  }
}

std::vector<Value> Interpreter::evalArgs() {
  std::vector<Value> args;

  auto t = lexer.next_token();
  while (t.type != DELIM_BRACKET_END) {
    if (t.type != LITERAL_INTEGER) {
      throw NotImplemented();
    }
    args.emplace_back(Value::integer(t.value_integer));
    t = lexer.next_token();
  }

  return args;
}

Value Interpreter::evalCons(std::vector<Value> args) {
  if (args.size() != 2) {
    throw std::logic_error("cons expects exactly 2 args");
  }

  return Value::cons(ConsCell(std::move(args[0]), std::move(args[1])));
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