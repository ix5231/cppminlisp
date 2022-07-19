#include "interpreter.hpp"

#include <boost/format.hpp>
#include <cctype>
#include <stdexcept>
#include <string>
#include <unordered_set>

#include "util.hpp"

Interpreter::Interpreter(const std::string &_source)
    : source(_source), next(_source.begin()) {}

int Interpreter::parse() {
  if (*next != '(') {
    const char a = *next;
    const auto err = (boost::format("Expected ( but found %1%") % a).str();
    throw std::invalid_argument(err);
  }
  ++next;

  if (*next != '+') {
    const char a = *next;
    const auto err = (boost::format("Expected + but found %1%") % a).str();
    throw std::invalid_argument(err);
  }
  ++next;
  ++next;

  if (*next != '1') {
    const char a = *next;
    const auto err = (boost::format("Expected 1 but found %1%") % a).str();
    throw std::invalid_argument(err);
  }
  ++next;
  ++next;

  if (*next != '1') {
    const char a = *next;
    const auto err = (boost::format("Expected 1 but found %1%") % a).str();
    throw std::invalid_argument(err);
  }
  ++next;

  if (*next != ')') {
    const char a = *next;
    const auto err = (boost::format("Expected ) but found %1%") % a).str();
    throw std::invalid_argument(err);
  }

  return 1 + 1;
}

void Interpreter::next_token() {
  char ch = *next;
  int l = 0;

  while ((next + l) != source.end()) {
    if (isalpha(ch) || isdigit(ch) || is_extended_alpha(ch)) {
      l++;
    } else {
      next_len = l;
      next += l;
      return;
    }
  }
}

bool Interpreter::is_extended_alpha(const char ch){
  const std::unordered_set<char> extended_alphabet{'!', '$', '%', '&', '*', '+',
                                                   '-', '.', '/', ':', '<', '=',
                                                   '>', '?', '@', '^', '_', '~'};
  auto it = extended_alphabet.find(ch);
  return it != extended_alphabet.end();
}