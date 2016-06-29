Install dependencies:

    conda create -n cython-demo python=3.5 cython nose coverage
    source activate cython-demo

Build:

    make ext

Test:

    make test

Analyse test coverge:

    make cover
