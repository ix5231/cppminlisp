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
  if (lexer.current_token().type != DELIM_BRACKET_START) {
    throw std::logic_error("Expected DELIM_BRACKET_START");
  }

  if (lexer.next_token().type != OPERATOR) {
    throw std::logic_error("Expected OPERATOR");
  }
  std::string opname = lexer.current_token().value_symbol;

  lexer.next_token();
  std::vector<Value> args;
  while (lexer.current_token().type != DELIM_BRACKET_END) {
    if (lexer.current_token().type == DELIM_BRACKET_START) {
      args.emplace_back(evalProcedure());
    } else if (lexer.current_token().type == LITERAL_INTEGER) {
      args.emplace_back(Value::integer(lexer.current_token().value_integer));
      lexer.next_token();
    } else {
      throw NotImplemented();
    }
  }
  lexer.next_token();

  if (opname == "cons") {
    return evalCons(args);
  } else if (opname == "+") {
    return evalPlus(args);
  } else {
    throw NotImplemented();
  }
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