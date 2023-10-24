#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Regattas {
public:
  int betResult(vector<string> regattas, string ticket) {
    unordered_map<char, char> regattaWinners;
    unordered_set<char> allBoats;
    unordered_set<char> selectedBoats;

    for (const auto &regatta : regattas) {
      regattaWinners[regatta[0]] = regatta[0];
      for (char boat : regatta) {
        allBoats.insert(boat);
      }
    }

    int correctPredictions = 0;

    for (char boat : ticket) {
      // If the boat does not race that day, the ticket is invalid
      if (allBoats.find(boat) == allBoats.end()) {
        return -1;
      }
      // If the boat is selected more than once, the ticket is invalid
      if (selectedBoats.find(boat) != selectedBoats.end()) {
        return -1;
      }
      // Otherwise, add this boat to the set of selected boats
      selectedBoats.insert(boat);

      // Check if this boat is a winner and increment the count if so
      if (regattaWinners.find(boat) != regattaWinners.end()) {
        correctPredictions++;
      }
    }

    return correctPredictions;
  }
};
