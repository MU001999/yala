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
R"yala(#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <functional>

#include "cre.hpp"

int yylex();
)yala";

string gen_yylex(std::vector<std::pair<std::string, std::string>> &actions)
{
    string patterns = R"yala(static std::vector<std::pair<cre::Pattern, std::function<int()>>> patterns = 
    {
)yala";
    for (auto &re_action : actions)
        patterns += "        { cre::Pattern(R\"("s + re_action.first + ")\"), "s + "[&]() -> int " + re_action.second + " },\n";
    patterns += "    };\n";

    string code = R"yala(
int yylex()
{
    static std::string input, yytext, now;
    static std::size_t pos = 0;
    )yala"s + patterns + R"yala(
    char c;
    while (std::cin >> c) input += c;
    while (pos < input.size())
    {
        now.clear(); yytext.clear();
        std::function<int()> func;

        for (auto &pattern_func : patterns)
        {
            now = pattern_func.first.match(input);
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
})yala"s;
    return code;
}
} // namespace

namespace yala::codegen
{
string gen_code(const string &source)
{
    string code = prefix, appendix;

    size_t pos = source.find("%{"), end_pos = source.npos;
    if (pos != source.npos)
    {
        end_pos = source.find("%}");
        if (end_pos == source.npos) ERRPROC;
        code += source.substr(pos + 2, end_pos - pos - 2) + "\n\n";
    }
    
    end_pos = end_pos == source.npos ? 0 : end_pos + 2;

    pos = source.find("%%");
    if (pos == source.npos) ERRPROC;
    
    std::vector<std::pair<std::string, std::string>> actions;

    auto second_pos = source.find("%%", pos + 2);
    if (second_pos == source.npos) // without second %%
    {
        actions = parse_action(source.substr(end_pos), pos - end_pos);
    }
    else // with second %%
    {
        actions = parse_action(source.substr(end_pos, second_pos - end_pos), pos - end_pos);
        code += source.substr(second_pos + 2) + "\n\n";
    }
    
    if (!actions.empty()) code += gen_yylex(actions);

    return code;
}
} // namespace yala::codegen