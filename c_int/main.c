#include <stdio.h>

#define PRINT_SIZE_OF(type) printf("%10s: %lu byte(s)\n", #type, sizeof(type));

int main()
{
    PRINT_SIZE_OF(char);
    PRINT_SIZE_OF(short);
    PRINT_SIZE_OF(int);
    PRINT_SIZE_OF(long);
    PRINT_SIZE_OF(long long);
}
