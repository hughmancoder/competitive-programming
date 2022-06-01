#include <bits/stdc++.h>
using namespace std;

// Euclid's Algorithm
long long gcd(long long a, long long b) {
	if (b > a) { return gcd(b, a); }
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

// a's factors (including itself and 1) from smallest to largest
vector<long long> factors(long long a) {
	const long long sq{static_cast<long long>(sqrt(a))};
	vector<long long> res;
	vector<long long> comp;
	for (long long i{2}; i <= sq; ++i) {
		if ((a % i) == 0) {
			res.push_back(i);
			comp.push_back(a/i);
		}
	}
	res.insert(res.end(), comp.rbegin(), comp.rend());
	return res;
}


int main(int argc, char *argv[])
{
	long long x, y;
	cin >> x >> y;

	// the answer is the minimum cost for either buying a single sheet and
	// cutting it once to make up both areas, or buying 2 sheets individually

	// since we only pay for the height of any sheet bought, we minimise cost by
	// making this length either the greatest common factor of x and y in the
	// case where we buy a single sheet, or the largest factor of each
	// individually.

	// finally, if numbers are mutually prime (i.e. share no factors) it's
	// impossible to do better than buying sheets individually.

	long long besttogether{LONG_LONG_MAX};
	if (long long z = gcd(x, y); z != 1) {
		auto fx{factors(x)};
		auto fy{factors(y)};
		vector<long long> comfact;
		set_intersection(fx.begin(), fx.end(), fy.begin(), fy.end(), back_inserter(comfact));
		besttogether = *min_element(comfact.begin()+1, comfact.end());
	}
	long long bestind{(x / *(factors(x).rbegin()+1)) + (y / *(factors(y).rbegin()+1))};
	cout << min(bestind, besttogether) << "\n";
	return 0;
}
