#include <iostream>
#include <string>
#include "BigBurger.hpp"

void testBigBurger() {
    BigBurger bb;
    std::cout << "Test case 1: " << (bb.maxWait({3, 3, 9}, {2, 15, 14}) == 11) << std::endl;
    std::cout << "Test case 2: " << (bb.maxWait({182}, {11}) == 0) << std::endl;
    std::cout << "Test case 3: " << (bb.maxWait({2, 10, 11}, {3, 4, 3}) == 3) << std::endl;
    std::cout << "Test case 4: " << (bb.maxWait({2, 10, 12}, {15, 1, 15}) == 7) << std::endl;
}
