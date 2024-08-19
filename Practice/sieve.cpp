#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.emplace_back(i);
        }

        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[p]) {
                break;
            }
        }
    }
}

void solve() {
    const int N = 1E2;

    sieve(N);
    for (int i = 1; i <= N; i++) {
        std::cout << i << " " << minp[i] << "\n";
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