#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	auto manacher = [&](std::string s) -> int {
		std::string t = "#";
		for (auto c : s) {
			t += c;
			t += "#";
		}
		int n = t.size();
		std::vector<int> r(n);
		for (int i = 0, j = 0; i < n; i++) {
			if (2 * j - i >= 0 && j + r[j] > i) {
				r[i] = std::min(r[2 * j - i], j + r[j] - i);
			}
			while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) {
				r[i] += 1;
			}
			if (i + r[i] > j + r[j]) {
				j = i;
			}
		}
		return *max_element(r.begin(), r.end()) - 1;
	};
	int ans = manacher(s);
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