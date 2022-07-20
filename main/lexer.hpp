#if !defined(LEXER_HPP)
#define LEXER_HPP

#include <string>

#include "token.hpp"

class Lexer {
  const std::string &source;
  const std::string::const_iterator next;
  static bool Lexer::is_extended_alpha(const char ch);
public:
  Lexer(const std::string &_source);
  Token nextToken();
};

#endif // LEXER_HPP
