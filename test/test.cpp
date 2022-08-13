#include <gtest/gtest.h>

#include "main/conscell.hpp"
#include "main/interpreter.hpp"
#include "main/lexer.hpp"
#include "main/token.hpp"

TEST(Arithmetic, Literal) {
  std::string src = "3";
  Interpreter p(src);
  auto v = p.eval();
  EXPECT_EQ(v.value_integer, 3);
}

TEST(Arithmetic, BasicPlus) {
  std::string src = "(+ 2 143)";
  Interpreter p(src);
  auto v = p.eval();
  EXPECT_EQ(v.value_integer, 145);
}

TEST(Arithmetic, PlusN) {
  std::string src = "(+ 1 2 3 4)";
  Interpreter p(src);
  auto v = p.eval();
  EXPECT_EQ(v.value_integer, 10);
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

TEST(ConsCell, DoubleCons) {
  std::string src = "(cons 1 (cons 2 3))";
  Interpreter p(src);

  auto v = p.eval();
  EXPECT_EQ(v.type, CONSCELL);

  ConsCell &cc = *v.value_conscell.get();
  EXPECT_EQ(cc.car->type, INTEGER);
  EXPECT_EQ(cc.car->value_integer, 1);
  EXPECT_EQ(cc.cdr->type, CONSCELL);

  ConsCell &cc2 = *cc.cdr->value_conscell.get();
  EXPECT_EQ(cc2.car->type, INTEGER);
  EXPECT_EQ(cc2.car->value_integer, 2);
  EXPECT_EQ(cc2.cdr->type, INTEGER);
  EXPECT_EQ(cc2.cdr->value_integer, 3);
}

TEST(ConsCell, Complex) {
  std::string src = "(cons (cons 1 2) (cons 3 (cons 4 5)))";
  Interpreter p(src);

  auto v = p.eval();
  EXPECT_EQ(v.type, CONSCELL);

  ConsCell &cc = *v.value_conscell;
  EXPECT_EQ(cc.car->type, CONSCELL);
  EXPECT_EQ(cc.cdr->type, CONSCELL);

  ConsCell &cc_left = *cc.car->value_conscell;
  EXPECT_EQ(cc_left.car->type, INTEGER);
  EXPECT_EQ(cc_left.car->value_integer, 1);
  EXPECT_EQ(cc_left.cdr->type, INTEGER);
  EXPECT_EQ(cc_left.cdr->value_integer, 2);

  ConsCell &cc_right = *cc.cdr->value_conscell;
  EXPECT_EQ(cc_right.car->type, INTEGER);
  EXPECT_EQ(cc_right.car->value_integer, 3);
  EXPECT_EQ(cc_right.cdr->type, CONSCELL);

  ConsCell &cc_right_right = *cc_right.cdr->value_conscell;
  EXPECT_EQ(cc_right_right.car->type, INTEGER);
  EXPECT_EQ(cc_right_right.car->value_integer, 4);
  EXPECT_EQ(cc_right_right.cdr->type, INTEGER);
  EXPECT_EQ(cc_right_right.cdr->value_integer, 5);
}

TEST(Lexer, Basic) {
  std::string src = "(+ 15 21)";
  Lexer l(src);
  Token t = l.current_token();
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
