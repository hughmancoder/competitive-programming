#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

class CubeStickers {
public:
    string isPossible(vector<string> stickers) {
        map<string, int> mp;
        for (int i = 0; i < stickers.size(); i++) {
            mp[stickers[i]]++;
        }

        int n = mp.size();
        if (n >= 6) return "YES";

        if (n == 5) {
            int ones = 4;
            int twos = 1;
            map<string, int>::iterator it = mp.begin();
            while (it != mp.end()) {
                if (twos && it->second >= 2) {
                    mp.erase(it++);
                    twos--;
                } else if (ones && it->second >= 1) {
                    mp.erase(it++);
                    ones--;
                } else {
                    ++it;
                }
            }
        }

        if (n == 4) {
            int ones = 2;
            int twos = 2;
            map<string, int>::iterator it = mp.begin();
            while (it != mp.end()) {
                if (twos && it->second >= 2) {
                    mp.erase(it++);
                    twos--;
                }
                else if (ones && it->second >= 1) {
                    mp.erase(it++);
                    ones--;
                } 
                else {
                    ++it;
                }
            }
        }

        if (n == 3) {
            map<string, int>::iterator it = mp.begin();
            while (it != mp.end()) {
                if (it->second >= 2) {
                    mp.erase(it++);
                } else {
                    ++it;
                }
            }
        }

        return mp.empty() ? "YES" : "NO";
    }
};
