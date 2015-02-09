Install ITK and CMake:

    conda create -c https://conda.binstar.org/dfroger -n itk cmake itk
    source activate itk
    hash -r

Build benchmark:

    mkdir build; cd build
    cmake -DCMAKE_PREFIX_PATH=$(conda info -e | grep '*' | tr -s ' ' | cut -d" " -f3) ..
    make

Run and plot benchmark:

    bash ../run.sh
    python ../plot.py

![](https://raw.github.com/dfroger/quickstart/master/itk/iterators/times.png)
