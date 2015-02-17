A simple example of using [Breathe](https://breathe.readthedocs.org)
, which is a [Sphinx](http://sphinx-doc.org/) extension providing
a brigde with [Doxygen](www.doxygen.org).

Install sphinx and the breathe extension:

    conda create -n breathe sphinx pip
    source activate breathe
    hash -r
    pip install breathe

Generate XML Doxygen:

    mkdir doxyxml; cd doxyxml
    doxygen -g spam.config
    cp spam.config spam.config.orig
    ... edit spam.config ...
    doxygen spam.config

Build Sphinx documentation:

    mkdir doc; cd doc
    sphinx-quickstart
    cp conf.py conf.py.orig
    ... edit conf.py ...
    make html
