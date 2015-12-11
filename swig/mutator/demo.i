%module demo

%{
#define SWIG_FILE_WITH_INIT
#include "demo.hxx"
%}

%include "attribute.i"

%attribute(Foo, int, si, si, set_si);
%attribute(Foo, int, gi, gi);

%attribute(Bar, bool, sb, sb, set_sb);
%attribute2(Foo, Bar, sbar, sbar, set_sbar);
%attribute2(Foo, Bar, gbar, gbar);

%include "mutator.hpp"
%include "demo.hxx"
