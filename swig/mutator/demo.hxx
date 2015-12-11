#ifndef DEMO_HXX_INCLUDED
#define DEMO_HXX_INCLUDED

#include <vector>
#include "mutator.hpp"

// todo:
//    - string

using namespace std;

class Bar
{
    public:
        Bar(bool sb):
            m_sb(sb)
        {};

    private:
        WITH_SETTER(bool, sb)
};

class Foo
{
    public:
        Foo(int si):
            m_si(si),
            m_gi(si*2),
            m_sbar(false),
            m_gbar(false)
        {
            m_gv.push_back(1);
            m_gv.push_back(2);
            m_gv.push_back(3);
        }

    private:
        WITH_SETTER(int, si)
        WITH_GETTER(int, gi)
        WITH_SETTER_REF(Bar, sbar)
        WITH_GETTER_REF(Bar, gbar)
        WITH_GETTER_REF(vector<int>, gv)
};

#endif
