%{
  #include"abstree.h"
  //#include"scanner.h"
  #include<cstdio>
  #include<cstdlib>
  #include<string>
  #include<iostream>
  using namespace std;

  extern int yylex();
  extern int contador;

  extern node *Tree;
  	
  int yyerror(const char *);

  int rows=0, cols=0;
  table M;

  extern idTable ids;

  string id;
%}

%union{
	   float value;	//valor para expresiones numericas
	   matrix *mptr;	//puntero a matriz
	   node *mnode;	//puntero a nodo
	   char* str;	//cadena para almacenar id
}

%token <value> NUM
%token <mnode> ID
%token THROW

%type <value> exp term fact
%type <mnode> mexp mterm mfact
%type <mnode> mdef rowseq
%type <mnode> stseq st assign throwing 

%%

main:		stseq '.' {Tree= $1;}
			;

stseq:		stseq ';' st {$$=$3}
			| st {$$=$1}
			;

st:			assign {$$=$1}
			| throwing {$$=$1;}
			;

assign:		ID {id=yylval.str; /*cout<<"\nassign "<<id<<"\n";*/} ':' {ids[id]=NULL;} mexp { /*cout<<"\nmexp "<<id<<"\n";*/ ids[id]=$5->M; $$=$5;}
			;

throwing:	THROW mexp {/*printf("\nTHROW \n");*/ $$=$2; show(*evaluate($2));}
			;

mexp:		mexp '+' mterm {$$= newnode(_msuma, $1, $3);}
			| mexp '-' mterm {$$= newnode(_mresta, $1, $3);}
			| mterm {$$= $1}
			;

mterm:		mterm '*' mfact{$$= newnode(_mmulti, $1, $3);}
			| mfact {$$= $1}
			;

mfact:		'(' mexp ')' {$$= $2}
			| mdef {$$= $1}
			| ID {id=yylval.str; /*cout<<"\nmfact "<<id<<"\n";*/ /*show(*ids[yylval.str]);*/ /*$$= newnode(ids[yylval.str]->data,ids[yylval.str]->n,ids[yylval.str]->m);*/ $$=newnode(id);}
			;

mdef:		'[' {/*printf("\ninitM\n");*/} rowseq ']' {$$= newnode(M,rows,cols); /*show(M);*/ /*printf("\nfinM\n");*/ rows=0;cols=0; M.clear();}
			;

rowseq:		rowseq ';' {rows++;cols=0;} row {/*printf("\nrow:\n");*/}
			| {rows++;cols=0;} row  {/*printf("\nrow:\n");*/}
			;

row:		row ',' {cols++;} exp {/*printf("\n%f [%i,%i]\n",$4,rows,cols);*/ M[rows][cols]=$4;}
			| {cols++;} exp {/*printf("\n%f [%i,%i]\n",$2,rows,cols);*/ M[rows][cols]=$2;}
			;

exp:		exp '+' term {$$=$1 + $3;}
			| exp '-' term {$$=$1 - $3;}
			| term {$$=$1;}
			; 

term:		term '*' fact {$$=$1 * $3;}
			| term '/' fact {$$=$1 / $3;}
			| fact {$$=$1;}
			;

fact:		'-' fact {$$= (- $2);}
			| '(' exp ')' {$$=$2;}
			| NUM {$$=$1;}
			;

%%

int yyerror(const char *MSSG){printf("[%i] %s \n",contador,MSSG); return 0;}
