#include <string>
using namespace std;
class BlackAndWhiteSolitaire {
    public:
    int minimumTurns(string cardFront) {
        // let c1 and c2 denote the number of cards that need to be flipped for the two possible sequences respectively
        int c1 = 0, c2 = 0;
        for (int i = 0; i < cardFront.size(); i++) {
            if (i % 2 == 0) {
                if (cardFront[i] == 'B') {
                    c1++;
                } else {
                    c2++;
                }                           
            } else {
                if (cardFront[i] == 'W') {
                    c1++;
                } else {
                    c2++;
                }
            }
        }
        return min(c1, c2);
    }
};