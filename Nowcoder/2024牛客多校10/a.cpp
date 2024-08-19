#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	if (std::count(s.begin(), s.end(), 'Y') >= 4) {
		std::cout << 1 << "\n";
	} else if (std::count(s.begin(), s.end(), 'N') >= 2) {
		std::cout << -1 << "\n";
	} else {
		std::cout << 0 << "\n";
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