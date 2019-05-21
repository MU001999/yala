#include <string>
#include <unordered_map>

#include "parse.hpp"
#include "codegen.hpp"
#include "../cre/cre.hpp"

#define ERRPROC exit(0)

using namespace std;
using namespace cre;
using namespace yala::parse;

namespace
{
const string prefix = 
R"yala(#include "cre.hpp"
)yala";
}

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
        code += source.substr(pos + 2, end_pos - pos - 2);
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
        appendix = source.find("%%", second_pos + 2);
    }

    if (!appendix.empty())
    {
        // ...
    }

    return code;
}
}