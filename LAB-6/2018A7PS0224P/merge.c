#include "merge.h"

void merge(Element ls1[], int s1, Element ls2[], int s2, Element ls[])
{
    int i = 0, j = 0, k = 0;
    while (i < s1 && j < s2)
    {
        if (ls1[i].cg <= ls2[j].cg)
        {
            ls[k++] = ls1[i];
            i++;
        }
        else
        {
            ls[k++] = ls2[j];
            j++;
        }
    }
    while (i < s1)
    {
        ls[k++] = ls1[i];
        i++;
    }
    while (j < s2)
    {
        ls[k++] = ls2[j];
        j++;
    }
}


