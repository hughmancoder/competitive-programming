#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class KokoBananas {
public:
  int lastHand(vector<int> hands, int K) {
    int N = hands.size();
    int lastHandEaten = -1;

    while (K > 0) {
      int maxBananas = -1;
      for (int i = 0; i < N; ++i) {
        if (hands[i] > maxBananas) {
          maxBananas = hands[i];
          lastHandEaten = i;
        }
      }

      hands[lastHandEaten]--;
      K--;
    }

    return lastHandEaten;
  }
};