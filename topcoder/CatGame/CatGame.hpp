
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <climits>

using namespace std;

class CatGame {
public:
    int getNumber(vector<int> coordinates, int X) {
        int n = coordinates.size();
        sort(coordinates.begin(), coordinates.end());
        int L = coordinates[0] + X, U = coordinates[n-1] - X;
    
        for (int i = 0; i < coordinates.size(); ++i) {
            int bb = coordinates[i] - X;
            int bt = coordinates[i] + X;
            int M = (U + L) / 2;
            if ((bt <= U && bt >= L) || (bb <= U && bb >= L)) {
                continue;
            } else {
                // choose min boundary
                if (abs(bb - M) < abs((bt - M))) {
                    U = max(bb, U);
                    L = min(bb, L);
                } else {
                    L = min(bt, L);
                    U = max(bt, U);
                }
            }
        }
        // cout << U << " " << L << endl;
        return abs(U-L);
    }
};