#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	std::vector dp(n + 1, std::vector<int> (2));
	dp[0][0] = dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1]) {
			dp[i + 1][0] = dp[i][1];
			dp[i + 1][1] = dp[i][0] + 1;
		} else {
			if ((s[i - 1] == 'S' && s[i] == 'P') || (s[i - 1] == 'P' && s[i] == 'R') || (s[i - 1] == 'R' && s[i] == 'S')) {
				dp[i + 1][0] = std::max(dp[i][0], dp[i][1]);
				dp[i + 1][1] = dp[i][1] + 1;
			} else if ((s[i] == 'S' && s[i - 1] == 'P') || (s[i] == 'P' && s[i - 1] == 'R') || (s[i] == 'R' && s[i - 1] == 'S')) {
				dp[i + 1][0] = dp[i][0];
				dp[i + 1][1] = std::max(dp[i][0], dp[i][1]) + 1;
			} else {
				dp[i + 1][0] = std::max(dp[i][0], dp[i][1]);
				dp[i + 1][1] = std::max(dp[i][0], dp[i][1]) + 1;
			}
		}
	}
	std::cout << std::max(dp[n][0], dp[n][1]) << "\n";
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