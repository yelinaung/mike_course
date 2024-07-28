#include <stdio.h>
#include <stdlib.h>
// Stak and Heap Memory
// +---------------------------+
// |        Memory             |
// |  +---------------------+  |
// |  |       Stack         |  |
// |  | +----------------+  |  |
// |  | | Local Var 3    |  |  |
// |  | +----------------+  |  |
// |  | | Local Var 2    |  |  |
// |  | +----------------+  |  |
// |  | | Local Var 1    |  |  |
// |  | +----------------+  |  |
// |  | | Function Params|  |  |
// |  | +----------------+  |  |
// |  | | Return Address |  |  |
// |  | +----------------+  |  |
// |  |        ...          |  |
// |  |                     |  |
// |  |    Stack Pointer    |  |
// |  |         |           |  |
// |  |         v           |  |
// |  +---------------------+  |
// |            |              |
// |            |              |
// |            v              |
// |  +---------------------+  |
// |  |        Heap         |  |
// |  |                     |  |
// |  | +----------------+  |  |
// |  | |  Dynamic Obj 1 |  |  |
// |  | +----------------+  |  |
// |  | +----------------+  |  |
// |  | |  Dynamic Obj 2 |  |  |
// |  | +----------------+  |  |
// |  | +----------------+  |  |
// |  | |  Dynamic Obj 3 |  |  |
// |  | +----------------+  |  |
// |  |        ...          |  |
// |  +---------------------+  |
// +---------------------------+
void foo()
{
    // local variable
    // only available in this scope
    // memory is automatically reclaimed within the bloc
    // in which it was initialized
    //
    // int a = 4;
}

int* allocateOnHeap(int size)
{
    int* array = (int*)malloc(sizeof(int) * size);
    printf("heap memory - array\t%p\n", array);
    printf("stack memory - array\t%p\n", &array);
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }
    return array;
}

int main()
{
    for (int i = 0; i < 100000; i++) {
        foo();
    }
    // int x = 4; // local variable
    printf("Day 3!\n");

    // malloc returns void* - a void pointer
    int* array = (int*)malloc(sizeof(int) * 10000);
    printf("array %p\n", array);
    free(array);

    // we are allocating memory in another function
    int size = 100;
    int* allocated = allocateOnHeap(size);
    printf("heap memory - allocated\t%p\n", array);
    printf("stack memory - allocated\t%p\n", &allocated);
    // accession from another function!
    for (int i = 0; i < 10; i++) {
        printf("heapData [%d]=%d\n", i, allocated[i]);
    }
    free(allocated);
    return 0;
}
