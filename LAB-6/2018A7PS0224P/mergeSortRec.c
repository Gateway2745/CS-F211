#include "merge.h"
#include "helper.h"
#include <limits.h>

LL bottom_stack = ULLONG_MAX;

void mergeSortR(Element e[], int l, int r)
{
    bottom_stack = min(bottom_stack, (LL)&r); // keeps track of the address of last element pushed onto the stack
    Element ls[r - l + 1];
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSortR(e, l, m);
        mergeSortR(e, m + 1, r);
        merge(e + l, m - l + 1, e + m + 1, r - m, ls);
        for (int i = 0; i < r - l + 1; i++)
        {
            e[l + i] = ls[i];
        }
    }
}

int main(int argc, char *argv[])
{
    FILE *stats = fopen("recursive.csv", "w");
    fprintf(stats, "input size,time,stack-space\n");

    for (int i = 1; i <= argc - 1; i++)
    {
        clock_t t;
        double sortTime;

        FILE *data = fopen(argv[i], "r");
        char *arr_size = strtok(argv[i], ".");
        int size = atoi(arr_size);

        Element *records = (Element *)malloc(size * sizeof(Element));

        read(data, records);

        t = clock();

        char flag; // dummy variable to keep track of address of top of stack (as physical address of stack segment decreases)
        LL top_stack = (LL)&flag;
        mergeSortR(records, 0, size);

        t = clock() - t;

        sortTime = ((double)t) / CLOCKS_PER_SEC * 1000;
        printf("N:%d\nRecursive sorting time is %f ms.\n",size, sortTime);
        printf("Stack space is %lld MB\n", (top_stack - bottom_stack)/1024);
        fprintf(stats, "%d,%f,%lld\n", size, sortTime, top_stack - bottom_stack);
        bottom_stack = ULLONG_MAX;
    }

    fclose(stats);
}