
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;	
};

struct node* push(struct node *head_ref, int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	
	new_node->data = data;
	new_node->prev = NULL;

	if(head_ref == NULL)
	{
		new_node->next = NULL;
	}
	else
	{
		new_node->next = head_ref;
	}
	return new_node;
}

void printList(struct node *start)
{
	if(start == NULL)
	{
		printf("\t List is empty \n");
		return;
	}
	while(start->next != NULL)
	{
		printf("data in the double linked list :- %d", start->data);
		start =  start->next;	
	}
}

int main(void)
{
	printf("\t\t***********************Double Linked List***************************\n\n");
	struct node *head = NULL;

	printList(head);
	head = push(head,4);
	printList(head);

	return 0;
}
