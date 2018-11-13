#include "YALC.hpp"


Lex::Lex(const ::std::string _input_file)
{
    ::std::ifstream fin(_input_file);
};


void Lex::run()
{

}


void Lex::output(const ::std::string _output_file)
{
    ::std::ofstream fout(_output_file);
}