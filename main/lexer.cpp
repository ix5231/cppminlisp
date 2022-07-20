#include "lexer.hpp"

#include <string>
#include <unordered_set>

#include "token.hpp"
#include "util.hpp"

Lexer::Lexer(const std::string &_source)
    : source(_source), next(_source.begin()) {}

Token Lexer::nextToken() {
  while (next != source.end()) {
    switch (*next) {
    case '(':
      return (Token) { DELIM_BRACKET_START, };
    case ')':
      return (Token) { DELIM_BRACKET_END, };
    default:
      if (isdigit(*next)) {
        throw NotImplemented();
      } else if (isalpha(*next) or is_extended_alpha(*next)) {
        throw NotImplemented();
      } else {
        throw std::logic_error("Unexpected char found: " + *next);
      }
      break;
    }
  }

  throw std::logic_error("Iterator exhausted");
}

bool Lexer::is_extended_alpha(const char ch) {
  const std::unordered_set<char> extended_alphabet{'!', '$', '%', '&', '*', '+',
                                                   '-', '.', '/', ':', '<', '=',
                                                   '>', '?', '@', '^', '_', '~'};
  auto it = extended_alphabet.find(ch);
  return it != extended_alphabet.end();
}