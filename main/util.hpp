#if !defined(UTIL_HPP)
#define UTIL_HPP

#include <stdexcept>

class NotImplemented : public std::logic_error
{
public:
    NotImplemented() : std::logic_error("Function not yet implemented") { };
};

#endif // UTIL_HPP