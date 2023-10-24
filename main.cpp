
#include "SumOfPower/SumOfPower.hpp"
#include <iostream>
using namespace std;

int main() {
  // test program
  SumOfPower sop;
  cout << sop.findSum({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) << endl;
  cout << sop.findSum({3, 14, 15, 92, 65}) << endl;
}