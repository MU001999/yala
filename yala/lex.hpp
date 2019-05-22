#ifndef YALA_LEX_HPP
#define YALA_LEX_HPP

#include <string>

namespace yala
{
class Lex
{
  public:
    Lex(const std::string &ifile);
    ~Lex() = default;

    void output(const std::string &ofile);

  private:
    std::string source_;
};
} // namespace yala

#endif // YALA_LEX_HPP