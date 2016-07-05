Install dependencies:

    conda create -n cygdb -c dfroger debug python=2.7 cython gdb

Build extension to debug and test:

    make ext
    make test

Debug extension:

    make debug

