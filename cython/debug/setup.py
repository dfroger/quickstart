from setuptools import setup, Extension

from Cython.Build import cythonize

extensions = Extension('demo', sources=['demo.pyx'])

setup(
    name = 'demo',
    url = 'https://github.com/quickstart/cython/debug',
    description = 'Example of debugging Cython project',
    license = 'BSD',
    author = 'David Froger',
    author_email = 'david.froger@mailoo.org',
    ext_modules = cythonize(
        extensions,
        gdb_debug=True,
        #compiler_directives = {
            #'language_level': 3,
        #},
    ),
)
