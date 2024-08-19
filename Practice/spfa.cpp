#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;

void solve() {
	int n, m;
    std::cin >> n >> m;

    const int N = n + 1;
    std::vector<std::vector<std::pair<int, int>>> adj(N);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--;
        v--;
        adj[u].emplace_back(v, w);
    }
    for (int i = 0; i < n; i++) {
        adj[n].emplace_back(i, 0);
    }

    std::vector<int> h(N, inf), vis(N), cnt(N);
    std::queue<int> q;
    q.emplace(n);
    h[n] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        vis[x] = 0;
        for (auto [y, w] : adj[x]) {
            if (h[y] > h[x] + w) {
                h[y] = h[x] + w;
                cnt[y] = cnt[x] + 1;
                if (cnt[y] >= N) {
                    std::cout << -1 << "\n";
                    return;
                }
                if (!vis[y]) {
                    q.emplace(y);
                    vis[y] = 1;
                }
            }
        }
    }

    for (int x = 0; x < n; x++) {
        for (auto &[y, w] : adj[x]) {
            w += h[x] - h[y];
        }
    }

    std::vector<int> dis;
    auto dijkstra = [&](int s) -> void {
        dis.assign(n, inf);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        pq.emplace(0, s);
        dis[s] = 0;

        while (!pq.empty()) {
            auto [d, x] = pq.top();
            pq.pop();

            if (d != dis[x]) {
                continue;
            }
            for (auto [y, w] : adj[x]) {
                if (dis[y] > dis[x] + w) {
                    dis[y] = dis[x] + w;
                    pq.emplace(dis[y], y);
                }
            }
        }   
    };
    for (int i = 0; i < n; i++) {
        dijkstra(i);

        i64 ans = 0;
        for (int j = 0; j < n; j++) {
            if (dis[j] == inf) {
                ans += 1LL * (j + 1) * dis[j];
            } else {
                ans += 1LL * (j + 1) * (dis[j] + h[j] - h[i]);
            }
        }
        std::cout << ans << "\n";
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