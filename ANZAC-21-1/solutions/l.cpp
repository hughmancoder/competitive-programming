#include <bits/stdc++.h>
using namespace std;

// Time Complexity O(9*n)
// Space Complexity O(n)

int main()
{
    int n;
    cin >> n;
    vector<int> d;
    for (int i = 0; i < 10; i++)
    {
        int val;
        cin >> val;
        d.push_back(val);
    }

    string final;
    int ret = INT_MIN;


    // since maximum size for sound is 9 ignore constant
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int val = 0;

        
        for (auto c : s)
        {
            val += d[c - '0'];
        }
        // get min
        if (ret < val)
        {
            ret = val;
            final = s;
        }
    }
    cout << final << endl;
    return 0;
}