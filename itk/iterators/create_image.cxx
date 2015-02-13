#include <stdlib.h>

float* create_image(size_t s)
{
    return (float*) malloc(sizeof(float) * s);
}

