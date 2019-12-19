%{
  //#include"parser.cpp"
  #include"parser.hpp"
  //#include"abstree.h"
  #include<cstdio>
  
  extern YYSTYPE yylval;
  int contador=1;
%}

numero [0-9]+("."[0-9]+)?
id [a-zA-Z]([a-zA-Z]|[0-9])*
espacio [ \t]
nlinea \n
op [-+*/]
cord "]"
cori "["
delim [()]
punt [.,;:]

%%
throw return THROW;
{id}  {yylval.str=yytext; return ID;}
{numero} {yylval.value = atof(yytext); return NUM;}
{espacio} /*ignorar*/;
{nlinea} contador++;
{op} return *yytext;
{delim} return *yytext;
{punt} return *yytext;
{cord} return *yytext;
{cori} return *yytext;
<<EOF>> {printf("-EOF-"); return 0;}

%%

int yywrap()	{return 1;}
