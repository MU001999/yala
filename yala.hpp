#pragma once

#include <bitset>
#include <vector>
#include <string>
#include <memory>
#include <optional>
#include <functional>

namespace yala
{
namespace detail
{
struct NFANode
{
    enum EdgeType
    {
        EPSILON,
        CCL,
        EMPTY
    };

    EdgeType edge_type;
    std::bitset<256> input_set;
    std::shared_ptr<NFANode> next, next2;
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
