Install dependencies:

    conda create -n debuggee -c dfroger python=3.5 cython debug
    conda create -n debugger -c dfroger python=2.7 cython gdb

Get debugger path:

    source activate debugger
    DEBUGGER_PATH=$CONDA_PREFIX/bin

Build extension to debug and test:

    source activate debuggee
    make ext
    make test

Debug extension:

    $DEBUGGER_PATH/cygdb . -- --args python main.py
