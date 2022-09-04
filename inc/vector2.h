#pragma once
#include <math.h>

typedef struct vector2
{
    int x;
    int y;
} vector2;

double vector2_length(vector2 *v)
{
    return sqrt(pow(v->x, 2) + pow(v->y, 2));
}

void vector2_normalize(vector2 *v)
{
    v->x = v->x / abs(v->x);
    v->y = v->y / abs(v->y);
}

int vector2_dot(vector2 *a, vector2 *b)
{
    return (a->x * b->x) + (a->y * b->y);
}
