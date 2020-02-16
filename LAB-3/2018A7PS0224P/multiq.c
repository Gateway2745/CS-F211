#include "multiq.h"
#include <stdlib.h>

MultiQ createMQ(int num)
{
    MultiQ mq;
    mq.num = num;
    mq.queue = (Queue *)malloc((num + 1) * sizeof(Queue)); // priorities are from 1 to num
    for (int i = 1; i <= num; i++)
    {
        mq.queue[i] = newQ();
    }
    return mq;
}

MultiQ addMQ(MultiQ mq, Task t)
{
    Element ele = {t.TaskID, NULL};
    mq.queue[t.p] = addQ(mq.queue[t.p], ele);
    return mq;
}

Task nextMQ(MultiQ mq)
{
    int num = mq.num;
    Queue *temp = mq.queue + num - 1;
    while (!temp->head)
        temp--;
    Task t = {temp - mq.queue + 1, temp->head->data};
    return t;
}

MultiQ delNextMQ(MultiQ mq)
{
    int num = mq.num;
    Queue *temp = mq.queue + num;
    while (!temp->head)
        temp--;
    *temp = delQ(*temp);
    return mq;
}

int isEmptyMQ(MultiQ mq)
{
    int num = mq.num;
    while (--num)
        if (mq.queue[num].head)
            return 0;
    return 1;
}

int sizeMQ(MultiQ mq)
{
    int count = 0;
    for (int i = 1; i <= mq.num; i++)
    {
        count += lengthQ(mq.queue[i]);
    }
    return count;
}

int sizeMQbyPriority(MultiQ mq, Priority p)
{
    if (p > mq.num || p <= 0) // checks for invalid priority
        return 0;
    return lengthQ(mq.queue[p]);
}

Queue getQueueFromMQ(MultiQ mq, Priority p)
{
    if (p > mq.num || p <= 0) // checks for invalid priority
        return (Queue){NULL, NULL};
    return mq.queue[p];
}