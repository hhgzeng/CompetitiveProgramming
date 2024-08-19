#include <bits/stdc++.h>

using i64 = long long;

std::set<int> point;
std::set<std::pair<int, int>> bridge;
std::set<std::pair<int, int>> E;

struct EBCC {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> dfn, low, bel;
    std::vector<int> stk;
    int cur, cnt;
    
    EBCC() {}
    EBCC(int n) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        stk.clear();
        cur = cnt = 0;
    }
    
    void addEdge(int u, int v) {
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    
    void dfs(int x, int p) {
        dfn[x] = low[x] = cur++;
        stk.emplace_back(x);
            
        int child = 0;
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            if (dfn[y] == -1) {
                child++;
                E.emplace(x, y);
                dfs(y, x);
                low[x] = std::min(low[x], low[y]);
                if (low[y] >= dfn[x] && p != -1) {
                    point.emplace(x);
                }
                if (low[y] > dfn[x]) {
                    bridge.emplace(x, y);
                }
            } else if (bel[y] == -1 && dfn[y] < dfn[x]) {
                E.emplace(x, y);
                low[x] = std::min(low[x], dfn[y]);
            }
        }
        
        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stk.back();
                bel[y] = cnt;
                stk.pop_back();
            } while (y != x);
            cnt++;
        }

        if (p == -1 && child >= 2) {
            point.emplace(x);
        }
    }
    
    std::vector<int> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i, -1);
            }
        }
        return bel;
    }
    
    struct Graph {
        int n;
        std::vector<std::pair<int, int>> edges;
        std::vector<int> siz;
        std::vector<int> cnte;
    };
    Graph compress() {
        Graph g;
        g.n = cnt;
        g.siz.resize(cnt);
        g.cnte.resize(cnt);
        for (int i = 0; i < n; i++) {
            g.siz[bel[i]]++;
            for (auto j : adj[i]) {
                if (bel[i] < bel[j]) {
                    g.edges.emplace_back(bel[i], bel[j]);
                } else if (i < j) {
                    g.cnte[bel[i]]++;
                }
            }
        }
        return g;
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;

    EBCC ebcc(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        ebcc.addEdge(u, v);
    }

    ebcc.work();
    std::cout << point.size() << "\n";
    for (auto x : point) {
        std::cout << x + 1 << " ";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    while (T--) {
        solve();
    }

    return 0;
}