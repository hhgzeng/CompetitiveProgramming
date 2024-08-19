#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e5 + 5;
int f[N], inv[N];
int p;

int qpow(int a, int b)
{
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void init()
{
    f[0] = 1;
    for (int i = 1; i < p; i++) f[i] = f[i - 1] * i % p;
    inv[p - 1] = qpow(f[p - 1], p - 2);
    for (int i = p - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % p;
}

void solve()
{   
    int n, m;
    cin >> n >> m >> p;

    init();

    auto C = [&](int n, int m) -> int {
        if (m > n) return 0;
        return f[n] * inv[m] % p * inv[n - m] % p;
    };

    auto Lucas = [&](auto && Lucas, int n, int m) -> int {
        if (m == 0) return 1;
        return C(n % p, m % p) * Lucas(Lucas, n / p, m / p) % p;
    };

    cout << Lucas(Lucas, n + m, m) << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}