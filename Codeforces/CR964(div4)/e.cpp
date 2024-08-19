#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int l, r;
    std::cin >> l >> r;

    i64 ans = 0;
    int x = 3, s = 1;
    while (x < l) {
        x *= 3;
        s++;
    }
    int lst = l - 1;
    while (x < r) {
        ans += s * (x - lst) + 1;
        lst = x;
        x *= 3;
        s++;
    }
    if (r == x) {
        ans++;
    }
    x = std::min(x, r);
    ans += s * (x - lst);

    int ok = 0;
    while (l) {
        if (l % 3 != 0) {
            ok = 1;
        }   
        l /= 3;
        ans++;
    }
    if (!ok) {
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