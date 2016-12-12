include "cysignals/signals.pxi"

import time
from posix.unistd cimport sleep
from stdio cimport printf

cdef int foo() except -1:
    cdef:
        int i, n=5
    for i in range(5):
        sig_on()
        printf("c: %d/%d\n", i, n)
        sleep(1)
        sig_off()

def main():
    foo()
    n = 5
    for i in range(n):
        print('python: {}/{}'.format(i, n))
        time.sleep(1)
