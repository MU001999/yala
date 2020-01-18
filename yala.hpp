#pragma once

#include <vector>
#include <string>

namespace yala
{
namespace detail
{
struct NFANode
{

};

struct NFAPair
{

};

struct DFANode
{

};

class PatternParser
{

};
}

struct Token
{
    std::string_view id;
    std::string value;
};

class Tokenizer
{
  public:
    Tokenizer() = default;

    Token next();

    void add_token_type(const std::string &id,
        const std::string &pattern);

  private:
    std::vector<std::string> ids_;
};
}
