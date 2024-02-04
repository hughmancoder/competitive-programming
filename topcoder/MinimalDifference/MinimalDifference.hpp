#include <cmath>
#include <climits>
class MinimalDifference {
    public:

        int getSum(int num) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        }

    	int findNumber(int A, int B, int C) {
            int minDiff = INT_MAX;
            int res = A;
            int target = getSum(C);

            for (int num = A; num <= B; num ++) {
                int diff = abs(target - getSum(num));
                if (diff == 0) {
                    return num;
                }
                if (diff < minDiff) {
                    minDiff = diff;
                    res = num;
                }
            }
            return res;
        }

};