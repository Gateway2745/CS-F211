#include "cycle.h"

Node *testCyclic(List ls)
{
    Node *p = ls.first;
    Node *q = ls.first;
    while (p && q && q->next)
    {
        p = p->next;
        q = q->next->next;
        if (p == q)
            return p;
    }
    return NULL;
}
