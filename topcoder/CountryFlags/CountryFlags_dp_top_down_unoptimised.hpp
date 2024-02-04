#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class CountryFlags {
  vector<set<int>> graph;
  unordered_map<int, unordered_map<int, long>> dp; // DP table

public:
  long minStripes(string numFlags, vector<string> forbidden) {
    graph.clear();
    dp.clear(); // Clear DP table

    for (string forbiddenString : forbidden) {
      set<int> temp;
      stringstream ss(forbiddenString);
      int i;
      while (ss >> i) {
        temp.insert(i);
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
  long calculateCombinations(int colour, int stripes) {
    if (stripes <= 0) {
      return 1;
    }

    // If DP table has a value for this state, return it
    if (dp[colour].find(stripes) != dp[colour].end()) {
      return dp[colour][stripes];
    }

    long combinations = 0;
    for (int i = 0; i < graph.size(); i++) {
      // if colour is forbidden, skip it
      if (colour != -1 && graph[colour].find(i) != graph[colour].end()) {
        continue;
      }
      combinations += calculateCombinations(i, stripes - 1);
    }

    // Store the result in the DP table before returning
    dp[colour][stripes] = combinations;
    return combinations;
  }
};
