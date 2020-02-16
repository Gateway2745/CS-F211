#include "helper.h"
#include <stdlib.h>

unsigned long total_memory_allocated = 0; // keeps track of total memory allocated

void *myalloc(unsigned long num)
{
    total_memory_allocated += num;
    int* ptr = (int*)malloc(num + 8); // first 8 bytes will store the amount of memory allocated
    *ptr = num;
    return (void*)(ptr + 2);
}

void myfree(void *ptr)
{
    int* newptr = (int*)ptr - 2;
    total_memory_allocated -= *newptr; // retrieve the contents of first 8 bytes which contains the amount of memory that was allocated during myalloc
    free((void*)newptr);
}

int generate_random(int low, int high) // generates a random number in the range [low, high]
{
    return (rand() % (high - low + 1)) + low;
}

int probability()   // randomly returns either 0 or 1
{
    double prob = (double)rand() / (double)RAND_MAX;
    if (prob >= 0.5)
        return 1;
    return 0;
}
