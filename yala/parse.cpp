#include <cctype>
#include <unordered_map>

#include "parse.hpp"

#define ERRPROC abort()

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
        string name, regex;
        while (start < end_pos && isspace(source[start])) ++start;
        while (start < end_pos && !isspace(source[start])) name += source[start++];
        
        if (name.empty()) break;

        while (start < end_pos && isspace(source[start])) if (source[start] == '\n') ERRPROC; else ++start;
        while (start < end_pos && source[start] != '\n')
        {
            if (source[start] == '{')
            {
                auto pos = source.find('}', start);
                if (pos == source.npos) ERRPROC;
                auto target = source.substr(start + 1, pos - start - 1);
                if (!regexs.count(target)) ERRPROC;
                regex += '(' + regexs[target] + ')';
                start = pos + 1;
            }
            else regex += source[start++];
        }

        if (regex.empty()) ERRPROC;

        auto pos = regex.size() - 1;
        while (isspace(regex[pos])) --pos;
        regexs[name] = regex.substr(0, pos + 1);
    }

    return regexs;
}
} // namespace

namespace yala::parse
{
vector<pair<string, string>>
parse_action(const string &source, size_t first_pos)
{
    vector<pair<string, string>> actions;
    auto regexs = parse_regex(source, first_pos);

    auto start = first_pos + 2, end_pos = source.size();
    while (start < end_pos)
    {
        string regex, action = "{";
        while (start < end_pos && isspace(source[start])) ++start;
        while (start < end_pos && !isspace(source[start]))
        {
            if (source[start] == '{')
            {
                auto pos = source.find('}', start);
                if (pos == source.npos) ERRPROC;
                auto target = source.substr(start + 1, pos - start - 1);
                if (!regexs.count(target)) ERRPROC;
                regex += '(' + regexs[target] + ')';
                start = pos + 1;
            }
            else if (source[start] == '"')
            {
                auto pos = source.find('"', start + 1);
                if (pos == source.npos) ERRPROC;
                auto raw = source.substr(start + 1, pos - start - 1);
                for (auto c : raw) regex += "\\"s + c;
                start = pos + 1;
            }
            else regex += source[start++];
        }
        if (regex.empty()) break;
        while (start < end_pos && source[start] != '{') ++start;

        int left = 1;
        if (source[start++] != '{') ERRPROC;
        
        while (start < end_pos && left > 0)
        {
            if (source[start] == '}') --left;
            else if (source[start] == '{') ++left;
            action += source[start++];
        }

        if (action == "{") ERRPROC;

        actions.push_back({ regex, action });
    }

    return actions;
}
} // namespace yala::parse