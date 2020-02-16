#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

typedef struct Element
{
    char name[11];
    float cg;
} Element;

void merge(Element[], int, Element[], int, Element[]);
void mergeSortR(Element[], int l, int r);
void mergeSortI(Element[], int l, int r);