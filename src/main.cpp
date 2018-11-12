#include "YALC.hpp"


int main(int argc, const char *argv[])
{
	const ::std::string out_file("out.cpp");
	Lex lex(out_file);
	lex.run();

	return 0;
}