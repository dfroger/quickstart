%module demo

%{
#define SWIG_FILE_WITH_INIT
#include "a.hpp"
%}

%include "a.hpp"
