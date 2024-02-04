#include <vector>
#include <string>
using namespace std;

class CountExpressions {
public:
    int calcExpressions(int x, int y, int val) {
        int count = 0;
        string operators = "+-*";
        
        
        for (int i  = 0; i < 3; ++i) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    char op1 = operators[i];
                    char op2 = operators[j];
                    char op3 = operators[k];
        
                    int pos[6][4] = {
                        {x, x, y, y},
                        {x, y, x, y},
                        {x, y, y, x},
                        {y, x, x, y},
                        {y, x, y, x},
                        {y, y, x, x}
                    };
                    
        
                    for (int i = 0; i < 6; ++i) {
                        int a = pos[i][0];
                        int b = pos[i][1];
                        int c = pos[i][2];
                        int d = pos[i][3];
                        
        
                        int res = a;
                        if (op1 == '+') res += b;
                        else if (op1 == '-') res -= b;
                        else res *= b;
                        
                        if (op2 == '+') res += c;
                        else if (op2 == '-') res -= c;
                        else res *= c;
                        
                        if (op3 == '+') res += d;
                        else if (op3 == '-') res -= d;
                        else res *= d;
                        
        
                        if (res == val) {
                            ++count;
                        }
                    }
                }
            }
        }
        
        return count;
    }
};