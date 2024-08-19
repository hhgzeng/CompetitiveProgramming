// author : hhgzeng
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 5;

void solve()
{
    ll k, l, p;
    cin >> k >> l >> p;
    ll s, w;
    cin >> s >> w;

    auto qpow = [&](ll a, ll b) -> ll {
        a %= p;
        ll res = 1;
        while (b) {
            if (b & 1) res = res * a % p;
            a = a * a % p;
            b >>= 1;
        }
        return res;
    };

    if (l == 1) {
        if (s) cout << 1 << '\n';
        else cout << k % p << '\n';
        return;
    }

    if (k == 1) {
        cout << 0 << '\n';
        return;
    }

    if (s) {
        assert(k - 2 >= 0 && l - 2 >= 0);
        cout << (k - 1) % p * qpow(k - 2, l - 2) % p << '\n';
    } else {
        assert(k - 2 >= 0 && l - 2 >= 0);
        cout << k % p * ((k - 1) % p) % p * qpow(k - 2, l - 2) % p << '\n';
    }
    
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int T = 1;
    while (T--) {
        solve();
    }

    return 0;
}