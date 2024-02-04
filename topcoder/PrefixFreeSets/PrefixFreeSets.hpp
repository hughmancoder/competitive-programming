#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class PrefixFreeSets {
public:
    int maxElements(vector<string> words) {
        // sort alphabetically
        sort(words.begin(), words.end());
        
        int count = 0;
        
        for (int i = 0; i < words.size(); i++) {
            bool isPrefix = false;
            
            if (i + 1 < words.size()) {
                // check if previous lexiographic word is a prefix
                if (words[i + 1].substr(0, words[i].size()) == words[i]) {
                    isPrefix = true;
                }
            }
            
            if (!isPrefix) {
                count++;
            }
        }
        
        return count;
    }
};


