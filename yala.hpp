#pragma once

#include <vector>
#include <string>
#include <optional>
#include <functional>

namespace yala
{
namespace detail
{
struct NFANode
{
    std::optional<std::size_t> return_id;
};

struct NFAPair
{

};

struct DFANode
{
    std::optional<std::size_t> return_id;
};

class PatternParser
{
  public:
    void add_token_type(const std::string &id,
        const std::string &pattern);

    void compile();
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

    void compile();

  private:
    std::vector<std::string> ids_;
};
}
