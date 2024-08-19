#include <bits/stdc++.h>

using i64 = long long;

struct SCC {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> dfn, low, bel;
    std::vector<int> stk;
    std::vector<int> a, b;
    int cur, cnt;

    SCC() {}
    SCC(int n) {
        init(n);
    }

    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        stk.clear();
        a.resize(n);
        b.resize(n);
        cur = cnt = 0;
    }

    void addEdge(int u, int v) {
        adj[u].emplace_back(v);
    }

    void dfs(int x) {
        dfn[x] = low[x] = cur++;
        stk.emplace_back(x);
        for (auto y : adj[x]) {
            if (dfn[y] == -1) {
                dfs(y);
                low[x] = std::min(low[x], low[y]);
            } else if (bel[y] == -1) {
                low[x] = std::min(low[x], dfn[y]);
            }
        }

        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stk.back();
                bel[y] = cnt;
                b[cnt] += a[y];
                stk.pop_back();
            } while (x != y);
            cnt++;
        }
    }

    std::vector<int> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i);
            }
        }
        return bel;
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;

    SCC scc(n);
    for (int i = 0; i < n; i++) {
        std::cin >> scc.a[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        scc.addEdge(u, v);
    }

    scc.work();
    std::vector<std::vector<int>> g(n);
    std::vector<int> ind(n);
    for (int x = 0; x < n; x++) {
        for (auto y : scc.adj[x]) {
            if (scc.bel[x] != scc.bel[y]) {
                g[scc.bel[x]].emplace_back(scc.bel[y]);
                ind[scc.bel[y]]++;
            }
        }
    }

    std::queue<int> q;
    std::vector<int> dis(n);
    for (int x = 0; x < scc.cnt; x++) {
        if (!ind[x]) {
            q.push(x);
            dis[x] = scc.b[x];
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto y : g[x]) {
            dis[y] = std::max(dis[y], dis[x] + scc.b[y]);
            ind[y]--;
            if (ind[y] == 0) {
                q.push(y);
            }
        }
    }
    int ans = *std::max_element(dis.begin(), dis.end());
    std::cout << ans << "\n";
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