#ifndef YALC_LEX_HPP
#define YALC_LEX_HPP

#include <string>

class Lex
{
public:

	Lex(const std::string &);
	~Lex() {};

	void run();

	void output(const std::string &);
};

#endif // YALC_LEX_HPP