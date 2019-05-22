#include <cctype>

#include "parse.hpp"

using namespace std;

namespace
{
unordered_map<string ,string>
parse_regex(const string &source, size_t end_pos)
{
    unordered_map<string, string> regexs;

    size_t start = 0;
    while (start < end_pos)
    {
        // init regexs
    }

    return regexs;
}
} // namespace

namespace yala::parse
{
unordered_map<string, string>
parse_action(const string &source, size_t first_pos)
{
    unordered_map<string, string> actions, regexs;
    regexs = parse_regex(source, first_pos);

    auto start = first_pos + 2;
    while (start < source.size())
    {
        // init actions with regexs
    }

    return actions;
}
} // namespace yala::parse