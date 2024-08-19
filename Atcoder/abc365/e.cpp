#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	i64 ans = -std::accumulate(a.begin(), a.end(), 0LL);
	for (int i = 1; i < n; i++) {
		a[i] ^= a[i - 1];
	}

	for (int i = 0; i < 30; i++) {
		int cnt[2] {1, 0};
		for (int j = 0; j < n; j++) {
			if ((a[j] >> i) & 1) {
				ans += 1LL * cnt[0] * (1 << i);
				cnt[1]++;
			} else {
				ans += 1LL * cnt[1] * (1 << i);
				cnt[0]++;
			}
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