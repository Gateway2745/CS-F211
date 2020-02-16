#include "linkedlist.h"
#include "Stack.h"

// inserts element on top of the stack
void push(struct linkedList* head, int data)
{	
	insertFirst(head,data);
}

// pops element at top of stack
struct node* pop(struct linkedList *head)
{
	return deleteFirst(head);
}