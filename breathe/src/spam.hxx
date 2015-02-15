#ifndef SPAM_HXX_INCLUDED
#define SPAM_HXX_INCLUDED

#include <string>
#include <iostream>

namespace Spam {
    int foo(int a, int b);

    class Hello
    {
        public:
            Hello(std::string name);
            void greet();
        private:
            std::string m_name;
    };
}

void bar();

#endif
