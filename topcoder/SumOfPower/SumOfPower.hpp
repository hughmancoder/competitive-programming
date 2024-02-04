#include <iostream>
#include <vector>
using namespace std;

class SumOfPower {
public:
  int findSum(vector<int> array) {
    int n = array.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int subSum = 0;
        for (int k = i; k <= j; k++) {
          subSum += array[k];
        }
        sum += subSum;
      }
    }
    return sum;
  }
};