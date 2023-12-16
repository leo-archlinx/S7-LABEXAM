%{
    #include<stdio.h>
%}

%%
if|else|while|do|for|switch|return|int|void|main|float {
    printf("its a identifier %s\n",yytext);
}
[a-zA-Z0-9]* {
    printf("its an identifier %s\n",yytext);
}
"{"|"}"|"("|")"|"["|"]" {
    printf("its a parathesis %s\n",yytext);
}
"\*"|"\/"|"\-"|"\+"|"\=" {
    printf("its an operator %s\n",yytext);
}
%%

int yywrap(){
    return 1;
}

void main(){
    printf("Enter the string \n");
    yylex();
}