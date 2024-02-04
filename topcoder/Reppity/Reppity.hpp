#include <string>
using namespace std;

class Reppity
{
public:
    int longestRep(string input)
    {
        int n = input.size();
        int longest = 0;
        for (int i = 0; i < n; i++)
        {
            char startLetter = input[i];
            for (int j = i + 1; j < n; j++)
            {
                if (input[j] == input[i])
                {
                    // find length of longest substr
                    int cnt = 0;
                    while (i + cnt < j)
                    {
                        if (input[i + cnt] == input[j + cnt])
                        {
                            cnt++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    longest = max(longest, cnt);
                }
            }
        }
        return longest;
    }
};