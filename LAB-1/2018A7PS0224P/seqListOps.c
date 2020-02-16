/***********file:   Ops.c *********/ // insert() and insertelements() methods have been modified for the assignment solution
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
    SeqList sl;
    sl.head = nextfreeloc++;
    sl.size = 0;
    st[sl.head].next = -1;
    return (sl);
}

void printJob(Job j)
{
    printf("JOB ID = %d, Priority = %d, Exec time = %d, Arrival time = %d \n", j.id, j.pri, j.et, j.at);
}

int inputJobs(JobList list)
{
    int i;
    int size;

    printf("\n Enter the Number of Jobs :");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        printf("\nEnter job ID");
        scanf("%d", &list[i].id);
        printf("Enter Priority (from 0 - 2)");
        scanf("%d", (int*)&list[i].pri);
        printf("Execution Time");
        scanf("%d", &list[i].et);
        printf("Arrival Time");
        scanf("%d", &list[i].at);
    }
    return size;
}
// modified function
SeqList insert(Job j, SeqList sl)
{
    int i, temp;
    for (i = sl.head; st[i].next != -1; i = st[i].next)
    {
        if (compare(j, st[st[i].next].ele) == LESSER)
            break;
    }
    int pos = st[i].next == -1 ? nextfreeloc : st[i].next; //pos stores the location where the new Job j has to be inserted

    for (int t = nextfreeloc - 1; t >= pos; t--) // shift all elements in store array which are greater than pos one position to the right and update their 'next' values accordingly
    {
        st[t].next = st[t].next == -1 ? -1 : st[t].next + 1;
        st[t + 1] = st[t];
    }

    nextfreeloc++; // nextfreeloc keeps track of number of jobs already inserted
    st[pos].next = st[i].next == -1 ? -1 : pos + 1;
    st[pos].ele = j;
    st[i].next = pos;
    sl.size++;
    return sl;
}
// modified function
void insertelements(JobList list, int size, SeqList s[])
{
    for (int i = 2; i >= 0; i--) //traverse joblist 3 times
    {
        for (int k = 0; k < size; k++)
        {
            Job j = list[k];
            if (j.pri == i)
            {
                s[i] = insert(j, s[i]); //insert pr2,pr1,pr0 jobs in that order
            }
        }
    }
}

void copy_sorted_ele(SeqList s[], JobList ele)
{
    int len = 0;
    for (int i = 2; i >= 0; i--)
    {
        Location k = st[s[i].head];
        while (k.next != -1)
        {
            k = st[k.next];
            ele[len++] = k.ele;
        }
    }
}

void printlist(SeqList sl)
{
    printf("size of list = %d\n", sl.size);
    for (int i = st[sl.head].next; i != -1; i = st[i].next)
    {
        printJob(st[i].ele);
    }
}

void printJobList(JobList list, int size)
{
    for (int i = 0; i < size; i++)
    {
        printJob(list[i]);
    }
}

void sortJobList(JobList list, int size)
{
    SeqList seq[3];
    seq[0] = createlist();
    seq[1] = createlist();
    seq[2] = createlist();
    insertelements(list, size, seq);
    printlist(seq[0]);
    printlist(seq[1]);
    printlist(seq[2]);
    copy_sorted_ele(seq, list);
}
