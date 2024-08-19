#include <bits/stdc++.h>

using i64 = long long;

// n points, m edges, w
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

	std::vector<int> dis(n, -1);
	auto dijkstra = [&](int s, int t) -> void {
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
		dis[s] = 0;
		pq.emplace(0, s);

		while (!pq.empty()) {
			auto [d, x] = pq.top();
			pq.pop();

			if (dis[x] != d) {
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

	int s, t;
	std::cin >> s >> t;
	dijkstra(s, t);
	std::cout << dis[t] << "\n";
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