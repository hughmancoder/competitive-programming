#include <vector>
#include <limits.h>
using namespace std;

class CircularLine {
    public:
    
int longestTravel(vector<int> t) {
    int n = t.size();
    vector<int> sum(n + 1, 0);
    int runningSum = 0;
    for (int i = 0; i < n; i++) {
        runningSum += t[i];
        sum[i + 1] = runningSum;
    }   
    int longestTravel = INT_MIN;
    int travelTime;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // travel time for j to i and i to j respectively
            travelTime = min(sum[j] - sum[i], runningSum - (sum[j] - sum[i]));
            longestTravel = max(travelTime, longestTravel);
        }
    }
    return longestTravel;
}
};