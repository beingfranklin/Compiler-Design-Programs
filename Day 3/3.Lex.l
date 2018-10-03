%{
	#include "y.tab.h"
%}

id [a-z]([a-z]|[0-9])*

%%
"switch"	{return SW;}
"("		{return OB;}
")"		{return CB;}
"\n"		{return NL;}
"{"		{return COB;}
"case"		{return CS;}
[0-9]*		{return NUM;}
":"		{return Q;}
"break"		{return BR;}
";"		{return SEM;}
"}"		{return CCB;}
{id}		{return ID;}
%%
	
int yywrap()
{
	printf("Invalid in lex");
}
