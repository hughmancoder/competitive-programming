#include <string>
#include <vector>
using namespace std;
class AlternateColors
{
public:
    string getColor(long r, long g, long b, long k)
    {
        double minColour = min(min(r, g), b);
        // cout << "minColour" << minColour << endl;
        if (minColour * 3 >= k)
        {
            int index = k % 3;
            if (index == 1)
                return "RED";
            if (index == 2)
                return "GREEN";
            return "BLUE";
        }

        // subtract min count
        k -= 3 * minColour;
        r -= minColour;
        g -= minColour;
        b -= minColour;

        if (b == 0)
        {
            minColour = min(r, g);
            if (r == g || (minColour * 2 >= k))
                return k % 2 == 1 ? "RED" : "GREEN";
            return r > g ? "RED" : "GREEN";
        }
        if (g == 0)
        {
            minColour = min(r, b);
            if (r == b || (minColour * 2 >= k))
                return k % 2 == 1 ? "RED" : "BLUE";
            return r > b ? "RED" : "BLUE";
        }
        minColour = min(g, b);
        if (g == b || (minColour * 2 >= k))
            return k % 2 == 1 ? "GREEN" : "BLUE";
        return g > b ? "GREEN" : "BLUE";
    }
};
