#include "credit-card.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

LL store_size = 0; // stores length of allocated array

Card *read(FILE *f)
{
    int initial = 10;
    Card *store = (Card *)malloc(initial * sizeof(Card));
    int realloc_times = 1;
    while (!feof(f))
    {
        Card c;
        fscanf(f, "\"%lld,%[^,],%[^,],%[^,],%[^\"]\" ", &c.num, c.bank_code, c.expiry, c.first, c.last);

        if (store_size >= initial)
        {
            store = (Card *)realloc(store, ++realloc_times * initial * sizeof(Card));
        }
        store[store_size++] = c;
    }

    return store;
}

void print(Card *c, LL size)
{
    for (LL i = 0; i < size; i++)
    {
        printf("%lld\n", c[i].num);
    }
}

LL min(LL a, LL b)
{
    return a > b ? b : a;
}