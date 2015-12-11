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

        const bool sb() const { return m_sb;};
        void set_sb(const bool sb) { m_sb = sb; };

    private:
        bool m_sb;
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

        const int si() const { return m_si; }
        void set_si(const int si) { m_si = si; m_gi = si*2; }

        const int gi() const { return m_gi; }

        const Bar& sbar() const { return m_sbar; }
        void set_sbar(const Bar& sbar) { m_sbar = sbar; }

        const Bar& gbar() const { return m_gbar; }

        const vector<int>& gv() const { return m_gv; }

    private:
        int m_si;
        int m_gi;
        Bar m_sbar;
        Bar m_gbar;
        vector<int> m_gv;
};

#endif
