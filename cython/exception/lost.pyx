import time

cdef int foo():
    n = 5
    for i in range(n):
        print('python 0: {}/{}'.format(i, n))
        time.sleep(1)

def main():
    foo()
    n = 5
    for i in range(n):
        print('python 1: {}/{}'.format(i, n))
        time.sleep(1)
