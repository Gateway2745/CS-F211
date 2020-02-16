#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <limits.h>
#include "credit-card.h"

LL bottom_stack = ULLONG_MAX; // physical address of elements pushed onto the stack is in decreasing order

void insertInOrder(Card *store, Card c, LL pos)
{
    int j = pos - 1;
    while (j >= 0 && store[j].num > c.num)
    {
        store[j + 1] = store[j];
        j--;
    }
    j++;
    store[j] = c;
}

void insertionSort(Card *store, LL size)
{
    bottom_stack = min(bottom_stack, (LL)&size); // keeps track of the address of last element pushed onto the stack
    if (size == 0)
        return;
    insertionSort(store, size - 1);
    insertInOrder(store, store[size], size);
}

int main(int argc, char *argv[])
{
    clock_t t;
    double loadTime, sortTime;
    FILE *times = fopen("times.csv", "w"); // store data in csv format for easier visualization
    FILE *memory = fopen("memory.csv", "w");
    for (int i = 1; i <= argc - 1; i++)
    {
        printf("%s Records:\n", argv[i]);
        FILE *f = fopen(argv[i], "r");
        t = clock();
        Card *store = read(f);
        t = clock() - t;
        fclose(f);

        loadTime = ((double)t) / CLOCKS_PER_SEC * 1000;
        printf("Loading time taken is %f ms.\n", loadTime);

        char flag; // dummy variable to keep track of address of top of stack (as physical address of stack segment decreases)
        LL top_stack = (LL)&flag;
        t = clock();
        insertionSort(store, store_size - 1);
        t = clock() - t;

        sortTime = ((double)t) / CLOCKS_PER_SEC * 1000;
        printf("Sorting time is %f ms.\n", sortTime);

        fprintf(times, "%d,%f\n", atoi(argv[i]), sortTime);
        fprintf(memory, "%d,%lld \n", atoi(argv[i]), top_stack - bottom_stack);
        // printf("Stack space allocated is %lld bytes \n", top_stack - bottom_stack);
        top_stack = 0;
        store_size = 0;
        free(store);
    }

    fclose(times);
    fclose(memory);
    return 0;
}
