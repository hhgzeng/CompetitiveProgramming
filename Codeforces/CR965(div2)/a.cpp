#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int x, y, k;
	std::cin >> x >> y >> k;

	if (k & 1) {
		std::cout << x << " " << y << "\n";
	}
	k--;
	for (int i = 1; i <= k; i += 2) {
		std::cout << x - i << " " << y - i << "\n";
		std::cout << x + i << " " << y + i << "\n";
	}
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