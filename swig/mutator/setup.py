from distutils.core import setup, Extension

ext = Extension(
    '_demo',
    sources = ['demo.i',],
    swig_opts = ['-c++', '-builtin'],
)

setup(
    name = 'demo',
    ext_modules = [ext,],
    py_modules = ['demo',],
)
