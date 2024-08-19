#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--;
        v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int ans = 0;
    std::vector<int> dis(n, inf), vis(n);
    auto prim = [&]() -> void {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        pq.emplace(0, 0);
        dis[0] = 0;

        while (!pq.empty()) {
            auto [d, x] = pq.top();
            pq.pop();

            if (d != dis[x]) {
                continue;
            }
            if (vis[x] == 0) {
                ans += d;
            }
            vis[x] = 1;
            for (auto [y, w] : adj[x]) {
                if (dis[y] > w) {
                    dis[y] = w;
                    pq.emplace(dis[y], y);
                }
            }
        }
    };
    prim();
    if (std::count(dis.begin(), dis.end(), inf)) {
        std::cout << "orz\n";
        return;
    }
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