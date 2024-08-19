#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    int n;
    n = rng() % 1000 + 1;
    std::cout << n << "\n";

    const int N = n * n;
    std::set<std::pair<int, int>> s;
    for (int i = 0; i < N; i++) {
        int x, y;
        x = rng() % n + 1;
        y = rng() % n + 1;
        if (s.count({x, y})) {
            i--;
            continue;
        }
        s.emplace(x, y);
        std::cout << x << " " << y << "\n";
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