#include <bits/stdc++.h>
using namespace std;

// Kahn's algorithm
optional<vector<int>> topological(const vector<list<int>> &g)
{
	vector<int> indegree(g.size(), 0);
	vector<int> res;
	for_each(g.begin(), g.end(),
			 [&](const list<int> &l) {
				 for_each(l.begin(), l.end(), [&](int e) { ++indegree[e]; });
			 });

	queue<int> q;
	for (int i{0}; i < g.size(); ++i) {
		if (indegree[i] == 0) { q.push(i); }
	}
	for (; !q.empty(); q.pop()) {
		int x{q.front()};
		res.push_back(x);
		for_each(g[x].begin(), g[x].end(), [&](int e) { if (--indegree[e] == 0) { q.push(e); }});
	}

	return (all_of(indegree.begin(), indegree.end(), [](int x) { return x == 0; }) ?
			optional<vector<int>>{res} :
			nullopt);
}

int max_dist(const vector<list<int>> &g, vector<int> &dist, int v)
{
	if (dist[v]) { return dist[v]; }
	for (auto e : g[v]) { dist[v] = max(max_dist(g, dist, e)+1, dist[v]); }
	return dist[v];
}

int longest_path(const vector<list<int>> &g, const vector<int> &topo)
{
	vector<int> dist(g.size(), 0);
	for (int v : topo) {
		max_dist(g, dist, v);
	}
	return *max_element(dist.begin(), dist.end());
}

int main(int argc, char *argv[])
{
	int f, p;
	cin >> f >> p;
	vector<list<int>> g(f);
	for (auto i{0}; i < p; ++i) {
		int x, y;
		cin >> x >> y;
		g[y-1].push_front(x-1);
	}

	// the relationship between icecream flavours form a graph where there's an
	// edge from x to y if flavour y can be placed atop flavour x.  If any
	// cycles exist in the graph then the stack can be arbitrarily high.

	// the basic algorithm comes down to running a dfs from each vertex in order
	// to determine the longest possible path through the graph.  By keeping
	// track of the maximum length from each vertex we only need to visit each
	// one once.

	// I've used a topological sort to find cycles but that isn't strictly
	// necessary, it can also be done as part of the dfs.

	auto topo{topological(g)};

	cout << (topo ? longest_path(g, *topo) + 1 : -1) << "\n";
	return 0;
}
