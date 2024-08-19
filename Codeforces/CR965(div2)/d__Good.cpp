#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;
		v--;
		adj[u].emplace_back(v);
	}
	for (int i = 0; i < n - 1; i++) {
		adj[i].emplace_back(i + 1);
	}

    std::vector<int> dis(n, -1);
    dis[0] = 0;
    std::queue<int> q;
    q.push(0);
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        for (auto y : adj[x]) {
            if (dis[y] == -1) {
                dis[y] = dis[x] + 1;
                q.push(y);
            }
        }
    }

	std::vector<int> d(n);
	for (int x = 0; x < n; x++) {
		for (auto y : adj[x]) {
			int l = x + 1;
			int r = std::min(y, y - dis[x] - 1);
			if (l < r) {
				d[l]++;
				d[r]--;
			}
		}
	}

	for (int i = 1; i < n; i++) {
		d[i] += d[i - 1];
	}

	for (int i = 0; i < n - 1; i++) {
		std::cout << (d[i] == 0);
	}
	std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
	std::cin >> T;

    while (T--) {
    	solve();
    }

    return 0;
}