#include <bits/stdc++.h>
using namespace std;

// Time Complexity O(NlogN) where N is the number of inputed values
// Space Complextiy O(N) to store the inputed values

/*
    Conceptually this problem is a bit weird, but I understood it as given a value   9 , x ,x ,x ,x 3
    No matter what value the 'x's are, it doesnt affect the minimum difference begin 6, (9-3)
*/

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    // read in the values
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if (n == 1)
        {
            cout << 0 << endl;
            return 0;
        }
        nums.push_back(val);
    }

    // once sorted all the values are placed next to eachother
    // the minimum difference between two values is equal to the minimum difference between each value
    int mn = INT_MAX;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i++)
    {
        mn = min(mn, abs(nums[i + 1] - nums[i]));
    }

    cout << mn << endl;

    return 0;
}