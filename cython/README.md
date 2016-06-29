Install dependencies
====================

    conda create -n cython-demo python=3.5 cython nose coverage
    source activate cython-demo

Build
=====

    make ext

Test
====

    make test

Test coverge
============

    make cover

Test coverge results
====================

		.
		Name                Stmts   Miss  Cover
		---------------------------------------
		demo.py                 2      0   100%
		demo/foo.py             2      0   100%
		demo/foo/pyfoo.py      10      2    80%
		---------------------------------------
		TOTAL                  14      2    86%
		----------------------------------------------------------------------
		Ran 2 tests in 0.071s

		OK

Issue
=====

I would expect `foo.pyx` and `pyfoo.py` test coverage analysis to be the same.

What's wrong?
