#include "helper.h"
#include "cycle.h"

List createList(int n)
{
    List head;
    unsigned size = sizeof(Node);
    head.first = myalloc(size);
    head.num = n;
    head.first->data = generate_random(1, 100);
    head.first->next = NULL;
    Node *temp = head.first;
    for (int i = 2; i <= n; i++)
    {
        temp->next = myalloc(size);
        temp = temp->next;
        temp->next = NULL;
        temp->data = generate_random(1, 100);
    }
    FILE *f = fopen("heap_space.txt", "w"); // write total space allocated to 'heap-space.txt'
    fprintf(f, "%lu", total_memory_allocated);
    fclose(f);
    return head;
}

List createCycle(List ls)
{
    if (probability())
    {
        int pos = 1;
        int r = generate_random(1, ls.num);
        Node *last = ls.first;
        Node *mid = ls.first;
        while (last && last->next)
        {
            if (pos < r)
            {
                mid = mid->next;
                pos++;
            }
            last = last->next;
        }
        last->next = mid;
    }
    return ls;
}