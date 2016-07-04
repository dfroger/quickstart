#include <stdio.h>

int main()
{
#ifdef DEBUG
    printf("Hello world in DEBUG mode!\n");
#else
    printf("Hello world!\n");
#endif
}
