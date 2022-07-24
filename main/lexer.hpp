#if !defined(LEXER_HPP)
#define LEXER_HPP

#include <string>

#include "token.hpp"

class Lexer {
  const std::string &source;
  std::string::const_iterator next;
  Token current;

  std::string read_identifier();
  int read_integer();
  static bool is_extended_alpha(const char ch);

public:
  Lexer(const std::string &_source);
  Token next_token();
  Token current_token();
};

#endif // LEXER_HPP
