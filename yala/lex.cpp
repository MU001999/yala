#include <fstream>
#include "lex.hpp"

Lex::Lex(const std::string &input_file)
{
    std::ifstream fin(input_file);
};


void Lex::run()
{

}


void Lex::output(const std::string &output_file)
{
    std::ofstream fout(output_file);
}