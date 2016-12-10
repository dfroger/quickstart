# How to manage exception in Cython

There are two problems to adress when mananging `CTRL-C` as Python
KeyboardInterrupt exception.


## Installation


Install dependencies:

    conda create -n demo -c conda-forge -c dfroger python=3.5 cython craftr cysignals

Build:

    make configure
    make

Clean with:

    make clean


## Delated exception


See file `delayed.pyx` and `main_delayed.py`.

If `CTRL-C` is pressed during `C` code execution, signal is ignored, and
`C` code is not stopped but continue running.

When Python code is reached, signal is managed, and trigger a Python
`KeyboardInterrupt` exception.

Solution: The signal can be managed in `C` code to trigger a Python exception
using [cysignals](http://cysignals.readthedocs.io), and its functions
`sig_check`, `sig_on`et `sig_off`.


## Lost exception


See file `lost.pyx` and `main_lost.py`.

if `CTRL-C` is pressed during `Python` code execution, signal is transform
into Python exception, which is raised.

However, if the function into which the exception is raised has no way to
indicate the exception to its caller, the exception is lost.

A warning message is issued:

    Exception ignored in: 'foo.foo' KeyboardInterrupt

Solution: Declare the function using a exception value, as describe in
Cython
[documentation](http://docs.cython.org/en/latest/src/reference/language_basics.html#error-and-exception-handling).
See files `benchmark.pdf` and `benchmark.ipynb`.
