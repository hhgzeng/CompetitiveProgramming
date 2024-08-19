#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector dp(n, std::vector<int>(n));
	for (int i = 0; i < m; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		u--;
		v--;
		dp[u][v] = w;
		dp[v][u] = w;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	int s, t;
	std::cin >> s >> t;
	std::cout << dp[s][t] << "\n";
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