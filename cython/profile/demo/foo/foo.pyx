# cython: linetrace=True
# distutils: define_macros=CYTHON_TRACE_NOGIL=1

cdef int foo(int a, int b, bint ten):
    if ten:
        return bar(a) + bar(b) + 10
    else:
        return bar(a) + bar(b)

cdef int bar(int a):
    return a + 1

cdef int bam(int a):
    return a**2

def baz(int a, int b, bint ten):
    return foo(a,b,ten) * 2
