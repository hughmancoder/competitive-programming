#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	vector<int> plat(n);
	for (auto& p : plat) { cin >> p; }

	// in order to find the longest dank walk we need to know 2 pieces of
	// information for each platform:
	// 1. what's the longest dank walk starting from this position?
	// - minimum score of reachable platforms to the right + 1
	// - or 1 if none
	// 2. is it actually valid to start a walk from this position?
	// - are there platforms to the left that could reach this?

	vector<int> dankness(n, INT_MAX);
	vector<bool> isdank(n, true);
	for (auto i{n-1}; i >= 0; --i) {
		int dank{INT_MAX};
		int sofar{INT_MAX};
		for (auto j{i+1}; j < n; ++j) {
			if (plat[j] > plat[i] && plat[j] <= sofar) {
				dank = min(dank, dankness[j]);
				sofar = plat[j];
			}
		}
		dankness[i] = (dank != INT_MAX ? dank + 1 : 1);
		for (auto k{i-1}; k >= 0; --k) {
			if (plat[k] < plat[i]) {
				isdank[i] = false;
				break;
			}
		}
	}

	int best{INT_MAX};
	for (int i{0}; i < n; ++i) {
		best = (isdank[i] ? min(dankness[i], best) : best);
	}
	cout << best << "\n";

	return 0;
}
