#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	int n, m;
	n = rng() % 10 + 1;
	m = rng() % n;
	std::cout << n << " " << m << "\n";

	for (int i = 0; i < m; i++) {
		int u, v;
		u = rng() % n + 1;
		v = rng() % n + 1;
		if (u == v) {
			i--;
			continue;
		}
		if (u > v) {
			std::swap(u, v);
		}
		std::cout << u << " " << v << "\n";
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    std::cout << T << "\n";
	// std::cin >> T;

    while (T--) {
    	solve();
    }

    return 0;
}