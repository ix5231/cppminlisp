#include "lexer.hpp"

#include <string>
#include <unordered_set>

#include "token.hpp"
#include "util.hpp"

Lexer::Lexer(const std::string &_source)
    : source(_source), next(_source.begin()) {
  next_token();
}

Token Lexer::next_token() {
  while (next != source.end()) {
    switch (*next) {
    case '(':
      ++next;
      return current = (Token){
                 DELIM_BRACKET_START,
             };
    case ')':
      ++next;
      return current = (Token){
                 DELIM_BRACKET_END,
             };
    default:
      if (isspace(*next)) {
        ++next;
      } else if (isalpha(*next) or is_extended_alpha(*next)) {
        std::string val = read_identifier();
        return current = (Token){
                   OPERATOR,
                   val,
                   0,
               };
      } else if (isdigit(*next)) {
        int val = read_integer();
        return current = (Token){
                   LITERAL_INTEGER,
                   "",
                   val,
               };
      } else {
        throw std::logic_error(std::string("Unexpected char found: \"") +
                               *next + std::string("\""));
      }
      break;
    }
  }

  return (Token){EOS};
}

Token Lexer::current_token() { return current; }

std::string Lexer::read_identifier() {
  int l = 0;
  while (next + l != source.end()) {
    if (isalpha(*(next + l)) or is_extended_alpha(*(next + l)) or
        isdigit(*(next + l))) {
      l++;
    } else {
      break;
    }
  }

  std::string ret(next, next + l);
  next += l;
  return ret;
}

int Lexer::read_integer() {
  int l = 0;
  while (next + l != source.end()) {
    if (isdigit(*(next + l))) {
      l++;
    } else {
      break;
    }
  }

  std::string subst(next, next + l);
  int ret = std::stoi(subst);

  next += l;
  return ret;
}

bool Lexer::is_extended_alpha(const char ch) {
  const std::unordered_set<char> extended_alphabet{
      '!', '$', '%', '&', '*', '+', '-', '.', '/',
      ':', '<', '=', '>', '?', '@', '^', '_', '~'};
  auto it = extended_alphabet.find(ch);
  return it != extended_alphabet.end();
}