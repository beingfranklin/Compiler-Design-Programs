%{
 #include<stdio.h>
 
%}

digit [0-9]
letter [A-Za-z]
%%
[()+!#<>.;"%,{}=-]
if|else|int|float|void|char|include|stdio.h|printf|main
"({letter}|{digit})"
{digit}({digit}|{letter})*

{letter}({letter}|{digit})*  printf("%s",yytext);
%%

void main()
{

yyin=fopen("input2.txt","r");
printf("Identifiers:\n");
yylex();

}
