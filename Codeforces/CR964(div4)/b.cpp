#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int a1, a2, b1, b2;
    std::cin >> a1 >> a2 >> b1 >> b2;

    int ans = 0;
    if (a1 > b1 && a2 >= b2 || a1 >= b1 && a2 > b2) {
        ans++;
    }
    if (a1 > b2 && a2 >= b1 || a1 >= b2 && a2 > b1) {
        ans++;
    }
    if (a2 > b1 && a1 >= b2 || a2 >= b1 && a1 > b2) {
        ans++;
    }
    if (a2 > b2 && a1 >= b1 || a2 >= b2 && a1 > b1) {
        ans++;
    }
    std::cout << ans << "\n";
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