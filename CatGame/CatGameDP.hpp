#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <climits>

using namespace std;

class CatGame {
private:
    int X;
    vector<int> coordinates;
    pair<int, int> dp[2][101][101];  // Use a 2D array for memoization
    map<int, int> indexes;

public:

    pair<int, int> getBounds(pair<int, int> bounds, int i) {
        if (i >= coordinates.size()) {
            return bounds;
        }

        int x = indexes[bounds.first];
        int y = indexes[bounds.second];

        if (dp[i % 2][x][y] != make_pair(-1, -1) && x >= 0 && x <= 100 && y >= 0 && y <= 100) {
            return dp[i % 2][x][y];
        }

        int lower_bounds = coordinates[i] - X;
        int upper_bounds = coordinates[i] + X;

        // Choose lower bounds
        pair<int, int> p1 = getBounds({min(bounds.first, lower_bounds), max(bounds.second, lower_bounds)}, i + 1);

        // Choose upper bounds
        pair<int, int> p2 = getBounds({min(bounds.first, upper_bounds), max(bounds.second, upper_bounds)}, i + 1);

        int dif1 = abs(p1.second - p1.first);
        int dif2 = abs(p2.second - p2.first);

        pair<int, int> res = (dif1 <= dif2) ? p1 : p2;

        x = indexes[res.first];
        y = indexes[res.second];

        if (x >= 0 && x <= 100 && y >= 0 && y <= 100) {
            dp[i % 2][x][y] = res;
        }

        return res;
    }

    int getNumber(vector<int> coordinates, int X) {
        this->X = X;
        this->coordinates = coordinates;

        vector<int> states;
        for (int i = 0; i < coordinates.size(); ++i) {
            int lower_bounds = coordinates[i] - X;
            int upper_bounds = coordinates[i] + X;
            states.push_back(lower_bounds);
            states.push_back(upper_bounds);
        }

        // Initialize the index map for memoization
        for (int i = 0; i < states.size(); ++i) {
            indexes[states[i]] = i;
        }

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 101; ++j) {
                for (int k = 0; k < 101; ++k) {
                    dp[i][j][k] = make_pair(-1, -1);
                }
            }
        }

        pair<int, int> res = getBounds({INT_MAX, INT_MIN}, 0);

        return abs(res.second - res.first);
    }
};
