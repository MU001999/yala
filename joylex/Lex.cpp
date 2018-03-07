#include "Lex.hpp"

Lex::Lex(const string& _out_file) 
{
	freopen(_out_file.c_str(), "w+", stdout);
};