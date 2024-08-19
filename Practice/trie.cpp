#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1E6;
int trie[N][2];
int f[N], s[N];
int tot;

int newNode() {
	int x = ++tot;
	trie[x][0] = trie[x][1] = 0;
	f[x] = 0;
	return x;
}

void add(std::vector<int> a) {
	int p = 1;
	for (auto c : a) {
		int &q = trie[p][c];
		if (q == 0) {
			q = newNode();
		}
		p = q;
		s[p]++;
	}
	f[p]++;
}

int query(std::vector<int> a) {
	int p = 1, res = 0;
	for (auto c : a) {
		res += f[p];
		int q = trie[p][c];
		if (q == 0) {
			return res;
		}
		p = q;
	}
	return res + s[p];
}

void solve() {
	int n, m;
	std::cin >> n >> m;

	newNode();
	
	for (int i = 0; i < n; i++) {
		int t;
		std::cin >> t;

		std::vector<int> a(t);
		for (int j = 0; j < t; j++) {
			std::cin >> a[j];
		}
		add(a);
	}

	for (int i = 0; i < m; i++) {
		int t;
		std::cin >> t;

		std::vector<int> a(t);
		for (int j = 0; j < t; j++) {
			std::cin >> a[j];
		}
		int ans = query(a);
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