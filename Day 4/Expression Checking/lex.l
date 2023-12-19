%{
#include<stdio.h>    
%}
%%
[0-9]+ {return NUMBER;}
[a-zA-Z_] {return CH;}
. {return yytext[0];}
\n {return 0;}
%% 