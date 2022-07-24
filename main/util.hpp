#if !defined(UTIL_HPP)
#define UTIL_HPP

#include <cstdio>
#include <stdexcept>

#define debug(fmt, ...)                                                        \
  fprintf(stderr, "[%s L%d] ", __FILE__, __LINE__);                            \
  fprintf(stderr, fmt, __VA_ARGS__)
#define debugln(msg) debug("%s\n", msg)

class NotImplemented : public std::logic_error {
public:
  NotImplemented() : std::logic_error("Function not yet implemented"){};
};

#endif // UTIL_HPP