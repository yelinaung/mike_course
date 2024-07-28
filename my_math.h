#ifndef MYMATH_H
#define MYMATH_H
typedef struct vector {
	float x;
	float y;
} vec;

// function declaration only
// the ability to add two vectors
void Add(vec* output, const vec* input);
#endif
