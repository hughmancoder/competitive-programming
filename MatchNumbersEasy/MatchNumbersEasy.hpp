#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class MatchNumbersEasy {
public:

	string maxNumber(vector <int> matches, int n) {
		string nums[]={"0","1","2","3","4","5","6","7","8","9"};
		map<int,string> dp;
		int min=99999;
		dp[0]="";
		for(int i = 0 ; i<matches.size();i++)
		if(matches[i]<min)
		min=matches[i];
        // loop over all possible denominiations
		for(int i = 1 ; i<= n ;i++){
			string max="";
			if(i<min){
                // for each denomiation value store the max numerical value
				dp[i]=max;
				continue;
			}
            // populate possible value for each denomination
			for(int j = 0; j < matches.size(); j++) {
				// Initialize a temporary string for the current number combination
				string currentCombination = "";

				// Check if we have enough matches to form the number represented by 'j'
				if(i >= matches[j]) {
					// Construct the number using the current digit and the best number from the remaining matchsticks
					currentCombination = nums[j] + dp[i - matches[j]];

					// Sort the digits in descending order to form the largest possible number
					sort(currentCombination.rbegin(), currentCombination.rend());

					if(max == "") {
						// If 'max' is still uninitialized, set it to the current combination
						max = currentCombination;
					} 
					else if(max.size() == currentCombination.size()) {
						// If the lengths of 'max' and 'currentCombination' are the same, compare them lexicographically
						if(max.compare(currentCombination) < 0) {
							max = currentCombination;
						}
					} 
					else if(max.size() > currentCombination.size()) {
						// If 'max' is longer than 'currentCombination', prepend '0's to 'currentCombination' to make their lengths equal
						string paddedCurrentCombination(max.size() - currentCombination.size(), '0');
						paddedCurrentCombination += currentCombination;
						if(max.compare(paddedCurrentCombination) <= 0) {
							max = currentCombination;
						}
					} 
					else {
						// If 'currentCombination' is longer than 'max', prepend '0's to 'max' to make their lengths equal
						string paddedMax(currentCombination.size() - max.size(), '0');
						paddedMax += max;
						if(paddedMax.compare(currentCombination) <= 0) {
							max = currentCombination;
						}
					}
				}
			}
			// Update the best number for the current number of matchsticks
			dp[i] = max;
		}
		int count=0;
		for(int i = 0 ; i<dp[n].size() ;i++){
			if(dp[n][i]=='0')
			count++;
		}
		if(count==dp[n].size())
		return "0";
		else
		return dp[n];		
	}
};