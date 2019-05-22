#include <tuple>

#include "lex.hpp"

using namespace std;
using namespace yala;

static tuple<string, string> _parse_params(int argc, char *argv[])
{
    return make_tuple("../example/ice.yala", "out.yala.cpp");
}

int main(int argc, char *argv[])
{
    auto [ifile, ofile] = _parse_params(argc, argv);
    Lex(ifile).output(ofile.empty() ? "out.yala.cpp"s : ofile);
    return 0;
}