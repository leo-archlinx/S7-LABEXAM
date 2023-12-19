%{
#include<stdio.h>
#include "lex.yy.c"
int f =0;
int yyerror();    
%}
%token NUMBER CH
%left '+''-'
%left '*''/'
%%
E:E'+'E {f=1;}
|E'-'E {f=1;}
|E'*'E {f=1;}
|'('E')' {f=1;}
|NUMBER
|CH
%%
