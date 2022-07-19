#if !defined(INTERPRETER_HPP)
#define INTERPRETER_HPP

#include <string>

class Interpreter {
  private:
    const std::string &source;
    std::string::const_iterator next;
    int next_len = 0;
    void next_token();
    bool is_extended_alpha(const char ch);
  public:
    Interpreter(const std::string &_source);
    int parse();
};

#endif // INTERPRETER_HPP