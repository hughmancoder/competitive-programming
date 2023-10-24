
#include "KokoBananas/KokoBananas.hpp"
#include <iostream>
using namespace std;

int main() {
  // test program
  KokoBananas obj;

  cout << obj.lastHand({5, 8}, 2) << endl;
  cout << obj.lastHand({5, 8}, 4) << endl;
  cout << obj.lastHand({4, 9, 4}, 18) << endl;
}