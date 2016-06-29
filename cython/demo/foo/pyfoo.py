def foo(a, b, ten):
    if ten:
        return bar(a) + bar(b) + 10
    else:
        return bar(a) + bar(b)

def bar(a):
    return a + 1

def bam(a):
    return a**2

def baz(a, b, ten):
    return foo(a,b,ten) * 2
