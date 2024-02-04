from sys import stdin, stdout

""" N = 200005
adj = [[] for _ in range(N)]
vis = [False] * N
entry_node = -1
path = [] 
"""

# NOTE: runs out of memory due to python's nature

def solve():
    """ global vis, adj, entry_node """

    def dfs1(u, p):
        global entry_node
        vis[u] = True
        for v in adj[u]:
            if v != p and vis[v]:
                entry_node = v
                return True
            elif v != p and not vis[v]:
                if dfs1(v, u):
                    return True
        return False

    def dfs2(u):
        vis[u] = True
        min_dist = n
        for v in adj[u]:
            if v == entry_node:
                return 1
            if not vis[v]:
                dist = dfs2(v) + 1
                min_dist = min(dist, min_dist)
        return min_dist
    
    
    n, a, b = map(int, input().split())
    vis = [False] * (n + 1)
    adj = [[] for _ in range(n + 1)]
    for _ in range(n):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)

    
    dfs1(b, -1)
    vis = [False] * (n + 1)

    distMarcel = -1
    distValeriu = -1
    if entry_node == a:
        distMarcel = 0
    else:
        distMarcel = dfs2(a)
    vis = [False] * (n + 1)
    if entry_node == b:
        distValeriu = 0
    else:
        distValeriu = dfs2(b)
    if distValeriu < distMarcel:
        print("YES")
    else:
        print("NO")
    for i in range(1, n + 1):
        adj[i].clear()
        vis[i] = False
    # entry_node = -1

def main():
    t = int(input())
    while t:
        solve()
        t -= 1

main()