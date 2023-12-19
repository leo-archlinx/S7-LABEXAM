%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>    
int i;
%}
%%
[a-zA-Z]* {
    for(i=0;i<=yyleng;i++)
    {
        if((yytext[i]=='a') && (yytext[i+1]=='b') && (yytext[i+2]=='c'))
        {
            yytext[i]='A';
            yytext[i+1]='B';
            yytext[i+2]='C';
        }
    }
    printf("%s",yytext);
}
%%

void main(){
    printf("Enter the String to chek : \n");
    yylex();
}
