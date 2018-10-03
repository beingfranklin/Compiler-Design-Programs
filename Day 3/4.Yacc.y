%{
	#include<stdio.h>
%}

%token NUM NL

%left '+' '-'
%left '*' '/'
%left '(' ')'

%%
S:	E NL	{printf("Result = %d", $1);}
E:	E '+' E	{$$ = $1 + $3;}
 |	E '-' E {$$ = $1 - $3;}
 |	E '*' E	{$$ = $1 * $3;}
 |	E '/' E {$$ = $1 / $3;}
 |	'(' E ')'	{$$ = $2;}
 |	NUM	{$$ = $1;}
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