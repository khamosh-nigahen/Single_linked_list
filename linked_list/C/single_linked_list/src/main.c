
/*created a single linked list.
Coded all possible ways of inserting a node in singkle linked list.
Coded all possible ways to delete a node in a single linked list*/

#include "stdio.h"
#include "stdlib.h"

struct node
{
	int data;
	struct node *next;
};

void printList(struct node *n)
{
	while(NULL != n)
	{
		printf("data in the list :- %d \n", n->data);
		n = n->next;
	}
}

struct node*  insertNodeAtFirst(struct node *start, int data)
{
	struct node *new_head = NULL;
	new_head = (struct node *)malloc(sizeof(struct node));
	
	new_head->data = data;
	new_head->next = start;
	start = new_head;
	
	return start; 
}

void insertNodeAtMiddle(struct node *start, int node_data, int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	
	temp = start;
	while(temp->next->data != node_data)
	{
		temp = temp->next;
	}
	new_node->next = temp->next;
	temp->next = new_node;
	new_node->data = data;
}

void insertNodeAtEnd(struct node *start, int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));

	while(NULL != start->next)
	{
		start = start->next;
	}
	start->next = new_node;
	new_node->data = data;
	new_node->next = NULL;
}

void deleteNodeUsingKey(struct node *start, int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	struct node *prev = (struct node *)malloc(sizeof(struct node));
	temp = start;

	while(temp->next->data != key)
	{
		temp = temp->next;	
	}
	prev = temp;
	temp = temp->next;
	prev->next = temp->next;
	free(temp);		
}

void deleteNodeAtGivenPosition(struct node *start, int position)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	struct node *prev = (struct node *)malloc(sizeof(struct node));
	temp = start;
	int pos = 0;
	while(temp->next != NULL)
	{
		if(pos == position)
		{	
			break;
		}
		pos++;
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	free(temp);
}

void mem_free(struct node *start)
{
	struct node *temp = NULL;

	while(start->next !=NULL)
	{
		temp = start;
		start = start->next;
		free(temp);
	}
}

int main(void)
{
	printf("\t******************Single linked list*************************\n\n");
	struct node *head = NULL;
	struct node *second = NULL;
	struct node *third = NULL;
	
	head = (struct node*)malloc(sizeof(struct node));	
	second = (struct node*)malloc(sizeof(struct node));	
	third = (struct node*)malloc(sizeof(struct node));	

	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next= third;

	third->data = 3;
	third->next = NULL;

	printf("\tOriginal List :- \n");
	printList(head);
	printf("\n");

	head = insertNodeAtFirst(head, 0);
	printf("\tAfter inserting node at begining :- \n");
	printList(head);
	printf("\n");

	insertNodeAtMiddle(head,3,4);
	printf("\tAfter inserting node at middle :- \n");
	printList(head);
	printf("\n");

	insertNodeAtEnd(head,5);
	printf("\tAfter inserting node at end :- \n");
	printList(head);
	printf("\n");

	deleteNodeUsingKey(head,4);
	printf("\tDeleting a node with a key:- \n");
	printList(head);
	printf("\n");

	deleteNodeAtGivenPosition(head,4);
	printf("\tDeleting a node by giving position:- \n");
	printList(head);
	printf("\n");

	mem_free(head);
	printf("Memory Freed\n\n");
	printList(head);
	return 0;
} 
