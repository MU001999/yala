#ifndef YALA_PARSE_HPP
#define YALA_PARSE_HPP

#include <unordered_map>

namespace yala
{
namespace parse
{
std::unordered_map<std::string, std::string>
parse_re(const std::string &source);

std::unordered_map<std::string, std::string>
parse_actions(const std::string &source);
}
}

#endif // YALA_PARSE_HPP