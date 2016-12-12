Install dependencies:

    conda create -n demo -c conda-forge -c dfroger python=3.5 cython craftr

Build:

    CXX=gcc craftr export
    craftr build
