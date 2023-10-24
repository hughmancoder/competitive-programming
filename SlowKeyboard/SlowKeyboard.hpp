#include <iostream>
#include <string>
using namespace std;

class SlowKeyboard {
public:
  int enterTime(string time) {
    int m = stoi(time.substr(0, 2)); // Parse string to int
    int s = stoi(time.substr(3, 2)); // Parse string to int
    int tm = 0;                      // Initialize tm
    while (true) {
      if (needTime(m, s) <= tm)
        return tm;
      tm++;        // increase time
      s++;         // increase seconds
      m += s / 60; // calculate minute overflow
      s %= 60;
      m %= 60;
    }
  }

  // format mmss = m1m2s1s2
  int needTime(int m, int s) {
    // all digits take a second to press
    int ret = 4;
    // m1 and m2 are different
    if (m % 10 != m / 10)
      ret += 2;
    // m2 and s1 are different
    if (s / 10 != m % 10)
      ret += 2;
    // s1 and s2 are different
    if (s % 10 != s / 10)
      ret += 2;
    return ret;
  }
};
