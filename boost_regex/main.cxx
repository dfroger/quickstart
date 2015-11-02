#include <iostream>
#include <string>

#include "boost/regex.hpp"

using namespace std;

main()
{
    string text = "foo_bar";

    boost::regex re(
      "(.*)"  // group 1
      "_"     // underscore
      "(.*)"  // group 2
    );

    boost::match_results<std::string::const_iterator> results;
    if ( boost::regex_search(text, results, re)) {
        cout << results[1] << endl;
        cout << results[2] << endl;
        return 0;
    } else {
        return 1;
    }
}
