cdef int c_foo(int a, int b):
    return a + b

def foo(a, b):
    return c_foo(a, b)
