#include <gtest/gtest.h>

#include "main/parser.hpp"

TEST(Arithmetic, BasicPlus) {
  std::string src = "(+ 1 1)";
  EXPECT_EQ(parse(src), 2);
}