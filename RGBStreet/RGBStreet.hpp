#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <limits.h>
using namespace std;

class RGBStreet
{

public:
    int estimateCost(vector<string> houses)
    {
        int n = houses.size();
        int dp[n][3]; // create dp table to store costs at a given state

        int r, g, b;
        stringstream ss(houses[0]);
        ss >> r >> g >> b;

        // update initial states
        dp[0][0] = r;
        dp[0][1] = g;
        dp[0][2] = b;

        for (int i = 1; i < n; i++)
        {
            stringstream ss(houses[i]);
            ss >> r >> g >> b;
            dp[i][0] = r + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = g + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = b + min(dp[i - 1][0], dp[i - 1][1]);
        }

        return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    }
};