%module demo

%{
#define SWIG_FILE_WITH_INIT
#include "demo.hxx"
%}

%include "attribute.i"
%include "std_vector.i"

using namespace std;

%template(vector_int) vector<int>;

/* si:     Python property
 * si:     C++ getter
 * set_si: C++ setter */
%attribute(Foo, int,
    si,     
    si,     
    set_si);

/* gi:     Python property
 * gi:     C++ getter */
%attribute(Foo, int,
    gi,
    gi);

%attribute(Bar, bool,
    sb,
    sb,
    set_sb);

%attribute2(Foo, Bar,
    sbar,
    sbar,
    set_sbar);

%attribute2(Foo, Bar,     
    gbar,
    gbar);

%attribute2(Foo, vector<int>,
    gv,
    gv);

%include "mutator.hpp"
%include "demo.hxx"
