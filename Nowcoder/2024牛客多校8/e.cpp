#include <bits/stdc++.h>

using i64 = long long;

int S(i64 m) { 
    int res = 0;
    while (m) {
        res += m % 10;
        m /= 10;
    }
    return res;
}

void solve() {
    i64 n;
    std::cin >> n;

    const int N = std::sqrt(n);
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = (n - 1) % i + 1; j <= 108; j += i) {
            if (n - j < 0) {
                break;
            }
            i64 x = n - j;
            if (x % i == 0) {
                if (i >= 10 && S(i) == j) {
                    ans++;
                }
                if (x / i >= 10 && x / i != i && S(x / i) == j) {
                    ans++;
                }
            }
        }
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