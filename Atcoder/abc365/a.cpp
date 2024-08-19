#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	if (n % 400 == 0 || n % 4 == 0 && n % 100 != 0) {
		std::cout << 366 << "\n";
	} else {
		std::cout << 365 << "\n";
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