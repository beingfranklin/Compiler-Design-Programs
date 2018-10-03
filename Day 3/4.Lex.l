
%{
	#include "y.tab.h"
%}

%%
[0-9]*	{yylval = atoi(yytext); return NUM;}
.	{return yytext[0];}
"\n"	{return NL;}
%%

int yywrap()
{
	printf("Lex exception");
}