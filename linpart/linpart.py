import doctest

def linpart(nitems, nparts, ipart):
    """
    Partition nitems items into nparts partitions

    >>> nitems,nparts = 50, 4
    >>> for ipart in range(nparts):
    ...     first, last = linpart(nitems, nparts, ipart)
    ...     print("ipart = {}, first = {}, last = {} ({} items)"
    ...           .format(ipart, first, last, last+1-first))
    ipart = 0, first = 0, last = 12 (13 items)
    ipart = 1, first = 12, last = 25 (14 items)
    ipart = 2, first = 25, last = 37 (13 items)
    ipart = 3, first = 37, last = 50 (14 items)
    """
    first = (nitems *  ipart) // nparts
    last = (nitems * (ipart+1)) // nparts
    return first, last

if __name__ == '__main__':
    doctest.testmod()
