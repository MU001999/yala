#include <fstream>
#include <streambuf>

#include "lex.hpp"
#include "parse.hpp"
#include "codegen.hpp"

using namespace std;
using namespace yala;
using namespace codegen;

Lex::Lex(const string &ifile)
{
    ifstream fin(ifile);
    source_ = string(istreambuf_iterator<char>(fin), istreambuf_iterator<char>());
    fin.close();
}

void Lex::output(const string &ofile)
{
    ofstream fout(ofile);

    auto code = gen_code(source_);
    fout.write(code.c_str(), code.size());

    fout.close();
}