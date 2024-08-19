#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1E15;

void solve() {
	int n;
	i64 m;
	std::cin >> n >> m;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	auto check = [&](i64 x) {
		i64 sum = 0;
		for (int i = 0; i < n; i++) {
			sum += std::min(x, 1LL * a[i]);
			if (sum > m) {
				return false;
			}
		}
		return true;
	};

	i64 l = 0, r = inf;
	while (l < r) {
		i64 x = (l + r + 1) / 2;
		if (check(x)) {
			l = x;
		} else {
			r = x - 1;
		}
	}
	if (l == inf) {
		std::cout << "infinite\n";
	} else {
		std::cout << l << "\n";
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