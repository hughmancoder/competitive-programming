#include <climits>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class BlockEnemy {
private:
  vector<vector<int>> graph;
  vector<bool> occupied;
  int min_effort, A, B;

  bool removeCheapestPath(int node, int source) {
    bool remove_path = occupied[node] && node != source;
    for (int i = 0; i < graph.size(); ++i) {
      // if not visited
      if (graph[node][i] > 0) {
        int current_effort = graph[node][i];
        // mark outgoing nodes as visited for dfs
        graph[node][i] = graph[i][node] = 0;
        if (removeCheapestPath(i, source)) {
          if (current_effort < min_effort) {
            min_effort = current_effort;
            // record start and end index of node we are removing
            A = node;
            B = i;
          }
          remove_path = true;
        }
        // backtrack and remove node as not visited
        graph[node][i] = graph[i][node] = current_effort;
      }
    }
    return remove_path;
  }

public:
  int minEffort(int N, vector<string> roads, vector<int> occupiedTowns) {
    graph = vector<vector<int>>(N, vector<int>(N, 0));

    for (auto &road : roads) {
      istringstream ss(road);
      int a, b, e;
      ss >> a >> b >> e;
      graph[a][b] = graph[b][a] = e;
    }

    occupied = vector<bool>(N, false);
    for (auto &o : occupiedTowns)
      occupied[o] = true;

    int res = 0;
    for (int i = 0; i < N; ++i) {
      if (occupied[i]) {
        while (true) {
          min_effort = INT_MAX;
          // if we don't find an occupied node there is no need to remove a path
          if (!removeCheapestPath(i, i))
            break;
          res += min_effort;
          // mark removed node with cost 0 to remove
          graph[A][B] = graph[B][A] = 0;
        }
      }
    }
    return res;
  }
};
