#include "multiq.h"
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

MultiQ mq;

MultiQ loadData(FILE *f)
{
    while (!feof(f))
    {
        int task_id;
        Priority priority;
        fscanf(f, "%d,%d ", &task_id, &priority);
        Task t = {task_id, priority};
        mq = addMQ(mq, t);
    }
}

MultiQ testDel(int num)
{
    for (int i = 0; i < num; i++)
        delNextMQ(mq);
}

int main(int argc, char *argv[])
{
    struct timeval t1, t2;
    double loadTime, deletionTime;

    int num = 10;
    mq = createMQ(num);

    if (argc < 2) //if no input file is detected
    {
        printf("please enter input file!\n");
        exit(1);
    }

    FILE *fileptr = fopen(argv[1], "r");

    // start timer to calculate load time
    gettimeofday(&t1, NULL);

    loadData(fileptr);

    // stop timer when load has finished
    gettimeofday(&t2, NULL);

    // compute and print the load time in millisec
    loadTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
    printf("Total time to load data is %f ms.\n", loadTime);

    // start timer when deletion has started
    gettimeofday(&t1, NULL);

    testDel(5);

    // stop timer when required elements have been deleted
    gettimeofday(&t2, NULL);

    // compute and print the deletion time in millisec
    deletionTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
    printf("Total time for deletion is %f ms.\n", deletionTime);
}
