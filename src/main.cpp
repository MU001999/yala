#include "YALC.hpp"


static ::std::tuple<::std::string, ::std::string> _parse_params(int argc, const char *argv[])
{
	return ::std::make_tuple("", "");
}


int main(int argc, const char *argv[])
{
	auto [ifile, ofile] = _parse_params(argc, argv);

	Lex lex(ifile);
	lex.run();
	lex.output(ofile == "" ? "out.cpp" : ofile);

	return 0;
}