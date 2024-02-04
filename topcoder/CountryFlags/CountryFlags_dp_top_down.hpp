#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class CountryFlags {
  vector<set<int>> graph;
  unordered_map<long long, long long> memo; // Memoization cache

public:
  long minStripes(string numFlags, vector<string> forbidden) {
    graph.clear();
    memo.clear(); // Clear memoization cache

    for (const string &forbiddenString : forbidden) {
      set<int> temp;
      for (size_t i = 0, j = 0; j < forbiddenString.size(); j++) {
        if (forbiddenString[j] == ' ' || j == forbiddenString.size() - 1) {
          temp.insert(stoi(forbiddenString.substr(i, j - i + 1)));
          i = j + 1;
        }
      }
      graph.push_back(temp);
    }

    int stripes = 0;
    long flags = stol(numFlags);
    while (flags > 0) {
      stripes++;
      flags -= calculateCombinations(-1, stripes);
    }
    return stripes;
  }

private:
  long long calculateCombinations(int colour, int stripes) {
    if (stripes == 0)
      return 1;

    long long key = (long long)colour << 32 | stripes; // Create a unique key
    if (memo.find(key) != memo.end())
      return memo[key]; // Return cached result if exists

    long long combinations = 0;
    for (int i = 0; i < graph.size(); i++) {
      if (colour != -1 && graph[colour].find(i) != graph[colour].end())
        continue;
      combinations += calculateCombinations(i, stripes - 1);
    }

    memo[key] = combinations;
    return combinations;
  }
};
