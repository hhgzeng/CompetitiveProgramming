#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::cout << n / 10 + n % 10 << "\n";
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