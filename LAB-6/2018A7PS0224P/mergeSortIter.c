#include "merge.h"
#include "helper.h"

void mergeSortI(Element e[], int l, int r)
{
    int n = r - l + 1;
    for (int i = 1; i < n; i *= 2)
    {
        int size = 2 * i; // size of array after merging ( individual arrays after division are of size i)
        for (int j = 0; j < n; j += size)
        {
            Element ls[size];

            int st1 = j; // start position of first array after division
            int st2 = st1 + i > n - 1 ? -1 : st1 + i; // start position of second array after division
            int s1 = st1 + i - 1 > n - 1 ? n - st1 : i; // size of first array 
            int s2 = st2 == -1 ? 0 : (st2 + i - 1 > n - 1 ? n - st2 : i); // size of second array 
            if (s2 > 0)
            {
                merge(e + st1, s1, e + st2, s2, ls);
                for (int k = st1; k < st1 + s1 + s2; k++)
                {
                    e[k] = ls[k - st1];
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    FILE *stats = fopen("iterative.csv", "w");
    fprintf(stats, "input size,time,heap-space\n");

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

        mergeSortI(records, 0, size);

        t = clock() - t;

        sortTime = ((double)t) / CLOCKS_PER_SEC * 1000;
        printf("N:%d\nIterative sorting time is %f ms.\n",size, sortTime);
        printf("Heap space allocated is %lu bytes.\n",size * sizeof(Element));
        fprintf(stats, "%d,%f,%lu\n", size, sortTime, size * sizeof(Element));
    }

    fclose(stats);
}