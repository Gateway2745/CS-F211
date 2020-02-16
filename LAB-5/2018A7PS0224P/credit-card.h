#include <stdio.h>

typedef unsigned long long int LL;

typedef struct Card
{
    LL num;
    char bank_code[6];
    char expiry[8];
    char first[6];
    char last[6];
} Card;

extern LL store_size;
Card *read(FILE *);
void print(Card *, LL);
LL min(LL, LL);