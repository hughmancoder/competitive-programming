#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

class PaternityTest
{

public:
    vector<int> possibleFathers(string child, string mother, const vector<string> men)
    {

        vector<int> res;
        for (int i = 0; i < men.size(); i++)
        {
            string man = men[i];
            int matches = 0;
            bool parent = true;
            for (int j = 0; j < man.size(); j++)
            {
                if (child[j] == man[j])
                {
                    matches++;
                }
                else
                {
                    if (mother[j] != child[j])
                    {
                        parent = false;
                    }
                }
            }

            if (parent && matches >= child.length() / 2)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
