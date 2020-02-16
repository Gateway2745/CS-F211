typedef struct Element
{
    int data;
    struct Element *next;
} Element;

typedef struct Queue
{
    Element *head;
    Element *tail;
} Queue;

Queue newQ();
int isEmptyQ(Queue q);
Queue delQ(Queue q);
Element front(Queue q);
Queue addQ(Queue q, Element e);
int lengthQ(Queue q);