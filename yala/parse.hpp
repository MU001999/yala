#ifndef YALA_PARSE_HPP
#define YALA_PARSE_HPP

#include <string>
#include <vector>
#include <utility>

namespace yala
{
namespace parse
{
std::vector<std::pair<std::string, std::string>>
parse_action(const std::string &source, size_t first_pos);
} // namespace parse
} // namespace yala

#endif // YALA_PARSE_HPP