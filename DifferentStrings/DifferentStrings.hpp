#include <string>
using namespace std;

class DifferentStrings {
    public:
        int minimize(string A, string B) {
            int min = 50;
            for (int i = 0; i <= B.length() - A.length(); i++) {
                int count = 0;
                for (int j = 0; j < A.length(); j++) {
                    if (A[j] != B[i + j]) {
                        count++;
                    }
                }
                if (count < min) {
                    min = count;
                }
            }
            return min;
        }
};