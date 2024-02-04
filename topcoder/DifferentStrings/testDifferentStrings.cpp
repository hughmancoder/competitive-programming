#include <iostream>
#include <string>
#include "DifferentStrings.hpp"

void testDifferentStrings() {
    DifferentStrings ds;

    std::cout << "Test case 1: " << (ds.minimize("koder", "topcoder") == 1) << std::endl;
    std::cout << "Test case 2: " << (ds.minimize("hello", "xello") == 1) << std::endl;
    std::cout << "Test case 3: " << (ds.minimize("abc", "topabcoder") == 0) << std::endl;
    std::cout << "Test case 4: " << (ds.minimize("adaabc", "aababbc") == 2) << std::endl;
    std::cout << "Test case 5: " << (ds.minimize("giorgi", "igroig") == 6) << std::endl;
}
