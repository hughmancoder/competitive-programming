#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class BridgeSort {
    map<char, int> cardValues;
public:
    BridgeSort() {
        cardValues['2'] = 2;
        cardValues['3'] = 3;
        cardValues['4'] = 4;
        cardValues['5'] = 5;
        cardValues['6'] = 6;
        cardValues['7'] = 7;
        cardValues['8'] = 8;
        cardValues['9'] = 9;
        cardValues['T'] = 10;
        cardValues['J'] = 11;
        cardValues['Q'] = 12;
        cardValues['K'] = 13;
        cardValues['A'] = 14;
        cardValues['C'] = 1;
        cardValues['D'] = 2;
        cardValues['H'] = 3;
        cardValues['S'] = 4;
    }

    /* returns true if hand1 is greater than hand2, false otherwise */
    bool isGreater(const string& hand1, const string& hand2) {
        if (cardValues[hand1[0]] > cardValues[hand2[0]]) {
            return true;
        }
        if (cardValues[hand1[0]] == cardValues[hand2[0]]) {
            if (cardValues[hand1[1]] > cardValues[hand2[1]]) {
                return true;
            }
        }
        return false;
    }

    string sortedHand(string hand) {
        vector<string> cards;

        for (int i = 0; i < hand.size(); i+=2) {
            cards.push_back(hand.substr(i, 2)); 
        }
        
        for (int i = 0; i < cards.size(); i++) {
            for (int j = 0; j < cards.size() - i - 1; j++) {
                if (isGreater(cards[j], cards[j+1])) {
                    swap(cards[j], cards[j+1]); 
                }
            }
        }

        string res = "";
        for (int i = 0; i < cards.size(); i++) {
            res += cards[i];
        }
        return res;
    }
};