#include <string>
using namespace std;

class GoodHours {
    bool isGoodTime(int h, int m) {
            int d1 = h / 10;
            int d2 = h % 10;
            int d3 = m / 10;
            int d4 = m % 10;
            if (d1 * d2 * d3 == d4 || d1 * d2 == d3 * d4 || d1 == d2 * d3 * d4) {
                
                return true;
            }
            return false;
    }
public: 
    int howMany(string beforeTime, string afterTime) {
        int beforeHour = stoi(beforeTime.substr(0, 2));
        int beforeMinute = stoi(beforeTime.substr(3, 2));
        int afterHour = stoi(afterTime.substr(0, 2));
        int afterMinute = stoi(afterTime.substr(3, 2));
        int c = 0;
        int h = beforeHour;
        int m = beforeMinute;
        
        while (true) {
            
            if (isGoodTime(h, m)) {
                c++;
            }
            if (h == afterHour && m == afterMinute) {
                break;
            }

            m++;
            if (m == 60) {
                m = 0;
                h++;
                if (h == 24) {
                    h = 0;
                }
            }
            // std::cout << h << " " << m << std::endl;
            
        }
        return c;
    }
};