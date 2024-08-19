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
		adj[u].push_back(v);
	}
	for (int i = 0; i < n - 1; i++) {
		adj[i].push_back(i + 1);
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

	int mn = 1E9, mx = 0;
	for (int s = 0, x = 0; s < n - 1; s++) {
		int ok = (mx - s) <= mn;
		if (ok) {
			while (x < s && ok) {
				int y = *std::max_element(adj[x].begin(), adj[x].end());
				if (y - s > dis[x] + 1) {
					ok = 0;
					mx = y;
					mn = dis[x] + 1;
				}
				x++;
			}
		}
		std::cout << ok;
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