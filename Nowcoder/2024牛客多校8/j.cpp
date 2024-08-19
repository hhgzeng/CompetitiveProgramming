#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    if (m == n - 2) {
        std::cout << -1 << "\n";
        return;
    }
    if (m == 0) {
        int d = n / 3;
        if (n % 3 >= 1) {
            std::cout << 3 * d + 1 << " ";
        }
        for (int i = 0; i < d; i++) {
            std::cout << d - i << " " << 2 * d - i << " " << 3 * d - i << " ";
        }
        if (n % 3 >= 2) {
            std::cout << 3 * d + 2 << " ";
        }
        std::cout << "\n";
        return;
    }
    if (m == n - 3) {
        for (int i = 1; i <= n; i++) {
            std::cout << i << " \n"[i == n];
        }
        return;
    }

    int N = n - m;
    int d = N / 3;
    if (N % 3 == 2 || (N % 3 == 1 && 3 * d + 2 > N + 1)) {
        std::cout << 3 * d + 1 << " ";
    }
    for (int i = 0; i < d; i++) {
        std::cout << d - i << " " << 2 * d - i << " " << 3 * d - i << " ";
    }
    if (N % 3 == 2) {
        std::cout << 3 * d + 2 << " ";
    }
    for (int i = N + 1; i <= n; i++) {
        std::cout << i << " ";
    }
    if (N % 3 == 1 && 3 * d + 2 <= N + 1) {
        std::cout << 3 * d + 1 << " ";
    }
    std::cout << "\n";
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