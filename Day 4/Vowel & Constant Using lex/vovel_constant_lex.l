%option noyywrap
%{
#include<stdio.h>
#include<stdlib.h>
int vcount=0,ccount=0;    
%}
%%
[aeiouAEIOU] {vcount++;}
[a-zA-Z] {ccount++;}
%%


void main(){
    yyin=fopen("input.txt","r");
    yylex();
    printf("\nNo of Vowels present : %d\n",vcount);
    printf("No of consonents present : %d\n",ccount);
}