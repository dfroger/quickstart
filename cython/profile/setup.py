from setuptools import setup, Extension

from Cython.Build import cythonize

extensions = Extension('demo.foo.foo',
                        sources=['demo/foo/foo.pyx'])

setup(
    name = 'demo',
    url = 'https://github.com/quickstart/cython',
    description = 'Example of Cython project',
    license = 'BSD',
    author = 'David Froger',
    author_email = 'david.froger@mailoo.org',
    packages = [
        'demo',
        'demo.foo',
    ],
    ext_modules = cythonize(
        extensions,
        compiler_directives = {
            #'boundscheck': False,
            #'cdivision': True,
            #'wraparound': False,
            #'initializedcheck': False,
            'language_level': 3,
        },
    ),
    #requires = ['numpy'],
    tests_require = ['nose', 'coverage'],
)
