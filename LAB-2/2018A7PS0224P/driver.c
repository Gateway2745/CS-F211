#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "Stack.h"

int main(int argc, char *argv[])
{
	// Create a file pointer and open the file read as command line argument.
	FILE *fileptr = fopen(argv[1], "r");
	// Declare a pointer to a linked list (head) and allocate memory to it.
	struct linkedList *head = (struct linkedList *)malloc(sizeof(struct linkedList));
	// In a loop read the file and insert elements into the linkedList.
	while (!feof(fileptr))
	{
		// read the next element and store into the temp variable.
		int temp;
		fscanf(fileptr, "%d ", &temp);
		// push elements into the stack
		push(head, temp);
	}
	// close the file pointer
	fclose(fileptr);
	printf("After pushing all elements into stack:\n");
	printList(head);
	while (head->count > 0)
	{
		pop(head); // pop element at top of stack while number of elements in stack is greater than zero
	}
	printf("\nAfter popping all elements in stack:\n");
	printList(head);
}
