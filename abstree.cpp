#include"abstree.h"
#include<cstdlib>
#include<cstdio>
#include<map>
#include<iostream>
using namespace std;

idTable ids;

void show(matrix &M)
{
	if(&M==NULL){printf("\nError: Referencia nulla al evaluar la matriz\n");return;}
 	printf("\n");
 	printf("show: [%i][%i]\n",M.n,M.m);
 	
 	if((M.n==0 || M.m==0))
	{
		printf("\nError: Error al evaluar la matriz\n");
		return;	 
	}
 	
	for(int i=1;i<=M.n;i++)
	{
		for(int j=1;j<=M.m;j++)
		{
			printf("%f,",M.data[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

matrix *add(matrix *A, matrix *B)
{
	if(A==NULL || B==NULL){printf("\nError: referencia nula al evaluar\n");return NULL;}
	//printf("\nsuma\n");
	matrix *a=new matrix;
	matrix *b=new matrix;
	matrix *c=new matrix;
	
	a->n=A->n;
	a->m=A->m;
	a->data=A->data;
	
	b->n=B->n;
	b->m=B->m;
	b->data=B->data;
	
	//show(*a);
	//show(*b);
	int n,m;
	table data;
	if(a->n==b->n && a->m==b->m)
	{
		n=a->n;
		m=a->m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				data[i][j]= a->data[i][j] + b->data[i][j];
			}
		}
		c->n=n;
		c->m=m;
		c->data=data;
		//show(*c);
		//printf("\nfin suma\n");
		return c;
	}
	else printf("\nError: Las matrises no tiene dimensiones adecuadas\n");
	
	return NULL;	
}

matrix *subs(matrix *A, matrix *B)
{
	if(A==NULL || B==NULL){printf("\nError: referencia nula al evaluar\n");return NULL;}
	//printf("\nrest\n");
	matrix *a=new matrix;
	matrix *b=new matrix;
	matrix *c=new matrix;
	
	a->n=A->n;
	a->m=A->m;
	a->data=A->data;
	
	b->n=B->n;
	b->m=B->m;
	b->data=B->data;
	
	//show(*a);
	//show(*b);
	int n,m;
	table data;
	if(a->n==b->n && a->m==b->m)
	{
		n=a->n;
		m=a->m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				data[i][j]= a->data[i][j] - b->data[i][j];
			}
		}
		c->n=n;
		c->m=m;
		c->data=data;
		//show(*c);
		//printf("\nfin resta\n");
		return c;
	}
	else printf("\nError: Las matrises no tiene dimensiones adecuadas\n");
	
	return NULL;
}

matrix *mult(matrix *A, matrix *B)
{
	//printf("[%i][%i]*[%i][%i] ",A->n,A->m,B->n,B->m);
	//printf("\nmulti\n");
	if(A==NULL || B==NULL){printf("\nError: referencia nula al evaluar\n");return NULL;}
	matrix *a=new matrix;
	matrix *b=new matrix;
	matrix *c=new matrix;
	
	a->n=A->n;
	a->m=A->m;
	a->data=A->data;
	
	b->n=B->n;
	b->m=B->m;
	b->data=B->data;
	
	//show(*a);
	//show(*b);
	int n,m;
	table data;
	
	if(a->m==b->n)
	{
		n=a->n;
		m=b->m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				for(int k=1;k<=a->m;k++)
				{
					data[i][j]=(a->data[i][k]*b->data[k][j])+data[i][j];
				}
			}
		}
		c->n=n;
		c->m=m;
		c->data=data;
		//show(*c);
		//printf("\nfin multi\n");
		return c;
	}
	else printf("\nError: Las matrises no tiene dimensiones adecuadas\n");
	
	return NULL;
}

matrix *evaluate(node *p)
{
	
	matrix *R= new matrix;
	if(p==NULL){printf("\nError: referencia nula al evaluar\n");return NULL;}
	switch(p->type)
	{
		case _msuma:
			//printf("\nsuma [%i][%i]+[%i][%i]\n",p->lft->M->n,p->lft->M->m,p->rgt->M->n,p->rgt->M->m);
			//return add(p->lft->M, p->rgt->M);
			//R->data=add(evaluate(p->lft),evaluate(p->rgt))->data;
			//R->n=add(evaluate(p->lft),evaluate(p->rgt))->n;
			//R->m=add(evaluate(p->lft),evaluate(p->rgt))->m;
			R=add(evaluate(p->lft),evaluate(p->rgt));
			//printf("\nC suma\n");
			//show(*R);
			return R;
			break;
			
		case _mresta:
			//printf("\nresta [%i][%i]-[%i][%i]\n",p->lft->M->n,p->lft->M->m,p->rgt->M->n,p->rgt->M->m);
			//return subs(p->lft->M, p->rgt->M);
			//R->data=subs(evaluate(p->lft),evaluate(p->rgt))->data;
			//R->n=subs(evaluate(p->lft),evaluate(p->rgt))->n;
			//R->m=subs(evaluate(p->lft),evaluate(p->rgt))->m;
			R=subs(evaluate(p->lft),evaluate(p->rgt));
			//printf("\nC resta\n");
			show(*R);
			return R;
			break;
			
		case _mmulti:
			//printf("\nmulti [%i][%i]*[%i][%i]\n",p->lft->M->n,p->lft->M->m,p->rgt->M->n,p->rgt->M->m);
			//return mult(p->lft->M, p->rgt->M);
			//R->data=mult(evaluate(p->lft),evaluate(p->rgt))->data;
			//R->n=mult(evaluate(p->lft),evaluate(p->rgt))->n;
			//R->m=mult(evaluate(p->lft),evaluate(p->rgt))->m;
			R=mult(evaluate(p->lft),evaluate(p->rgt));
			//printf("\nC multi\n");
			//show(*R);
			return R;
			break;
			
		case _matrix:
			//printf("\n---matriz");show(*p->M);printf("---\n");
			return p->M;
			break;
	}
	return NULL;
}

