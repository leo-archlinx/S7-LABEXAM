%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
int word=0,line=0,cha=0;
%}

%%
\n {line++;cha+=yyleng;}
[^\t\n ]+ {word++;cha+=yyleng;}
%%


void main(){
    yyin=fopen("input.txt","r");
    yylex();
    printf("\nNo of lines %d\n",line);
    printf("No of Words %d\n",word);
    printf("No of Charecters %d\n",cha);
}