#include <algorithm>
#include <limits.h>
#include <iostream>
using namespace std;

class EggCartons
{
public:
    int minCartons(int n)
    {
        if (n % 8 == 0)
            return n / 8;
        if (n == 0)
            return 0;
        if (n < 0)
        {
            return -1;
        }
        int a = minCartons(n - 8);
        int b = minCartons(n - 6);
        if (a == -1 && b == -1)
            return -1;
        if (a == -1 || b == -1)
            return a == -1 ? b + 1 : a + 1;
        return min(a, b) + 1;
    }
};