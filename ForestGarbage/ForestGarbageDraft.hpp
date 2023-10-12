#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <unordered_set>
using namespace std;

class ForestGarbage {
    struct Node {
        int x;
        int y;
        int pathCost;
        int edgeCost;
    };

    int offsets[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool neighbourIsGarbage(int x, int y, vector<string> &forest) {
        int n = forest.size();
        int m = forest[0].size();
        for (int i = 0; i < 4; i++) {
            int nx = x + offsets[i][0];
            int ny = y + offsets[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && forest[nx][ny] == 'g') {
                return true;
            }
        }
        return false;
    }

public:
    vector<int> bestWay(vector<string> forest) {
        vector<vector<int>> result;
        int n = forest.size();
        int m = forest[0].size();
        queue<Node> q;
        unordered_set<string> visited;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (forest[i][j] == 'S') {
                    q.emplace(Node{i, j, 0, 0});
                    visited.insert(to_string(i) + "," + to_string(j));
                    break;
                }
            }
            if (!q.empty()) break;  // Break outer loop if 'S' is found
        }

        while (!q.empty()) {
            Node cur = q.front();
            q.pop();
            int x = cur.x;
            int y = cur.y;

            if (forest[x][y] == 'F') {
                result.push_back({cur.pathCost, cur.edgeCost});
            }

            bool path = false;
            for (int i = 0; i < 4; i++) {
                int nx = x + offsets[i][0];
                int ny = y + offsets[i][1];
                string key = to_string(nx) + "," + to_string(ny);
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && forest[nx][ny] != 'g' && visited.find(key) == visited.end()) {
                    q.emplace(Node{nx, ny, cur.pathCost, cur.edgeCost + neighbourIsGarbage(nx, ny, forest)});
                    visited.insert(key);
                    path = true;
                }
            }

            if (!path) {
                for (int i = 0; i < 4; i++) {
                    int nx = x + offsets[i][0];
                    int ny = y + offsets[i][1];
                    string key = to_string(nx) + "," + to_string(ny);
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited.find(key) == visited.end()) {
                        q.emplace(Node{nx, ny, cur.pathCost + 1, cur.edgeCost});
                        visited.insert(key);
                    }
                }
            }
        }

        int minPathCost = INT_MAX;
        int minEdgeCost = INT_MAX;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i][0] << " " << result[i][1] << endl;
            if (result[i][0] < minPathCost) {
                minPathCost = result[i][0];
                minEdgeCost = result[i][1];
            }
            else if (result[i][0] == minPathCost) {
                minEdgeCost = min(result[i][1], minEdgeCost);
            }
        }

        return {minPathCost, minEdgeCost};
    }
};
