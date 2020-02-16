#include "merge.h"
#include "helper.h"

void read(FILE *f, Element *records)
{
    int i = 0;
    while (!feof(f))
    {
        Element ele;
        fscanf(f, "%[^,],%f ", ele.name, &ele.cg);
        records[i++] = ele;
    }
}

LL min(LL a, LL b)
{
    return a > b ? b : a;
}
