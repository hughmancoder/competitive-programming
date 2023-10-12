#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class SimpleDuplicateRemover
{
public:
    vector<int> process(vector<int> sequence)
    {
        vector<int> res;
        set<int> s;
        for (int i = sequence.size() - 1; i >= 0; i--)
        {
            if (s.find(sequence[i]) == s.end())
            {
                s.insert(sequence[i]);
                res.push_back(sequence[i]);
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};