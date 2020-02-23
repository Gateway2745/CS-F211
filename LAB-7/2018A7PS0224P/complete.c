#include "employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <assert.h>

void read(FILE *f, Employee *records) // helper function to read data into file
{
    int i = 0;
    while (!feof(f))
    {
        Employee emp;
        fscanf(f, "%s %d ", emp.name, &emp.id);
        records[i++] = emp;
    }
}

void swap(Employee *a, Employee *b) // swap by reference
{
    Employee temp = *a;
    *a = *b;
    *b = temp;
}

double fabs(double x) // own implementation of float absolute to avoid unnecessary import of math.h
{
    if (x >= 0)
        return x;
    else
        return -x;
}

int partition(Employee *arr, int l, int r) // partition function needed for quicksort
{
    int i = l - 1;
    int j = l;
    for (; j <= r - 1; j++)
    {
        if (arr[j].id <= arr[r].id)
        {
            swap(&arr[j], &arr[++i]);
        }
    }
    swap(&arr[++i], &arr[r]);
    return i;
}

void quickSortI(Employee *arr, int l, int r, int S) // groups of S elements will be unsorted but always largest element in group i < smallest in group (i+1) i.e the S groups will be sorted
{                                                   // this function modifies original array
    int stack_size = r - l + 1;
    int top = -1;
    Parameter *stack = (Parameter *)malloc(sizeof(Parameter) * stack_size); // Parameter is a structure that stors the leftmost and rightmost indices of the array at each stage of partitioning the array

    Parameter p = {l, r};

    stack[++top] = p;

    while (top != -1)
    {
        int left = stack[top].l;
        int right = stack[top--].r;
        int m;
        if (right - left + 1 > S && right > left)
        {
            m = partition(arr, left, right);
            stack[++top] = (Parameter){left, m - 1};
            stack[++top] = (Parameter){m + 1, right};
        }
    }
}

void insertionSort(Employee *arr, int l, int r) // performs insertion sort. This function also modifies original array
{
    for (int i = 1; i <= r; i++)
    {
        Employee k = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].id > k.id)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[++j] = k;
    }
}

void hybridSort(Employee *arr, int l, int r, int cutoff) // a hybrid function which calls quick sort and insertion sort after a cutoff value
{
    quickSortI(arr, l, r, cutoff);
    insertionSort(arr, l, r);
}

Times testRun(Employee *arr, int size)
{
    clock_t t;
    double quickSortTime, insertionSortTime;

    Employee arr1[size], arr2[size]; // create duplicates so as to not modify original array

    for (int i = 0; i < size; i++) // copy original content into duplicate arrays
    {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
    }

    t = clock();
    quickSortI(arr1, 0, size - 1, 0); // call quicksort
    t = clock() - t;

    quickSortTime = ((double)t) / CLOCKS_PER_SEC * 1000;

    t = clock();
    insertionSort(arr2, 0, size - 1); // call insertion sort
    t = clock() - t;

    insertionSortTime = ((double)t) / CLOCKS_PER_SEC * 1000;

    Times sort_times = {quickSortTime, insertionSortTime}; // Times is a structure which stores sorting times for quick and insertion sort

    return sort_times;
}

int estimateCutoff(Employee *arr, int size)
{
    int min = 10 > size ? size : 10;
    int max = size < 10000 ? size : 10000;
    Times tt1 = testRun(arr, min);
    Times tt2 = testRun(arr, max);
    assert(tt1.ins <= tt1.qs && tt2.ins > tt2.qs && "arrays range not sufficient");
    Times tt;
    int mid;
    do
    {
        mid = (min + max) / 2;
        tt = testRun(arr, mid);
        if (tt.ins > tt.qs)
        {
            max = mid;
        }
        else
            min = mid;
    } while (fabs(tt.qs - tt.ins) > 10e-6); // if difference is less than 10^-6 consider the times to be equal

    return mid;
}

int main(int argc, char *argv[])
{
    FILE *data = fopen(argv[1], "r"); // to read input data
    if (!data)
    {
        printf("Please input source file with format <file size> e.g '10',100','1000' (no .txt extension)\n");
        exit(0);
    }

    FILE *op = fopen(argv[2], "w"); // to store sorted input
    if (!op)
    {
        printf("Please mention valid output file as 2nd argument!\n");
        exit(0);
    }

    FILE *sorting_time = fopen("SORTING-TIME.txt", "a"); // stores the sorting time of hybrid sort

    int size = atoi(argv[1]); // get input size from input file name

    Employee *records = (Employee *)malloc(size * sizeof(Employee));

    read(data, records);

    int cutoff = estimateCutoff(records, size);

    clock_t t;
    double hybridSortTime;

    t = clock();
    hybridSort(records, 0, size - 1, cutoff);
    t = clock() - t;

    hybridSortTime = ((double)t) / CLOCKS_PER_SEC * 1000;
    fprintf(sorting_time, "N: %d , Hybrid Sorting Time: %f ms\n", size, hybridSortTime);
    printf("Hybrid Sort Time is : %lf ms\n", hybridSortTime);

    for (int i = 0; i < size; i++)
    {
        fprintf(op, "%s %d\n", records[i].name, records[i].id);
    }

    fclose(data);
    fclose(op);
    fclose(sorting_time);
}