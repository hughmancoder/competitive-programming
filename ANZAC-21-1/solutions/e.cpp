#include <bits/stdc++.h>
using namespace std;

// Time Complexity O(N) One pass through the input string
// Space Complexity O(N) While you are creating a vector of string, the size of that is still equal to the original input string + 'X's

int main()
{
    string s;
    int k;
    cin >> s >> k;

    while (s.size() % k != 0)
    {
        s += 'X';
    }

    int val = s.size()/k;
    vector<string> ss;
    string temp;
    int counter = 0;

    // Split string s evenly into ss 
    for (auto i : s)
    {
        if (counter == val)
        {
            ss.push_back(temp);
            temp.clear();
            counter = 0;
        }
        temp.push_back(i);
        counter++;
    }
    ss.push_back(temp);

    for (int i = 0; i < ss[0].size(); i++)
    {
        for (int j = 0; j < ss.size(); j++)
        {
            cout << ss[j][i];
        }
    }

    return 0;
}