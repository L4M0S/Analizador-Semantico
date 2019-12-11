#ifndef abstree_h
#define abstree_h

typedef enum{	_main,_stseq,_st,_assign,_throwing,_mexp,_mterm,_mfact,_mdef,_rowseq,_row,_exp,_term,_fact,
				_suma,_resta,_multi,_divi,_neg,_num,_id
			} tnode;

typedef struct snode
{
	tnode type;
	float val;
	char *str;
	snode *lft;
	snode *rgt;
}node;

node *newnode(tnode,float);
node *newnode(tnode,char *);
node *newnode(tnode,node *);
node *newnode(tnode,node *,node *);

void recorrer(node *);

float resolver(node *);


#endif

