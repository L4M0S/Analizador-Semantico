#include"abstree.h"
#include<cstdlib>
#include<cstdio>

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

void recorrer(node *p) //preorden
{
	printf("\n");
	
	if(!p) return;
	
	switch(p->type)
	{
		case _suma:
			printf("suma\n");
			recorrer(p->lft);
			recorrer(p->rgt);
			break;
			
		case _resta:
			printf("resta\n");
			recorrer(p->lft);
			recorrer(p->rgt);
			break;
			
		case _multi:
			printf("multi\n");
			recorrer(p->lft);
			recorrer(p->rgt);
			break;
			
		case _divi:
			printf("divi\n");
			recorrer(p->lft);
			recorrer(p->rgt);
			break;
			
		case _neg:
			printf("neg\n");
			recorrer(p->rgt);
			break;
			
		case _num:
			printf("num: ");
			printf("%i\n",p->val);
			break;
			
		case _id:
			printf("id: ");
			printf("%s\n",p->str);
			break;
	}
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
