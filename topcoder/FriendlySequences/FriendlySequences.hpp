#include <vector>
#include <set>
using namespace std;

class FriendlySequences
{
private:
    set<int> getDigitSet(int number)
    {
        set<int> set;
        while (number > 0)
        {
            set.insert(number % 10);
            number /= 10;
        }
        return set;
    }

    bool areSetsEqual(const set<int> &set1, const set<int> &set2)
    {
        if (set1.size() != set2.size())
        {
            return false;
        }

        for (int num : set1)
        {
            if (set2.find(num) == set2.end())
            {
                return false;
            }
        }

        return true;
    }

public:
    int count(vector<int> array)
    {
        int n = array.size();
        int res = 0;
        for (int l = 0; l < n; l++)
        {
            set<int> set = getDigitSet(array[l]);
            for (int r = l + 1; r < n; r++)
            {
                if (areSetsEqual(set, getDigitSet(array[r])))
                {
                    res++;
                }
                else
                {
                    break;
                }
            }
        }
        return res;
    }
};