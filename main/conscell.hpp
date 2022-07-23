#if !defined(CONSCELL_HPP)
#define CONSCELL_HPP

#include <memory>

#include "value.hpp"

struct ConsCell {
  std::unique_ptr<Value> car;
  std::unique_ptr<Value> cdr;
};

#endif // CONSCELL_HPP
