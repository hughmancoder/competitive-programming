#include <bits/stdc++.h>
using namespace std;


// Time Complexity O(N) where N is the length of string B
// Space Complexity O(1) variables

int main()
{
    string a;
    int b;

    cin >> b >> a;

    int index = 0;

    // you itterate through each character of a
    // and checking if that value is greater or equal to the number you wish to insert
    // if it is greater you know that the input value should come after
    while (b <= a[index] - '0')
    {
        cout << a[index];
        index++;
    }
    // Once you have found the first value that is less than b, you insert b here
    cout << b;
    while (index < a.size())
    {
        cout << a[index];
        index++;
    }

    return 0;
}