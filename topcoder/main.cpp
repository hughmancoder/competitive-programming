#include "CountryFlags/CountryFlags.hpp"
#include <iostream>
using namespace std;

int main() {
  // Create an instance of the CountryFlags class
  CountryFlags obj;

  // Example Cases
  cout << "Test 1: " << (obj.minStripes("10", {"0", "1 2", "1 2"}) == 3)
       << endl;
  cout << "Test 2: " << (obj.minStripes("100", {"0", "1", "2"}) == 6) << endl;
  // cout << "Test 3: "
  //      << (obj.minStripes("100000000000000000", {"0", "1"}) ==
  //          50000000000000000)
  //      << endl;
  // cout << "Test 4: "
  //      << (obj.minStripes("10000000000000000",
  //                         {"01", "01", "234", "234", "234"}) == 40)
  //      << endl;

  // Uncomment and test additional cases here
  cout << "Test 5: "
       << (obj.minStripes("10000000000000000",
                          {"0123456789", "013456789", "023456789", "0123456789",
                           "0123456789", "0123456789", "0123456789",
                           "0123456789", "0123456789", "0123456789"}) ==
           4999999999999996)
       << endl;
  cout << "Test 6: "
       << (obj.minStripes("5", {"0", "1", "2", "3", "4", "5"}) == 1) << endl;

  return 0;
}
