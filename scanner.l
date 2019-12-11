%{
  #include"parser.cpp"
  //#include"abstree.h"
  #include<cstdio>
  
  extern YYSTYPE yyval;
  int contador=1;
%}

numero [0-9]+("."[0-9]+)?
id [a-zA-Z]([a-zA-Z]|[0-9])*
espacio [ \t]
nlinea \n
op [-+*/]
cord []]
cori [[]
delim [()]
punt [.,;:]

%%
{id}  { if(yytext=="throw") return THROW;
        /*yyval.string = yytext;*/ return ID; /*printf("id: %s %i\n",yytext,yyleng);*/ }
{numero} { /*yyval.val = atof(yytext);*/ return NUM;}
{espacio} { /*ignorar*/ }
{nlinea} { contador++; }
{op} { return *yytext; }
{delim} { return *yytext; }
{punt} { return *yytext; }
{cord} { /*printf("cord ");*/ return *yytext; }
{cori} { /*printf("cori %s ",yytext);*/ return *yytext; }
<<EOF>> {printf("-EOF-"); return 0;}

%%

int yywrap()	{return 1;}