#include <gtest/gtest.h>

#include "main/conscell.hpp"
#include "main/interpreter.hpp"
#include "main/lexer.hpp"
#include "main/token.hpp"

TEST(Arithmetic, BasicPlus) {
  std::string src = "(+ 2 143)";
  Interpreter p(src);
  auto v = p.eval();
  EXPECT_EQ(v.value_integer, 145);
}

TEST(ConsCell, SimplePair) {
  std::string src = "(cons 1 2)";
  Interpreter p(src);

  auto v = p.eval();
  EXPECT_EQ(v.type, CONSCELL);

  ConsCell cc = *v.value_conscell.get();
  EXPECT_EQ(cc.car->type, INTEGER);
  EXPECT_EQ(cc.car->value_integer, 1);
  EXPECT_EQ(cc.cdr->type, INTEGER);
  EXPECT_EQ(cc.cdr->value_integer, 2);
}

TEST(Lexer, Basic) {
  std::string src = "(+ 15 21)";
  Lexer l(src);
  Token t;
  t = l.next_token();
  EXPECT_EQ(t.type, DELIM_BRACKET_START);
  t = l.next_token();
  EXPECT_EQ(t.type, OPERATOR);
  EXPECT_EQ(t.value_symbol, "+");
  t = l.next_token();
  EXPECT_EQ(t.type, LITERAL_INTEGER);
  EXPECT_EQ(t.value_integer, 15);
  t = l.next_token();
  EXPECT_EQ(t.type, LITERAL_INTEGER);
  EXPECT_EQ(t.value_integer, 21);
  t = l.next_token();
  EXPECT_EQ(t.type, DELIM_BRACKET_END);
}
