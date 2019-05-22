# yala

yet another lexical analyzar

##### example

```lex
// ice.yala
%{
#include <vector>
#include <string>
#include <utility>

enum TOKEN
{
    TEND = 1,    // #

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
{string}        { PUSH(TSTRING, yytext); return 0; }
{double}        { PUSH(TDOUBLE, yytext); return 0; }
{integer}       { PUSH(TINTEGER, yytext); return 0; }
{identifier}    { PUSH(TIDENTIFIER, yytext); return 0; }

using           { PUSH(TUSING); return 0; }
if              { PUSH(TIF); return 0; }
elif            { PUSH(TELIF); return 0; }
else            { PUSH(TELSE); return 0; }
while           { PUSH(TWHILE); return 0; }
do              { PUSH(TDO); return 0; }
for             { PUSH(TFOR); return 0; }
to              { PUSH(TTO); return 0; }
foreach         { PUSH(TFOREACH); return 0; }
as              { PUSH(TAS); return 0; }
break           { PUSH(TBREAK); return 0; }
continue        { PUSH(TCONTINUE); return 0; }
return          { PUSH(TRETURN); return 0; }
match           { PUSH(TMATCH); return 0; }
new             { PUSH(TNEW); return 0; }
none            { PUSH(TNONE); return 0; }
true            { PUSH(TTRUE); return 0; }
false           { PUSH(TFALSE); return 0; }
and             { PUSH(TAND); return 0; }
or              { PUSH(TOR); return 0; }
not             { PUSH(TNOT); return 0; }

"#"             { PUSH(TEND); return 0; }
"@"             { PUSH(TAT); return 0; }
"@@"            { PUSH(TATAT); return 0; }
":"             { PUSH(TASSIGN); return 0; }
";"             { PUSH(TCOMMA); return 0; }
"."             { PUSH(TDOT); return 0; }
"("             { PUSH(TLPAREN); return 0; }
")"             { PUSH(TRPAREN); return 0; }
"["             { PUSH(TLBRACKET); return 0; }
"]"             { PUSH(TRBRACKET); return 0; }
"{"             { PUSH(TLBRACE); return 0; }
"}"             { PUSH(TRBRACE); return 0; }
"+"             { PUSH(TADD); return 0; }
"-"             { PUSH(TSUB); return 0; }
"*"             { PUSH(TMUL); return 0; }
"/"             { PUSH(TDIV); return 0; }
"%"             { PUSH(TMOD); return 0; }
"&"             { PUSH(TBAND); return 0; }
"|"             { PUSH(TBOR); return 0; }
"^"             { PUSH(TBXOR); return 0; }
"~"             { PUSH(TBNEG); return 0; }
"<<"            { PUSH(TBLS); return 0; }
">>"            { PUSH(TBRS); return 0; }
"!"             { PUSH(TNOT); return 0; }
"="             { PUSH(TCEQ); return 0; }
"!="            { PUSH(TCNE); return 0; }
"<"             { PUSH(TCLT); return 0; }
"<="            { PUSH(TCLE); return 0; }
">"             { PUSH(TCGT); return 0; }
">="            { PUSH(TCGE); return 0; }
"=>"            { PUSH(TRET); return 0; }

.               { ; }

%%

int main(int argc, char *argv[])
{
    while (int res = yylex());

    for (auto &token : tokens)
    {
        std::cout << token.token_id << " " << token.value << std::endl;
    }

    return 0;
}

```