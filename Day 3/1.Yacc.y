%{
	#include<stdio.h>
	#include "lex.yy.c"
%}

%token SW OB ID CB NL COB CS NUM Q BR SEM CCB

%%
S:	X NL	{printf("Valid");}
 ;
X:	SW OB ID CB NL COB NL CS NUM Q ID NL BR SEM NL CCB NL
 ;
%%

void main()
{
	yyparse();
}

int yyerror()
{
	printf("Invalid\n");
}
