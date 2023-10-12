#include <vector>
using namespace std;
class TimeTravellingCellar
{
public:
    int determineProfit(vector<int> profit, vector<int> decay)
    {
        int maxProfit = 0;
        int n = profit.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;

                maxProfit = max(maxProfit, profit[i] - decay[j]);
            }
        }
        return maxProfit;
    }
};