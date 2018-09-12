%{
#include<stdio.h>
#include<stdlib.h>
%}
%%
0(10|01)*	{printf("Valid \n");}
.*	{printf("Invalid \n");}
%%
void main()
{
	yylex();
}
