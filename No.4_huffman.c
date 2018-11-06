#include <stdio.h>
#include <stdlib.h>

typedef struct huffman_node 
{
	int data;
	int lchild;
	int rchild;
	int parent;
}bnode;  //定义二叉链表结点结构

void Print(int i, bnode node[])
{
	if(node[i].parent == 26*2-2)
		printf("%d",node[i].data);
	else
	{
		Print(node[i].parent,node);
		printf("%d",node[i].data);
	}
}

void SelectIJ(int k, bnode node[], int *i, int *j)
{
	int b;
	int min1, min2;
	
	for(b=0;b<k;b++){
		if(node[b].parent == 0){
	 			min1 = b;
				break;
		}
	}
	for(b=0;b<k;b++){
		if(node[b].parent == 0){
			if(node[min1].data>=node[b].data)
				min1 = b;
		}
	}
	
	for(b=0;b<k;b++){
		if(node[b].parent == 0&& b != min1){
				min2 = b;
				break;
		}
	}
	for(b=0;b<k;b++){
		if(node[b].parent == 0 && b != min1){
			if(node[min2].data>=node[b].data)
				min2 = b;
		}
	}
	
	*i = min1;
	*j = min2;
}

void HuffmanTree(int n, bnode node[],int w[])
{
	int i,k,j;
	
	for(i=0;i<n;i++){
		node[i].data = w[i];
		node[i].lchild = node[i].rchild = 0;
	}
	
	for(i=0;i<2*n-1;i++){
		node[i].parent = 0;
	}
	
	for(k=n;k<2*n-1;k++){
		SelectIJ(k,node,&i,&j);
		node[k].data = node[i].data + node[j].data;
		node[k].lchild = i;
		node[i].data = 0;
		node[k].rchild = j;
		node[j].data = 1;
		node[i].parent = node[j].parent = k;
	}
	node[2*n-2].data = 0;
}

int main()
{
	FILE *fp;
	int weight[26];

	int i,j;
	int ch;
	int n;

	bnode *node;
	unsigned long code;

	for(i=0; i<26; i++)
	{
		weight[i] = 0;
	}

	if( (fp = fopen("StrayBirds.txt","r")) == NULL )
		return 0;

	do {
		ch = fgetc(fp);

		if (!( ((ch>=97)&&(ch<=122)) ||
			   ((ch>=65)&&(ch<=90 ))	 )
		   )
		{
			continue;
		}
		if( (ch>=97)&&(ch<=122) )
		{
			ch -= 32;
		}
        putchar(ch);
		weight[ch-65]++;
	} while(feof(fp)==0);

	printf("\n");

	n = 0;
	for(i=0; i<26; i++)
	{
		if(weight[i] > 0) 
		{
			n++;
			printf("%c  %d \n", i+65, weight[i]);
		}
	}

	node = (bnode *)malloc((2*26-1) * sizeof(bnode));

	//建立哈夫曼树
	HuffmanTree(26, node, weight);

	//哈夫曼编码
	for (i=0; i<26; i++)
	{
		printf("Now processing %c ----- ", i+65);
		Print(i,node);
		//printf("   %d",node[i].parent);
		printf("\n");
	}

	free(node);
	fclose(fp);
}