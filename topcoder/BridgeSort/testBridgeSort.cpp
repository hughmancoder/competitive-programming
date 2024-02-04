#include "BridgeSort.hpp"
#include <string>

void testBridgeSort() {
    BridgeSort bs;
    std::cout << "Test case 1: " << (bs.sortedHand("HAH2H3C4D5ST") == "C4D5H2H3HAST") << std::endl;
    std::cout << "Test case 2: " << (bs.sortedHand("H3SAHA") == "H3HASA") << std::endl;
}
