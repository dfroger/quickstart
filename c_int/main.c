#include <stdio.h>

// https://en.wikipedia.org/wiki/C_data_types
// http://stackoverflow.com/a/13604190
// http://en.cppreference.com/w/cpp/types/integer

#define PRINT_SIZE_OF(type) printf("%10s: %lu byte(s)\n", #type, sizeof(type));

#ifndef _GKLIB_H_
#ifdef COMPILER_MSC
#include <limits.h>
typedef __int32 int32_t;
typedef __int64 int64_t;
#else
#include <inttypes.h>
#endif
#endif

int main()
{
    PRINT_SIZE_OF(char);
    PRINT_SIZE_OF(short);
    PRINT_SIZE_OF(int);
    PRINT_SIZE_OF(unsigned long);
    PRINT_SIZE_OF(long);
    PRINT_SIZE_OF(long long);
    PRINT_SIZE_OF(int32_t);
    PRINT_SIZE_OF(int64_t);
}
