#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, s, m;
    std::cin >> n >> s >> m;

    std::vector<int> l(n + 2), r(n + 2);
    l[0] = r[0] = 0;
    l[n + 1] = r[n + 1] = m;
    for (int i = 1; i <= n; i++) {
        std::cin >> l[i] >> r[i];
    }

    for (int i = 1; i < n + 2; i++) {
        if (l[i] - r[i - 1] >= s) {
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
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