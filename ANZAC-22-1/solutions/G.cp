#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define MAXRC 55

struct frac {
    int num;
    int den;
    int fl() {
        return num/den;
    }
    int ce() {
        if (num%den) {
            return num/den + 1;
        }
        return num/den;
    }
    frac operator+(frac b) const {
        int n = num*b.den + b.num*den;
        int d = den*b.den;
        int gecd = __gcd(n,d);
        return {n/gecd, d/gecd};
    }
};

typedef pair<ld, pair<int, int>> edge;
priority_queue<edge, vector<edge>, greater<edge>> pq;

vector<edge> edges[MAXRC][MAXRC];

char graph[MAXRC][MAXRC];

bool seen[MAXRC][MAXRC];
ld dist[MAXRC][MAXRC];

void dij() {
    pq.push(edge((ld)0, make_pair(0,0)));
    while (!pq.empty()) {
        edge cur = pq.top();
        pq.pop();
        pair<int,int> v = cur.second;
        ld d = cur.first;
        if (seen[v.first][v.second]) continue;

        dist[v.first][v.second] = d;
        seen[v.first][v.second] = true;

        for (int i=0;i<edges[v.first][v.second].size();i++) {
            edge next = edges[v.first][v.second][i];
            pair<int,int> u = next.second;
            // cout << "(" << v.first << " " << v.second << ")" << "(" << u.first << " " << u.second << ")" << endl;
            ld weight = next.first;
            if (!seen[u.first][u.second]) pq.push(edge(d+weight, u));
        }
    }
}

int main() {
    int r,c;
    scanf("%d %d",&r,&c);
    for (int i=0;i<r;i++) {
        scanf("%s",graph[i]);
    }
    for (int i=0;i<=r;i++) {
        for (int j=0;j<=c;j++) {
            edges[i][j].push_back(make_pair(1, make_pair(i+1,j)));
            edges[i][j].push_back(make_pair(1, make_pair(i,j+1)));
            edges[i+1][j].push_back(make_pair(1, make_pair(i,j)));
            edges[i][j+1].push_back(make_pair(1, make_pair(i,j)));
        }
    }
    for (int i=0;i<=r;i++) {
        for (int j=0;j<=c;j++) {
            for (int k=i+1;k<=r;k++) {
                for (int l=j+1;l<=c;l++) {
                    // if (__gcd(k-i,l-j) != 1) continue;
                    frac gradient = {l-j, k-i};
                    frac t = {j,1};
                    pair<int, frac> prev_point = make_pair(i, t);
                    bool good = true;
                    for (int diff = i+1; diff <= k; diff++) {
                        pair<int, frac> cur_point = make_pair(prev_point.first+1, prev_point.second+gradient);
                        int lo = prev_point.second.fl();
                        int hi = cur_point.second.ce();
                        for (int check = lo; check < hi; check++) {
                            if (graph[prev_point.first][check] == '#') {
                                good = false;
                                break;
                            }
                        }
                        if (!good) {break;}
                        prev_point = cur_point;
                    }
                    // cout << (ld)sqrt((k-i)*(k-i)+(l-j)*(l-j)) << endl;
                    if (good) {
                        edges[i][j].push_back(make_pair((ld)sqrt(((ld)k-i)*(k-i)+(l-j)*(l-j)), make_pair(k,l)));
                        edges[k][l].push_back(make_pair((ld)sqrt(((ld)k-i)*(k-i)+(l-j)*(l-j)), make_pair(i,j)));
                        // cout << "(" << i << " " << j << ")" << "(" << k << " " << l << ")" << endl;
                    }
                }
            }
        }
    }
    dij();
    // for (int i=0;i<=r;i++) {
    //     for (int j=0;j<=r;j++) {

    //     }
    // }
    printf("%.9Lf\n", dist[r][c]);
}