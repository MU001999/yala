# yala

yet another lexical analyzar


##### example
```lex
// example1.yala
%{
#include <vector>
#include <string>
#include <utility>

enum TOKEN
{
    TEND = 1,        // #

    TAT,         // @
    TATAT,       // @@

    TUSING,      // using
    TIF,         // if
    TELIF,       // elif
    TELSE,       // else
    TWHILE,      // while
    TDO,         // do
    TFOR,        // for
    TTO,         // to
    TFOREACH,    // foreach
    TAS,         // as
    TBREAK,      // break
    TCONTINUE,   // continue
    TRETURN,     // return
    TMATCH,      // match

    TNEW,        // new

    TNONE,       // none
    TTRUE,       // true
    TFALSE,      // false

    TIDENTIFIER, // [a-zA-Z_][a-zA-Z0-9_]*
    TINTEGER,    // [0-9]+
    TDOUBLE,     // [0-9]+\.[0-9]*
    TSTRING,     // "[^"\n]"

    TASSIGN,     // :
    TCOMMA,      // ,
    TDOT,        // .

    TLPAREN,     // (
    TRPAREN,     // )
    TLBRACKET,   // [
    TRBRACKET,   // ]
    TLBRACE,     // {
    TRBRACE,     // }

    TADD,        // +
    TSUB,        // -
    TMUL,        // *
    TDIV,        // /
    TMOD,        // %

    TBAND,       // &
    TBOR,        // |
    TBXOR,       // ^
    TBNEG,       // ~
    TBLS,        // <<
    TBRS,        // >>

    TAND,        // and
    TOR,         // or
    TNOT,        // not !

    TCEQ,        // =
    TCNE,        // !=
    TCLT,        // <
    TCLE,        // <=
    TCGT,        // >
    TCGE,        // >=

    TRET         // =>
};

struct Token
{
    TOKEN token_id;
    std::string value;

    Token(TOKEN token_id, std::string value = "")
      : token_id(token_id), value(std::move(value)) {}
};

std::vector<Token> tokens;

#define PUSH(args) tokens.emplace_back(args)

}%

ws          \s+
digit       [0-9]
string      "[^"\n]"
double      {digit}+\.{digit}*
integer     {digit}+
identifier  [a-zA-Z_][a-zA-Z0-9_]*

%%

{ws}            { ; }
{string}        { PUSH(TSTRING, yytext); }
{double}        { PUSH(TDOUBLE, yytext); }
{integer}       { PUSH(TINTEGER, yytext); }
{identifier}    { PUSH(TIDENTIFIER, yytext); }

using           { PUSH(TUSING); }
if              { PUSH(TIF); }
elif            { PUSH(TELIF); }
else            { PUSH(TELSE); }
while           { PUSH(TWHILE); }
do              { PUSH(TDO); }
for             { PUSH(TFOR); }
to              { PUSH(TTO); }
foreach         { PUSH(TFOREACH); }
as              { PUSH(TAS); }
break           { PUSH(TBREAK); }
continue        { PUSH(TCONTINUE); }
return          { PUSH(TRETURN); }
match           { PUSH(TMATCH); }
new             { PUSH(TNEW); }
none            { PUSH(TNONE); }
true            { PUSH(TTRUE); }
false           { PUSH(TFALSE); }
and             { PUSH(TAND); }
or              { PUSH(TOR); }
not             { PUSH(TNOT); }

"#"             { PUSH(TEND); }
"@"             { PUSH(TAT); }
"@@"            { PUSH(TATAT); }
":"             { PUSH(TASSIGN); }
";"             { PUSH(TCOMMA); }
"."             { PUSH(TDOT); }
"("             { PUSH(TLPAREN); }
")"             { PUSH(TRPAREN); }
"["             { PUSH(TLBRACKET); }
"]"             { PUSH(TRBRACKET); }
"{"             { PUSH(TLBRACE); }
"}"             { PUSH(TRBRACE); }
"+"             { PUSH(TADD); }
"-"             { PUSH(TSUB); }
"*"             { PUSH(TMUL); }
"/"             { PUSH(TDIV); }
"%"             { PUSH(TMOD); }
"&"             { PUSH(TBAND); }
"|"             { PUSH(TBOR); }
"^"             { PUSH(TBXOR); }
"~"             { PUSH(TBNEG); }
"<<"            { PUSH(TBLS); }
">>"            { PUSH(TBRS); }
"!"             { PUSH(TNOT); }
"="             { PUSH(TCEQ); }
"!="            { PUSH(TCNE); }
"<"             { PUSH(TCLT); }
"<="            { PUSH(TCLE); }
">"             { PUSH(TCGT); }
">="            { PUSH(TCGE); }
"=>"            { PUSH(TRET); }

.               { ; }

%%

int main(int argc, char *argv[])
{
    while (TOKEN token_id = yylex());

    for (auto &token : tokens)
    {
        std::cout << token.token_id << " " << token.value << std::endl;
    }

    return 0;
}

```