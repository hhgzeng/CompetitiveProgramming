#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n, k;
	std::cin >> n >> k;

	std::vector<i64> a(n), b(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}

	std::vector<int> c(n);
	std::iota(c.begin(), c.end(), 0);
	std::sort(c.begin(), c.end(), [&](int x, int y) {
		return a[x] != a[y] ? a[x] < a[y] : b[x] < b[y];
	});

	i64 ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		int x = c[i];
		if (b[x] == 1) {
			if (a[x] + k > a[c[n - 1]]) {
				if (i > n / 2 - 1) {
					ans = std::max(ans, a[x] + k + a[c[n / 2 - 1]]);
				} else {
					ans = std::max(ans, a[x] + k + a[c[n / 2]]);
				}
			}
			break;
		}
	}

	i64 lst = 0, s = 1;
	std::multiset<i64> f;
	for (int i = 0; i < n - 1; i++) {
		int x = c[i];
		if (i <= n / 2 - 1 && b[x] == 1) {
			f.emplace(a[x]);
		}
		if (i >= n / 2 - 1) {
			if (lst == 0) {
				if (f.empty()) {
					lst = a[x];
					k = 0;
					break;
				}
				lst = *f.rbegin();
				f.extract(lst);
				continue;
			}
			if (k <= (a[x] - lst) * s) {
				lst += k / s;
				k = 0;
				break;
			}
			k -= (a[x] - lst) * s;
			lst = a[x];
			if (b[x] == 0) {
				if (f.size() > 0) {
					int t = *f.rbegin();
					f.extract(t);
					k -= std::min(k, a[x] - t);
				} else {
					k = 0;
				}
				if (k == 0) {
					break;
				}
			}
			s++;
		}
	}
	ans = std::max(ans, std::max(a[c[n / 2 - 1]], lst + k / s) + a[c[n - 1]]);
	std::cout << ans << "\n";
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