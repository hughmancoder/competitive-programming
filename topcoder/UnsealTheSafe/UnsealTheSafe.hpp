#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class UnsealTheSafe
{
private:
    vector<vector<int>> neighbors = {{7}, {2, 4}, {1, 3, 5}, {2, 6}, {1, 5, 7}, {2, 4, 6, 8}, {3, 5, 9}, {4, 8, 0}, {5, 7, 9}, {6, 8}};
    long dp[10][31];

public:
    long countPasswords(int N)
    {

        for (int i = 0; i < 10; i++)
        {
            dp[i][1] = 1;
        }

        for (int i = 2; i <= N; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                dp[j][i] = 0;
                for (int k = 0; k < neighbors[j].size(); k++)
                {
                    dp[j][i] += dp[neighbors[j][k]][i - 1]; // add last neighbors
                }
            }
        }
        long ans = 0;
        for (int i = 0; i < 10; i++)
        {
            ans += dp[i][N];
        }
        return ans;
    }
};
