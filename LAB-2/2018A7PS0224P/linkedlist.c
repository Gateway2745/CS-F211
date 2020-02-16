#include "linkedlist.h"
#include <stdlib.h>

void insertFirst(struct linkedList *head, int ele)
{
	struct node *link = (struct node *)malloc(sizeof(struct node));
	link->element = ele;
	link->next = head->first;
	head->first = link;
	head->count++;
}

struct node *deleteFirst(struct linkedList *head)
{
	if (head->first)
	{
		struct node *temp = head->first->next;
		head->first = temp;
		head->count--;
		return temp;
	}
	return NULL;
}

void printList(struct linkedList *head)
{
	struct node *ptr = head->first;
	printf("\n[ ");
	while (ptr != NULL)
	{
		printf("%d, ", ptr->element);
		ptr = ptr->next;
	}
	printf(" ]\n");
}

int search(struct linkedList *head, int ele)
{
	struct node *temp = head->first;
	while (temp)
	{
		if (temp->element == ele)
			return 1;
		temp = temp->next;
	}
	return 0;
}

struct node *delete (struct linkedList *head, int ele)
{
	if (!head->first)
		return NULL;
	else if (head->first && head->first->element == ele)
	{
		struct node *temp = head->first;
		head->first = temp->next;
		return temp;
	}
	else
	{
		struct node *prev = head->first;
		struct node *temp = head->first->next;
		while (temp)
		{
			if (temp->element == ele)
			{
				struct node *p = temp->next;
				prev->next = p;
				return temp;
			}
			prev = temp;
			temp = temp->next;
		}
		return NULL;
	}
}
