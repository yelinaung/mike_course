#include "my_math.h"

void Add(vec* output, const vec* input) {
    output->x = output->x + input->x;
    output->y = output->y + input->y;
}
