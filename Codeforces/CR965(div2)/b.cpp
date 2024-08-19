#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	for (int i = 1; i < n; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << a[0] << "\n";
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