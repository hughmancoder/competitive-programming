#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

class ErdosNumber {
public:
    vector<string> calculateNumbers(vector<string> publications) {
        set<string> all_authors;
        map<string, set<string>> graph;
        map<string, int> visited;
        queue<string> q;
        vector<string> res;

        // Build graph
        for (int i = 0; i < publications.size(); i++) {
            string publication = publications[i];
            vector<string> authors;
            size_t j = 0;
            while (j < publication.size()) {
                size_t space_pos = publication.find(' ', j);
                if (space_pos == string::npos) {
                    authors.push_back(publication.substr(j));
                    break;
                } else {
                    authors.push_back(publication.substr(j, space_pos - j));
                    j = space_pos + 1;
                }
            }

            for (int k = 0; k < authors.size(); k++) {
                string name = authors[k];
                graph[name].insert(authors.begin(), authors.end());
                all_authors.insert(name);
            }
        }

        // BFS
        q.push("ERDOS");
        visited["ERDOS"] = 0;
        while (!q.empty()) {
            string node = q.front();
            q.pop();
            for (set<string>::iterator it = graph[node].begin(); it != graph[node].end(); ++it) {
                string neighbor = *it;
                if (visited.find(neighbor) == visited.end()) {
                    visited[neighbor] = visited[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        for (set<string>::iterator it = all_authors.begin(); it != all_authors.end(); ++it) {
            string author = *it;
            if (visited.find(author) == visited.end()) {
                res.push_back(author);
            } else {
                res.push_back(author + " " + to_string(visited[author]));
            }
        }

        // Sort lexicographically
        sort(res.begin(), res.end());

        return res;
    }
};
