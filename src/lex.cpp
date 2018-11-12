#include "YALC.hpp"


Lex::Lex(const ::std::string& _out_file)
{
	freopen(_out_file.c_str(), "w+", stdout);
};