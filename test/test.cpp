#include <gtest/gtest.h>

#include "main/interpreter.hpp"
#include "main/lexer.hpp"
#include "main/token.hpp"

TEST(Arithmetic, BasicPlus) {
  std::string src = "(+ 1 1)";
  Interpreter p(src);
  EXPECT_EQ(p.parse(), 2);
}

TEST(Lexer, Basic) {
  std::string src = "(+ 15 21)";
  Lexer l(src);
  Token t;
  t = l.nextToken();
  EXPECT_EQ(t.type, DELIM_BRACKET_START);
  t = l.nextToken();
  EXPECT_EQ(t.type, OPERATOR);
  EXPECT_EQ(t.value_symbol, "+");
  t = l.nextToken();
  EXPECT_EQ(t.type, LITERAL_INTEGER);
  EXPECT_EQ(t.value_integer, 15);
  t = l.nextToken();
  EXPECT_EQ(t.type, LITERAL_INTEGER);
  EXPECT_EQ(t.value_integer, 21);
  t = l.nextToken();
  EXPECT_EQ(t.type, DELIM_BRACKET_END);
}