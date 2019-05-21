#include <fstream>
#include <streambuf>

#include "lex.hpp"
#include "parse.hpp"

using namespace std;
using namespace yala;

Lex::Lex(const string &ifile)
{
    ifstream fin(ifile);
    source_ = string(istreambuf_iterator<char>(fin), istreambuf_iterator<char>());
    fin.close();
}

void Lex::output(const string &ofile)
{
    ofstream fout(ofile);
    // parse source and generate code
    fout.close();
}