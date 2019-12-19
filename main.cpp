#include<cstdio>
#include<cstdlib>

#include"abstree.h"
#include"scanner.h"
//#include"parser.cpp"
#include<iostream>
using namespace std;

extern FILE *yyin;

extern int yylex();
extern int yyparse();

node *Tree;

//extern int contador;
char nombrearchivo[50];
//*
bool parser()
{
	cout<<"nombre y extencion del archivo: ";
	cin>>nombrearchivo;
	cout<<endl;
	if(fopen(nombrearchivo,"r"))
	{
		yyin=fopen(nombrearchivo,"r");
		
		int x=yyparse();
		
		fclose(yyin);
		
		return x==0;
	}
	cout<<"\nError: El archivo no existe\n";
	return false;
}//*/	

int main()
{
	/*
	yyin=fopen("test.txt","r");
	
	yylex();
	
	fclose(yyin);
	//*/
	//*	
	if(parser())
	{
		printf("parser correcto\n");
		printf("\nRECORRIDO\n");
		recorrer(Tree);
		borrar(Tree);
		//show(*evaluate(Tree));
	}
	else
	{
		printf("parser fallo\n");
	}
	//*/	
	system("pause");
	return 0;
}
