// author : hhgzeng
#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve()
{
    int n, P;
    cin >> n >> P;

    vector<int> f(n + 1), inv(n + 1), log(n + 1);
    log[0] = -1, f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i % P;
        log[i] = log[i >> 1] + 1;
    }

    auto qpow = [&](int a, int b) -> int {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % P;
            a = a * a % P;
            b >>= 1;
        }
        return res;
    };

    int Min = min(n, P - 1);
    inv[Min] = qpow(f[Min], P - 2); // 费马小定理
    for (int i = Min - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % P;

    auto C = [&](auto && C, int n, int m) -> int {
        if (m == 0) return 1;
        int sum = C(C, n / P, m / P);
        int a = n % P, b = m % P;  // C(a, b)
        int total = 0;
        if (a >= b) total = f[a] * inv[b] % P * inv[a - b] % P;
        return sum * total % P;
    };

    vector<int> dp(n + 1);
    dp[1] = 1, dp[2] = 1, dp[3] = 2;
    int l = 1, r = 1;
    for (int i = 4; i <= n; i++) {
        if (i - (1 << log[i]) + 1 <= 1 << (log[i] - 1)) l++;
        else r++;
        dp[i] = C(C, i - 1, l) * dp[l] % P * dp[r] % P;
    }
    cout << dp[n] << '\n';
    
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int T = 1;
    while (T--) {
        solve();
    }

    return 0;
}