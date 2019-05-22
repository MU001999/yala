#include "parse.hpp"

using namespace std;

namespace yala::parse
{
unordered_map<string, string>
parse_action(const string &source)
{
    return {
        { "abc", "{ return 0; }" }
    };
}
}