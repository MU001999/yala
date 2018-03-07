#ifndef Lex_hpp
#define Lex_hpp

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

using std::string;

class Lex
{
public:
	Lex(const string&);
	~Lex() {};

	void run();
};

#endif