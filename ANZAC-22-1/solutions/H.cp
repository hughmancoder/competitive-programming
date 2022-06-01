#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

bool isComposite[2000005];

ll L, H;
string P;
vector<ll> primes;

signed main() {
	for (ll i = 2; i < 2000000; ++i) {
		if (!isComposite[i]) {
			primes.push_back(i);
			for (ll k = 2; i * k < 2000000; ++k) {
				isComposite[i * k] = true;
			}
		}
	}
	
	cin >> L >> H >> P;
	ll ans = 0;
	for (ll i = L - 1; i <= H - 1; ++i) {
		ans += to_string(primes[i]).find(P) != string::npos;
	}
	cout << ans << "\n";
}