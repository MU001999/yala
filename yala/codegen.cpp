#include <string>
#include <unordered_map>

#include "parse.hpp"
#include "codegen.hpp"
#include "../cre/cre.hpp"

#define ERRPROC abort()

using namespace std;
using namespace cre;
using namespace yala::parse;

namespace
{
const string prefix = 
R"yala(##include <tility>
include <string>
#include <vector>
#include <iostream>
#include <functional>

#include "cre.hpp"

int yylex();
)yala";

string gen_yylex(unordered_map<string, string> &actions)
{
    string patterns = R"yala(static std::vector<std::pair<cre::Pattern, std::function<void()>>> patterns = 
    {
)yala";
    for (auto &re_action : actions)
        patterns += "        { "s + re_action.first + ", "s + "[&] " + re_action.second + " },\n";
    patterns += "    }\n";

    string code = R"yala(
int yylex()
{
    )yala"s + patterns + R"yala(
    static std::string input, yytext, now;
    static std::size_t pos = 0;
    char c;
    while (std::cin >> c) input += c;
    while (pos < input.size())
    {
        now.clear(); yytext.clear();
        std::function<int()> func;

        for (auto &pattern_func : patterns)
        {
            now = pattern_func.first.match(source);
            if (now.size() > yytext.size())
            {
                yytext = now;
                func = pattern_func.second;
            }
        }
        input = input.substr(pos + yytext.size());
        return func();
    }
    return 0;
}
)yala"s;
    return code;
}
} // namespace

namespace yala::codegen
{
string gen_code(const string &source)
{
    string code = prefix, appendix;

    auto pos = source.find("%{");
    if (pos != source.npos)
    {
        auto end_pos = source.find("%}");
        if (end_pos == source.npos) ERRPROC;
        code += source.substr(pos + 2, end_pos - pos - 2) + "\n\n";
    }

    pos = source.find("%%");
    if (pos == source.npos) ERRPROC;
    
    unordered_map<string, string> actions;

    auto second_pos = source.find("%%", pos + 2);
    if (second_pos == source.npos) // without second %%
    {
        actions = parse_action(source.substr(pos + 2));
    }
    else // with second %%
    {
        actions = parse_action(source.substr(pos + 2, second_pos - pos - 2));
        code += source.substr(second_pos + 2) + "\n\n";
    }
    
    if (!actions.empty()) code += gen_yylex(actions);

    return code;
}
}