#include <time.h>

void *myalloc(unsigned long num);
void myfree(void *ptr);
int generate_random(int low, int high);
int probability();
extern unsigned long total_memory_allocated;
