#include <bits/stdc++.h>
using namespace std;

// Time Complexity O(2*n^2)
// Space Complexity O(n^2)


// Dfs through the graph, double counting everything. Once on the way there, and once on the way back
int solver(vector<string> &graph, int i, int j, int n, set<pair<int, int>> &visited)
{

    // This base case is important, because you dont want to count square that you can reach after you reach the end point.
    if (i == n - 1 && j == n - 1)
    {
        return 1;
    }

    visited.insert({i, j});
    int moves = 0;
    if (i + 1 < n && graph[i + 1][j] != '#' && visited.count({i + 1, j}) == 0)
    {
        moves += solver(graph, i + 1, j, n, visited) + 1;
    }
    if (i - 1 >= 0 && graph[i - 1][j] != '#' && visited.count({i - 1, j}) == 0)
    {
        moves += solver(graph, i - 1, j, n, visited) + 1;
    }
    if (j + 1 < n && graph[i][j + 1] != '#' && visited.count({i, j + 1}) == 0)
    {
        moves += solver(graph, i, j + 1, n, visited) + 1;
    }
    if (j - 1 >= 0 && graph[i][j - 1] != '#' && visited.count({i, j - 1}) == 0)
    {
        moves += solver(graph, i, j - 1, n, visited) + 1;
    }
    return moves + 1;
}

// Another dfs, but this time it only searches for the shortest parth to the exit 
void solver2(vector<string> &graph, int i, int j, int n, int step, int &ret, set<pair<int, int>> &visited)
{
    if (i == n - 1 && j == n - 1)
    {
        ret = max(ret, step);
    }

    visited.insert({i, j});
    int moves = 0;
    if (i + 1 < n && graph[i + 1][j] != '#' && visited.count({i + 1, j}) == 0)
    {
        solver2(graph, i + 1, j, n, step + 1, ret, visited);
    }
    if (i - 1 >= 0 && graph[i - 1][j] != '#' && visited.count({i - 1, j}) == 0)
    {
        solver2(graph, i - 1, j, n, step + 1, ret, visited);
    }
    if (j + 1 < n && graph[i][j + 1] != '#' && visited.count({i, j + 1}) == 0)
    {
        solver2(graph, i, j + 1, n, step + 1, ret, visited);
    }
    if (j - 1 >= 0 && graph[i][j - 1] != '#' && visited.count({i, j - 1}) == 0)
    {
        solver2(graph, i, j - 1, n, step + 1, ret, visited);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> graph;
    for (int i = 0; i < n; i++)
    {
        string val;
        cin >> val;
        graph.push_back(val);
    }

    int ret = 1;
    set<pair<int, int>> visited;
    visited.insert({0, 0});
    int dfs1 = solver(graph, 0, 0, n, visited);
    visited.clear();
    int dfs2;
    solver2(graph, 0, 0, n, 0, dfs2, visited);

    // after doing a the first dfs you have double counted everything
    // after the second dfs you have found the shortest path. 
    // therefore the maximum path is a back and forth trip on every path + 1 trip on the shortest path, hence ans = dfs1 -dfs2



    cout << dfs1 - dfs2 << endl;

    return 0;
}