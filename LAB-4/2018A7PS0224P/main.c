#include "cycle.h"
#include "helper.h"
#include <sys/time.h>
#include<stdlib.h>

int main()
{
    srand(time(0));
    struct timeval t1, t2;
    double execTime;

    for (int i = 0; i < 5; i++) // run for 5 different sizes of linked list
    {
        gettimeofday(&t1, NULL);

        int N = generate_random(1000000, 2000000); // generates random integer between 10e6 and 2 * 10e6
        List ls = createList(N);
        ls = createCycle(ls);
        Node *test = testCyclic(ls);
        if (test)
            printf("CYCLE : YES\n");
        else
            printf("CYCLE : NO\n");

        gettimeofday(&t2, NULL);

        execTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
        printf("Number of elements in list : %d\n", N);
        printf("Total memory allocated : %lu\n", total_memory_allocated);
        printf("Total time taken is %f ms.\n\n", execTime);

        myfree(ls.first);
    }
}