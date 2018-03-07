#include <iostream>
#include <string>
#include <cstring>
#include "Lex.hpp"

using std::string;

int main(int argc, const char *argv[])
{
	const string out_file("out.c");
	Lex lex(out_file);
	lex.run();

	return 0;
}