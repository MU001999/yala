#include <fstream>
#include "lex.hpp"

using namespace std;
using namespace yala;

Lex::Lex(const string &input_file)
{
    std::ifstream fin(input_file);
};


void Lex::output(const string &output_file)
{
    std::ofstream fout(output_file);
}