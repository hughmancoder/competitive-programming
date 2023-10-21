#include "BlockEnemy.hpp"
#include <string>
#include <vector>

using namespace std;

void testBlockEnemy() {
  BlockEnemy be;
  vector<string> roads1 = {"1 0 1", "1 2 2", "0 3 3", "4 0 4"};
  vector<int> occupiedTowns1 = {3, 2, 4};
  cout << (be.minEffort(5, roads1, occupiedTowns1) == 4) << endl;

  vector<string> roads2 = {"1 0 1", "1 2 2", "0 3 3", "4 0 4"};
  vector<int> occupiedTowns2 = {3};
  cout << (be.minEffort(5, roads2, occupiedTowns2) == 0) << endl;

  vector<string> roads3 = {"0 1 3", "2 0 5",  "1 3 1",  "1 4 8",
                           "1 5 4", "2 6 2",  "4 7 11", "4 8 10",
                           "6 9 7", "6 10 9", "6 11 6"};
  vector<int> occupiedTowns3 = {1, 2, 6, 8};
  cout << (be.minEffort(12, roads3, occupiedTowns3) == 13) << endl;

  vector<string> roads4 = {"0 1 3", "2 0 5",  "1 3 1",  "1 4 8",
                           "1 5 4", "2 6 2",  "4 7 11", "4 8 10",
                           "6 9 7", "6 10 9", "6 11 6"};
  vector<int> occupiedTowns4 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  cout << (be.minEffort(12, roads4, occupiedTowns4) == 66) << endl;
}