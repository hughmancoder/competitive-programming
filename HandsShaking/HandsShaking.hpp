#include <iostream>
using namespace std;

class HandsShaking {
public:
    long countPerfect(int n) {
        n /= 2; // We want the nth Catalan number, but n is the number of businessmen, so divide by 2.
        vector<long> catalan(n + 1);
        catalan[0] = catalan[1] = 1;

        for (int i = 2; i <= n; i++) {
            catalan[i] = 0;
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }

        return catalan[n];
    }
};