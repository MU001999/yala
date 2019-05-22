#ifndef YALA_PARSE_HPP
#define YALA_PARSE_HPP

#include <string>
#include <unordered_map>

namespace yala
{
namespace parse
{
std::unordered_map<std::string, std::string>
parse_action(const std::string &source);
}
}

#endif // YALA_PARSE_HPP