%{
  #include"abstree.h"
  //#include"scanner.h"
  #include<cstdio>
  #include<cstdlib>

  extern int yylex();
  extern int contador;

  extern node *Tree;
  	
  int yyerror(const char *);
%}

%union{
	   float val;
	   char *string;
	   node *p;
}

%token NUM
%token ID
%token THROW

%%

main:		stseq '.'
			;

stseq:		stseq ';' st
			| st
			;

st:			assign
			| throwing
			;

assign:		ID ':' mexp
			;

throwing:	THROW mexp
			;

mexp:		mexp '+' mterm
			| mexp '-' mterm
			| mterm
			;

mterm:		mterm '*' mfact
			| mfact
			;

mfact:		'(' mexp ')'
			| mdef 
			| ID
			;

mdef:		'[' rowseq ']'
			;

rowseq:		rowseq ';' row
			| row
			;

row:		row ',' exp
			| exp
			;

exp:		exp '+' term
			| exp '-' term
			| term
			; 

term:		term '*' fact
			| term '/' fact
			| fact
			;

fact:		'-' fact
			| '(' exp ')'
			| NUM
			;

%%

int yyerror(const char *MSSG){printf("[%i] %s \n",contador,MSSG); return 0;}
