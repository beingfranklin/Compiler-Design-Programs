%{
	#include "y.tab.h"
%}

%%
[0-9]*	{return NUM;}
.	{return yytext[0];}
"\n"	{return NL;}
%%

int yywrap()
{

}
