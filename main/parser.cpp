#include "parser.hpp"

#include <string>
#include <stdexcept>
#include <boost/format.hpp>

#include "util.hpp"

int parse(const std::string &source) {
  auto next = source.begin();
  
  if (*next != '(') {
    const char a = *next;
    const auto err = (boost::format("Expected ( but found %1%") % a).str();
    throw std::invalid_argument(err);
  }
  next++;
  
  if (*next != '+') {
    const char a = *next;
    const auto err = (boost::format("Expected + but found %1%") % a).str();
    throw std::invalid_argument(err);
  }
  next++;
  next++;
  
  if (*next != '1') {
    const char a = *next;
    const auto err = (boost::format("Expected 1 but found %1%") % a).str();
    throw std::invalid_argument(err);
  }
  next++;
  next++;
  
  if (*next != '1') {
    const char a = *next;
    const auto err = (boost::format("Expected 1 but found %1%") % a).str();
    throw std::invalid_argument(err);
  }
  next++;

  if (*next != ')') {
    const char a = *next;
    const auto err = (boost::format("Expected ) but found %1%") % a).str();
    throw std::invalid_argument(err);
  }
  
  return 1 + 1;
}