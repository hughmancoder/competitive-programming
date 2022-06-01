#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// most of this question is just figuring out what it's asking.

// Basically we have a timeline of submissions and associated responses and have
// to take a number of measurements confirming that the response time for recent
// submissions were within a given percentile.

// We're given the number of measurements (n) and the time interval (t) between
// measurements.  Each measurement concerns only responses sent in the range
// [t*n - d, t*n]

// By sorting the {submission, response} pairs by response we can keep a rolling
// window of relevant entries as we make each measurement.  However to calculate
// percentiles we also need to maintain an ordered set of response times for
// these submissions.  We can do this in O(nlogn) by using a data structure
// called an order statistic tree which is a binary tree with a bit of extra
// information on where each node would be in sorted order.  In c++
// we get this for free by including the gnu pbds headers which are supported by
// both g++ and clang.

typedef tree<
	int,
	null_type,
	less_equal<int>,
	rb_tree_tag,
	tree_order_statistics_node_update>
set_t;

// the pth percentile of a collection is the minimum element such that at least
// p percent of elements are less than or equal to it
int percentile(const set_t& vals, int p) {
	int ordinal{static_cast<int>(ceil((double(p)/100)*vals.size()))};
	return *vals.find_by_order(ordinal-1);
}

int response_time(const pair<int,int>& attempt) { return attempt.second - attempt.first; }

int take_measurements(const vector<pair<int,int>> &attempts, int n, int t, int d, int p, int r)
{
	int res{0};
	int attlo{0}, atthi{0};
	set_t considered;

	for (int query{1}; query <= n; ++query) {
		int timehi{query*t};
		int timelo{(query*t)-d};
		while (atthi < attempts.size() && attempts[atthi].second < timehi) {
			considered.insert(response_time(attempts[atthi]));
			++atthi;
		}

		while (attlo < attempts.size() && attempts[attlo].second < timelo) {
			considered.erase(considered.upper_bound(response_time(attempts[attlo])));
			++attlo;
		}

		res += (considered.empty() || percentile(considered, p) <= r ? 1 : 0);
	}
	return res;
}

int main(int argc, char *argv[])
{
	int n, t, d, p, r, m;
	cin >> n >> t >> d >> p >> r >> m;
	vector<pair<int,int>> attempts(m);

	for (int i{0}; i < 2*m; ++i) {
		int ts, attn;
		char type;
		cin >> ts >> attn >> type;
		if (type == 'S') {
			attempts[attn-1].first = ts;
		}
		else { attempts[attn-1].second = ts; }
	}

	std::sort(attempts.begin(), attempts.end(),
			  [](const pair<int,int>& a, const pair<int,int> &b)
			  { return a.second < b.second; });

	cout << take_measurements(attempts, n, t, d, p, r) << "\n";
	return 0;
}