node *newnode(string id)
{
	node *p=new node;
	
	matrix *M=new matrix;
	//newnode(ids[yylval.str]->data,ids[yylval.str]->n,ids[yylval.str]->m);
	map<string, matrix*>::iterator it;
	it = ids.find(id);
  	if (it == ids.end()){cout<<endl<<"Error: El id ["<<id<<"] no a sido definido"<<endl; return NULL;}	
	
	M->n=ids[id]->n;
	M->m=ids[id]->m;
	M->data=ids[id]->data;
	
	p->type=_matrix;
	p->M=M;
	p->lft=NULL;
	p->rgt=NULL;
	
	//show(*M);
	//printf("\nretorno nodo matriz\n");
	return p;
}

node *newnode(table t, int r, int c)
{	
	node *p=new node;
	
	matrix *M=new matrix;
	
	M->n=r;
	M->m=c;
	M->data=t;
	
	p->type=_matrix;
	p->M=M;
	p->lft=NULL;
	p->rgt=NULL;
	
	//show(*M);
	//printf("\nretorno nodo matriz\n");
	return p;
}

node *newnode(tnode t ,node *l,node *r)
{
	node *p=new node;
	
	p->type=t;	
	p->lft=l;
	p->rgt=r;
	if(evaluate(p)==NULL){printf("\nError: referencia nula a la matriz\n");return NULL;}
	p->M=evaluate(p);
	if(p->M==NULL){printf("\nError: referencia nula a la matriz\n");return NULL;}
	
	//show(*p->M);
	//printf("matriz del nodo\n");
	//show(*result);
	//printf("\nretorno nodo\n");
	return p;
}

void recorrer(node *p) //preorden
{
	printf("\n");
	
	if(!p) return;
	
	switch(p->type)
	{
		case _msuma:
			printf("suma\n");
			recorrer(p->lft);
			recorrer(p->rgt);
			break;
			
		case _mresta:
			printf("resta\n");
			recorrer(p->lft);
			recorrer(p->rgt);
			break;
			
		case _mmulti:
			printf("multi\n");
			recorrer(p->lft);
			recorrer(p->rgt);
			break;
						
		case _matrix:
			printf("matriz:\n");
			show(*p->M);
			break;
	}
}

void borrar(node *p) //postorden
{	
	if(!p) return;
	
	switch(p->type)
	{
		case _msuma:
			//printf("suma\n");
			borrar(p->lft);
			borrar(p->rgt);
			delete p;
			break;
			
		case _mresta:
			//printf("resta\n");
			borrar(p->lft);
			borrar(p->rgt);
			delete p;
			break;
			
		case _mmulti:
			//printf("multi\n");
			borrar(p->lft);
			borrar(p->rgt);
			delete p;
			break;
						
		case _matrix:
			//printf("matriz:\n");
			delete p->M;
			p->M=NULL;
			p=NULL;
			delete p;
			break;
	}
}

/*
node *newnode(tnode t,float x)
{
	node *p=new node;
	
	p->type=t;
	p->val=x;
	p->str="";
	p->lft=NULL;
	p->rgt=NULL;
	
	return p;
}

node *newnode(tnode t,char *str)
{
	node *p=new node;
	
	p->type=t;
	p->val=0.0;
	p->str=str;
	p->lft=NULL;
	p->rgt=NULL;
	
	return p;
}

node *newnode(tnode t,node *op)
{
	node *p=new node;
	
	p->type=t;
	p->val=0.0;
	p->str="";
	p->lft=NULL;
	p->rgt=op;
	
	return p;
}

node *newnode(tnode t,node *l,node *r)
{
	node *p=new node;
	
	p->type=t;
	p->val=0.0;
	p->str="";
	p->lft=l;
	p->rgt=r;
	
	return p;
}

float resolver(node *p)
{
	switch(p->type)
	{
		case _suma:
			return resolver(p->lft) + resolver(p->rgt);
			break;
			
		case _resta:
			return resolver(p->lft) - resolver(p->rgt);
			break;
			
		case _multi:
			return resolver(p->lft) * resolver(p->rgt);
			break;
			
		case _divi:
			return resolver(p->lft) / resolver(p->rgt);
			break;
			
		case _neg:
			return - resolver(p->rgt);
			break;
			
		case _num:
			return p->val;
			break;
			
		case _id:
			printf("id: ");
			printf("%s\n",p->str);
			break;
	}
}
//*/
