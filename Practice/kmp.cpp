#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s, t;
	std::cin >> s >> t;

	const int n = s.size();
	const int m = t.size();
	std::vector<int> nxt(m, -1);
	std::vector<int> ans;
	auto kmp = [&](std::string s, std::string t) {
		for (int i = 1, j = -1; i < m; i++) {
			while (j >= 0 && t[i] != t[j + 1]) {
				j = nxt[j];
			}
			if (t[i] == t[j + 1]) {
				j++;
			}
			nxt[i] = j;
		}

		for (int i = 0, j = -1; i < n; i++) {
			while (j >= 0 && s[i] != t[j + 1]) {
				j = nxt[j];
			}
			if (s[i] == t[j + 1]) {
				j++;
			}
			if (j == m - 1) {
				ans.emplace_back(i - j);
				j = nxt[j];
			}
		}
	};
	kmp(s, t);

	for (int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] + 1 << "\n";
	}
	for (int i = 0; i < m; i++) {
		std::cout << nxt[i] + 1 << " \n"[i == m - 1];
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