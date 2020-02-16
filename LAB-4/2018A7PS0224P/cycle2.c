#include "cycle.h"

Node *testCyclic(List ls) // if the linkedlist is cyclic (head remains same after reversing) it returns the head else returns NULL
{
    Node *current, *prev, *next;
    current = ls.first;
    prev = NULL;
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    if (ls.first == prev)
        return ls.first;
    return NULL;
}