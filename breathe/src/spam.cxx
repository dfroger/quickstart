#include "spam/spam.hxx"

namespace Spam {
    int foo(int a, int b)
    {
        return a+b;
    }

    Hello::Hello(std::string name):
        m_name(name)
    {
    }

    void Hello::greet()
    {
        std::cout << "Hello " << m_name << std::endl;
    }

}

void bar()
{
}

