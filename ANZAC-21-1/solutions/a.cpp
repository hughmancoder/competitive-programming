#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // all possible fib numbers
    int arr[6] = {1, 2, 3, 5, 8, 13};
    string ret = "";

    // checks to see if the number is a fib number
    for (int i = 1; i <= n; i++)
    {
        bool fizz = false;
        for (int j = 0; j < 6; j++)
        {
            if (i == arr[j])
                fizz = true;
        }
        cout << fizz << endl;
        if (fizz)
            ret += "fizz";
        else
            ret += "buzz";
    }
    cout << ret << endl;
    return 0;
}

    // Time complexity O(KN) where K is then number of precomputed fib numbers, and N is the input
    // Space Complexity O(K) Same K as above