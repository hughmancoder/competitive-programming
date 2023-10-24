#include <iostream>
#include <set>
#include <string>
using namespace std;

class HenrysKey {
public:
  int howMany(string S) {
    set<string> keys;
    int n = S.size() - 1;
    for (int i = 0; i < S.size(); ++i) {
      // remove key at index i
      string key = S.substr(0, i) + S.substr(i + 1, n - i);
      keys.insert(key);
    }
    return keys.size();
  }
};