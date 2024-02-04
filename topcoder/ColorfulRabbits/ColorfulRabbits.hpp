#include <vector>
#include <unordered_map>
using namespace std;
class ColorfulRabbits {
    public:
    int getMinimum(vector<int> replies) {
        unordered_map<int, int> m;
        for (int i = 0; i < replies.size(); i++) {
            m[replies[i]]++;
        }
        int ans = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            int key = it->first;
            int value = it->second;
            if (key == 0) {
                ans += value;
            } else {
                int numGroups = value / (key + 1);
                ans += (key + 1) * numGroups;
                // add an extra group if we have remainders
                if (value % (key + 1) != 0) {
                    ans += key + 1;
                }
            }
        }
        return ans;
    }
};