#ifndef abstree_h
#define abstree_h

#include<map>
#include<string>

using namespace std;

typedef enum{	_main,_stseq,_st,_assign,_throwing,_mexp,_mterm,_mfact,_mdef,_rowseq,_row,_exp,_term,_fact,
				_suma,_resta,_multi,_divi,_neg,_num,_id,_msuma,_mresta,_mmulti,_matrix
			} tnode;
/*
typedef struct snode
{
	tnode type;
	float val;
	char *str;
	snode *lft;
	snode *rgt;
}node;
*/

typedef map<int,float>row;	//fila
typedef map<int,row> table;	//tabla

typedef struct
{
	int n=0,m=0;	//numero de filas y columnas
	table data;	//contenido de la matriz
}matrix;

typedef map<string, matrix*> idTable;

typedef struct x
{
	int type;	//tipo de nodo ('+','-','*','M')
	matrix *M;	//matriz asociada al nodo
	struct x *lft;	//puntero al sub-arbol izquierdo
	struct x *rgt;	//puntero al sub-arbol derecho
}node;

void show(matrix &);
matrix *add(matrix*, matrix*);
matrix *subs(matrix*, matrix*);
matrix *mult(matrix*, matrix*);
matrix *evaluate(node *);

node *newnode(string);
node *newnode(table,int,int);
node *newnode(tnode,node *,node *);


void recorrer(node *);
void borrar(node *);

float resolver(node *);

#endif

