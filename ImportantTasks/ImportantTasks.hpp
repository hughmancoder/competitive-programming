#include <vector>
#include <algorithm>
using namespace std;
class ImportantTasks
{
public:
    int maximalCost(vector<int> complexity, vector<int> computers)
    {
        sort(complexity.begin(), complexity.end(), greater<int>());
        sort(computers.begin(), computers.end(), greater<int>());

        int executed = 0;
        for (int i = 0; i < complexity.size(); i++)
        {
            for (int j = 0; j < computers.size(); j++)
            {
                if (computers[j] >= complexity[i])
                {
                    executed++;
                    computers.erase(computers.begin() + j);
                    break;
                }
            }
        }
        return executed;
    }
};
