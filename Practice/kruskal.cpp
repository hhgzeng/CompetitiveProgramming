#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
	std::vector<int> f, siz;

	DSU() {}
	DSU(int n) {
		init(n);
	}

	void init(int n) {
		f.resize(n);
		std::iota(f.begin(), f.end(), 0);
		siz.assign(n, 1);
	}

	int find(int x) {
		while (x != f[x]) {
			x = f[x] = f[f[x]];
		}
		return x;
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}

	bool merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) {
			return false;
		}
		siz[x] += siz[y];
		f[y] = x;
		return true;
	}

	int size(int x) {
		return siz[find(x)];
	}
};

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::array<int, 3>> edges(m);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		u--;
		v--;
		edges[i] = {w, u, v};
	}

	std::sort(edges.begin(), edges.end());

	DSU dsu(n);
	i64 ans = 0;
	for (int i = 0; i < m; i++) {
		auto [w, x, y] = edges[i];
		if (dsu.merge(x, y)) {
			ans += w;
		}
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