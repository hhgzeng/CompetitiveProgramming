#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> c(n);
	std::iota(c.begin(), c.end(), 0);
	std::sort(c.begin(), c.end(), [&](int x, int y) {
		return a[x] > a[y];
	});

	std::cout << c[1] + 1 << "\n";
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