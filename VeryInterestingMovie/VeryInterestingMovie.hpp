#include <vector>
#include <string>
using namespace std;

class VeryInterestingMovie {
    public:
    	int maximumPupils (vector<string> seats) {
            int res = 0;
            for (int i = 0; i < seats.size(); i++) {
                int count = 0;
                for (int j = 0; j < seats[i].size(); j++) {
                    if (seats[i][j] == 'Y' && (seats[i][j-1] != 'S' || j == 0)) {
                        seats[i][j] = 'S';
                        count++;
                    }
                }
                res += count;
                
            }
            return res;
        }
};