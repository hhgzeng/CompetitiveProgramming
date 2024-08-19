#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    const int N = n / k;
    std::vector<std::string> ans(N);
    for (int i = 0; i < n; i += k) {
        for (int j = 0; j < n; j += k) {
            ans[i / k] += s[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        std::cout << ans[i] << "\n";
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