%{
	#include<stdio.h>
%}

%token SW OB ID CB NL COB CS NUM Q BR SEM CCB

%%
S:	X NL	{printf("Valid");}
 ;
X: ID
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
