#include<cstdio>
#include<cstdlib>

#include"abstree.h"
#include"scanner.h"
//#include"parser.cpp"

extern FILE *yyin;

extern int yylex();
extern int yyparse();

node *Tree;

//extern int contador;

//*
bool parser()
{
	yyin=fopen("test.txt","r");
	
	int x=yyparse();
	
	fclose(yyin);
	
	return x==0;
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
	}
	else
	{
		printf("parser fallo\n");
	}
	//*/
	
	system("pause");
	return 0;
}
