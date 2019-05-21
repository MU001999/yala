#ifndef YALC_LEX_HPP
#define YALC_LEX_HPP

#include <string>

namespace yala
{
class Lex
{
public:

    Lex(const std::string& ifile);
    ~Lex() = default;

    void output(const std::string&);
};
}

#endif // YALC_LEX_HPP