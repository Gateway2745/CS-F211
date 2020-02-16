#include "que.h"
typedef int Priority;

typedef struct MultiQ
{
    Queue *queue;
    int num;
} MultiQ;

typedef struct Task
{
    int TaskID;
    Priority p;
} Task;

MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq, Task t);
Task nextMQ(MultiQ mq);
MultiQ delNextMQ(MultiQ mq);
int isEmptyMQ(MultiQ mq);
int sizeMQ(MultiQ mq);
int sizeMQbyPriority(MultiQ mq, Priority p);
Queue getQueueFromMQ(MultiQ, Priority p);
