#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>

#define MaxLength 10

typedef struct LIST
{
	char name[MaxLength];
	int length;
	struct LIST *next;
}LIST;


void print_list(LIST *p) /* Print all the node of the list. */
{
	printf("name = %s length = %d\n", p->name, p->length);
	if(p->next!=NULL)
		print_list(p->next);
}


LIST * insert_node(LIST *head, char x[MaxLength], int k)
{
	int i = 0,count = 0;
	LIST *a,*p,*b;
	b=head;
	a = (LIST *)malloc(sizeof(LIST));
	for(i=1;;i++){
		if(head==NULL) break;
		head = head->next;
		count ++;
	}
	head = b;
	if(k==1){
		a->next = head;
		head = a;
	}

	else if(k>count){
		for(i=1;i<=count-1;i++){
			head = head->next;
		}
		head->next = a;
		head = b;
		a->next = NULL;
	}

	else{
		for(i=1;i<k-1;i++){
			head = head->next;
		}
		p = head;
		head = head->next;
		a->next = head;
		p->next = a;
		head = b;
	}

	strcpy(a->name, x);
	a->length = strlen(x);

	return(head);
}

LIST* delete_node(LIST *head, int i)
{
	int k = 0,count = 0;
	struct LIST *a,*b;
	a = head;
	for(k=1;;k++){
		if(head==NULL) break;
		head = head->next;
		count ++;
	}
	head = a;
	if(i==1){
		head = head->next;
		free(a);
	}
	else if(i==count){
		for(k=1;k<i-1;k++){
			head = head->next;
		}
		free(head ->next);
		head ->next = NULL;
		head = a;
	}
	else if(i>count){
		printf("Wrong!!!\n");
		return NULL;
	}
	else{
		for(k=1;k<=i;k++){
			head = head->next;
		}
		b = head;
		head = a;
		for(k=1;k<i-1;k++){
			head = head->next;
		}
		free(head->next);
		head->next = b;
		head = a;
	}
	return head;
}

main()
{
	int i, choice;
	char x[MaxLength], element, listname;
//	LIST a, b, c, l, *p, *head;



/*	head = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;
	p = head;
*/


	LIST *a, *b, *c, *p, *head;

	a = (LIST *)malloc(sizeof(LIST));
	strcpy(a->name, "Zhou");

	b = (LIST *)malloc(sizeof(LIST));
	strcpy(b->name, "Xing");

	c = (LIST *)malloc(sizeof(LIST));
	strcpy(c->name, "Chi");
    a->length = 4;
    b->length = 4;
    c->length = 3;

	head = a;
	a->next = b;
	b->next = c;
	c->next = NULL;
	p = head;


	printf("Welcome to use this programe!\nNow the exist list is:\n");
	print_list(p);

	printf("Please chose the function:\n1.Insert a node in the linklist.\n2.Delete a node in the link list.\n3.Print link list.\n4.Quit the programe.\n");

	scanf("%d", &choice);
	switch(choice)
	{
		case 4:{
					printf("Thanks to use!Good bye!");
					break;
			   }
		case 1:{
					printf("Input where the node you want to Insert:");
					scanf("%d", &i);

					printf("Input the node you want to Insert:");
					scanf(" %s", &x);

					head = insert_node(head, x, i);
					print_list(head);

					break;
				}
		case 2:{
					printf("Input where the node you want to Delete:");
					scanf("%d", &i);

					if((head = delete_node(head, i))!=NULL)
						print_list(head);
					break;
				}
		case 3:{
					print_list(head);

					break;

			   }
	}
}
