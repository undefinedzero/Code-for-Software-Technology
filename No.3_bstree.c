#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define null 0
#define n 100

typedef int keytype;

typedef struct node
{
	keytype key;//�������������Ĺؼ�����
	struct node *lchild;
	struct node  *rchild;
}bstnode; //�������������ṹ

typedef bstnode *bstree;//�������������Ͷ���



void insertbst(bstree *tptr,keytype key)
{
	bstree a;
	a = (bstree)malloc(sizeof(bstnode));
	a -> key = key;
	a -> lchild = NULL;
	a -> rchild = NULL;

	if(((*tptr)->lchild)!=NULL && ((*tptr)->rchild)!= NULL){
		if(((*tptr)->key) < key)
			insertbst(&(*tptr)->rchild, key);
		else if(((*tptr)->key) > key)
			insertbst(&(*tptr)->lchild, key);
		else
			insertbst(&(*tptr)->rchild, key);
	}
	else if(((*tptr)->lchild)==NULL && ((*tptr)->rchild)!= NULL){
		if(((*tptr)->key) > key)
			(*tptr)->lchild = a;
		else
			insertbst(&(*tptr)->rchild, key);
	}
	else if(((*tptr)->lchild)!=NULL && ((*tptr)->rchild)== NULL){
		if(((*tptr)->key) < key)
			(*tptr)->rchild = a;
		else
			insertbst(&(*tptr)->lchild, key);
	}
	else if(((*tptr)->lchild)==NULL && ((*tptr)->rchild)== NULL){
		if((*tptr)->key==-1)
			(*tptr) = a;
		else if((*tptr)->key>key)
			(*tptr)->lchild = a;
		else if((*tptr)->key<=key)
			(*tptr)->rchild = a;
	}
	//�ڶ���������tptr�У�����ֵΪkey�Ľ��
	
	
}//end of insertbst

bstree createbst(bstree *t)
{	
	int a[8] = {1,20,6,18,12,5,1,20};
	//����һ�ö���������t
	keytype key;
	int i,m;
	bstree b;
	bstree * c,* d;
	b = (bstree)malloc(sizeof(bstnode));
	b->key = -1;
	b->lchild = NULL;
	b->rchild = NULL;
	t=&b;

	//�������100�����ڵ��������ɶ���������
	m =rand()%100;
	printf("random source data:");
	for(i=1; i<=m; i++)
	{
			key=rand()%100;
			printf("%d ",key);
			insertbst(t,key);//���ؼ���key���뵽����������t��
	}
	printf("\n");
	return b;
}//end of createbst 

void inorder(bstree t)
{
	//�Զ���������t�����������
	if (t)
	{
		inorder(t->lchild);//�������������
		printf(" %d",t->key);//���ʸ����
		inorder(t->rchild);//�������������
	}//end of if 
}//end of inorder


int main()//������
{
	bstree t=null,q=null;
	
	srand( (unsigned)time( NULL ) );
	
	t = createbst(&t);//����һ�ö���������t
	printf("\nbst data:");
	
	inorder(t);//�������������t�������������
	printf("\n");
}

