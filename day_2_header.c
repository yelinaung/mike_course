#include <stdio.h>
#include "my_math.h"

int main()
{
    printf("Day 2\n");

    vec first;
    first.x = 7.0;
    first.y = 8.0;
    vec second;
    second.x = 7.0;
    second.y = 8.0;
    Add(&first, &second);

    printf("result: first.x = %f\n", first.x);
    printf("result: first.y = %f\n", first.y);
    return 0;
}
