%module demo

%{
#define SWIG_FILE_WITH_INIT
#include "a.hpp"
%}

%include "std_vector.i"

namespace std {
    %template(vector_int) vector<int>; 
}

%include "a.hpp"
