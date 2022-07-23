#if !defined(GC_HPP)
#define GC_HPP

#include <memory>

template <typename T> using Gc = std::shared_ptr<T>;

#endif // GC_HPP