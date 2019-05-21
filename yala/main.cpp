#include <tuple>

#include "lex.hpp"

using namespace std;
using namespace yala;

static tuple<string, string> _parse_params(int argc, const char *argv[])
{
    return make_tuple("", "");
}

int main(int argc, char *argv[])
{
    auto [ifile, ofile] = _parse_params(argc, argv);

    Lex(ifile).output(ofile == "" ? "out.cpp" : ofile);

    return 0;
}