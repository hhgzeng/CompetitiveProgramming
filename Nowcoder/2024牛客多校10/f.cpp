#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    auto valid = [&](int a, int b) {
        return 0 <= a && a < n && 0 <= b && b < n;
    };

    std::vector<std::pair<int, int>> v;
    std::vector bad(n, std::vector<int> (n, 1));
    for (int i = 0; i < n * n; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;

        if (!bad[x][y]) {
            std::cout << 0;
            continue;
        }
        std::cout << 1;
        for (auto [a, b] : v) {
            int u = a - x;
            int v = b - y;
            int g = std::gcd(u, v);
            u /= g;
            v /= g;
            a = x;
            b = y;
            while (valid(a, b)) {
                bad[a][b] = 0;
                a += u;
                b += v;
            }
            a = x;
            b = y;
            while (valid(a, b)) {
                bad[a][b] = 0;
                a -= u;
                b -= v;
            }
        }
        v.emplace_back(x, y);
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