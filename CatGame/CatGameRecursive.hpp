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

public:

    pair<int, int> getBounds(pair<int, int> bounds, int i) {
        if (i >= coordinates.size()) {
            return bounds;
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

        pair<int, int> res = getBounds({INT_MAX, INT_MIN}, 0);

        return abs(res.second - res.first);
    }
};
