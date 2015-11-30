#include <iostream>

#include "greet.hxx"

using namespace std;

int main(int argc, char** argv)
{
    if (argc == 2)
        cout << greet(argv[1]) << endl;
    else
        cerr << "usage: " << argv[0] << " " << "NAME" << endl;
}

