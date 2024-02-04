#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>

using namespace std;

struct Node {
    int x, y, garbage_count, adj_garbage_count;

    bool operator<(const Node& other) const {
        if (garbage_count != other.garbage_count) {
            return garbage_count > other.garbage_count;
        }
        return adj_garbage_count > other.adj_garbage_count;
    }
};

class ForestGarbage {
    vector<pair<int, int> > neighbours;
public:
    ForestGarbage() {
        neighbours.push_back(make_pair(-1, 0));
        neighbours.push_back(make_pair(1, 0));
        neighbours.push_back(make_pair(0, -1));
        neighbours.push_back(make_pair(0, 1));
    }

    vector<int> bestWay(vector<string>& forest) {
        int rows = forest.size();
        int cols = forest[0].length();
        pair<int, int> start, end;

        // Find starting and destination points
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (forest[i][j] == 'S') {
                    start = make_pair(i, j);
                } else if (forest[i][j] == 'F') {
                    end = make_pair(i, j);
                }
            }
        }

        priority_queue<Node> pq;
        Node startNode;
        startNode.x = start.first;
        startNode.y = start.second;
        startNode.garbage_count = 0;
        startNode.adj_garbage_count = 0;
        pq.push(startNode);

        set<int> visited;

        while (!pq.empty()) {
            Node current = pq.top();
            pq.pop();

            int x = current.x, y = current.y;
            int hash_key = x * 10000 + y;

            if (visited.find(hash_key) != visited.end()) {
                continue;
            }
            visited.insert(hash_key);

            // Found destination
            if (x == end.first && y == end.second) {
                vector<int> result;
                result.push_back(current.garbage_count);
                result.push_back(current.adj_garbage_count);
                return result;
            }

            for (int i = 0; i < static_cast<int>(neighbours.size()); ++i) {
                pair<int, int> move = neighbours[i];
                int nx = x + move.first;
                int ny = y + move.second;
                int hash_key = nx * 10000 + ny;
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && visited.find(hash_key) == visited.end()) {
                    int new_garbage_count = current.garbage_count;
                    int new_adj_garbage_count = current.adj_garbage_count;

                    if (forest[nx][ny] == 'g') {
                        new_garbage_count++;
                    } else if (forest[nx][ny] == '.') {
                        for (int j = 0; j < static_cast<int>(neighbours.size()); ++j) {
                            int nx2 = nx + neighbours[j].first;
                            int ny2 = ny + neighbours[j].second;
                            if (nx2 >= 0 && nx2 < rows && ny2 >= 0 && ny2 < cols && forest[nx2][ny2] == 'g') {
                                new_adj_garbage_count++;
                                break;
                            }
                        }
                    }

                    Node newNode;
                    newNode.x = nx;
                    newNode.y = ny;
                    newNode.garbage_count = new_garbage_count;
                    newNode.adj_garbage_count = new_adj_garbage_count;
                    pq.push(newNode);
                }
            }
        }

        vector<int> invalid_result;
        invalid_result.push_back(-1);
        invalid_result.push_back(-1);
        return invalid_result;  // Shouldn't reach here with valid inputs
    }
};

