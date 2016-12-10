import time
from posix.unistd cimport sleep
from stdio cimport printf

cdef int foo():
    cdef:
        int i, n=5
    for i in range(5):
        printf("c: %d/%d\n", i, n)
        sleep(1)

def main():
    foo()
    n = 5
    for i in range(n):
        print('python: {}/{}'.format(i, n))
        time.sleep(1)
