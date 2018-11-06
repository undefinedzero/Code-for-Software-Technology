#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define null 0
#define n 100

typedef int keytype;

typedef struct node
{
	keytype key;//二叉排序树结点的关键字域
	struct node *lchild;
	struct node  *rchild;
}bstnode; //二叉排序树结点结构

typedef bstnode *bstree;//二叉排序树类型定义



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
	//在二叉排序树tptr中，插入值为key的结点
	
	
}//end of insertbst

bstree createbst(bstree *t)
{	
	int a[8] = {1,20,6,18,12,5,1,20};
	//创建一棵二叉排序树t
	keytype key;
	int i,m;
	bstree b;
	bstree * c,* d;
	b = (bstree)malloc(sizeof(bstnode));
	b->key = -1;
	b->lchild = NULL;
	b->rchild = NULL;
	t=&b;

	//随机输入100个以内的数据生成二叉排序树
	m =rand()%100;
	printf("random source data:");
	for(i=1; i<=m; i++)
	{
			key=rand()%100;
			printf("%d ",key);
			insertbst(t,key);//将关键字key插入到二叉排序树t中
	}
	printf("\n");
	return b;
}//end of createbst 

void inorder(bstree t)
{
	//对二叉排序树t进行中序遍历
	if (t)
	{
		inorder(t->lchild);//中序遍历左子树
		printf(" %d",t->key);//访问根结点
		inorder(t->rchild);//中序遍历右子树
	}//end of if 
}//end of inorder


int main()//主函数
{
	bstree t=null,q=null;
	
	srand( (unsigned)time( NULL ) );
	
	t = createbst(&t);//创建一棵二叉排序树t
	printf("\nbst data:");
	
	inorder(t);//输出二叉排序树t的中序遍历序列
	printf("\n");
}

