#include "que.h"
#include <stdlib.h>

Queue newQ()
{
    Queue queue;
    queue.head = queue.tail = NULL;
    return queue;
}

int isEmptyQ(Queue q)
{
    if (!q.head)
        return 1;
    return 0;
}

Queue delQ(Queue q)
{
    if (q.head)
    {
        Element* temp = q.head;
        q.head = q.head->next;
        free(temp);
        return q;
    }
    return q;
}

Element front(Queue q)
{
    return *q.head;
}

Queue addQ(Queue q, Element e)
{
    Element* new = (Element*) malloc(sizeof(Element));
    *new = e;
    if (!q.head)
    {
        q.head = q.tail = new;
        q.tail->next = NULL;
        return q;
    }
    q.tail->next = new;
    q.tail = new;
    q.tail->next = NULL;
    return q;
}

int lengthQ(Queue q)
{
    if (!q.head)
        return 0;
    int len = 0;
    Element *temp = q.head;
    while (temp)
    {
        ++len;
        temp = temp->next;
    }
    return len;
}
