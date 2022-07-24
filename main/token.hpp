#if !defined(TOKEN_HPP)
#define TOKEN_HPP

#include <string>

enum TokenType {
  DELIM_BRACKET_START,
  DELIM_BRACKET_END,
  LITERAL_INTEGER,
  OPERATOR,
  EOS,
};

struct Token {
  TokenType type;
  std::string value_symbol;
  int value_integer;
};

#endif // TOKEN_HPP
