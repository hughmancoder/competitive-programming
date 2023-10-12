#include <unordered_map>
#include <string>
using namespace std;

class NumberSplit {
public:
    unordered_map<int, int> memo;

    int longestSequence(int start) {
        if (start < 10) {
            return 1;
        }

        if (memo.find(start) != memo.end()) {
            return memo[start];
        }

        int max_length = 1;
        string str_start = to_string(start);

        for (size_t i = 1; i < str_start.size(); ++i) {
            for (size_t j = i + 1; j <= str_start.size(); ++j) {
                int left = stoi(str_start.substr(0, i));
                int middle = stoi(str_start.substr(i, j - i));
                int right = j < str_start.size() ? stoi(str_start.substr(j)) : -1;

                int next_num = (right != -1) ? (left * middle * right) : (left * middle);

                int curr_length = 1 + longestSequence(next_num);
                max_length = max(max_length, curr_length);
            }
        }

        memo[start] = max_length;
        return max_length;
    }
};