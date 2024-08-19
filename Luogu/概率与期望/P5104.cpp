#include <bits/stdc++.h>

#define int long long

using namespace std;

const int P = 1e9 + 7;

void solve()
{
    int n, w, k;
    cin >> w >> n >> k;

    auto qpow = [&](int a, int b) -> int {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % P;
            a = a * a % P;
            b >>= 1;
        }
        return res;
    };

    cout << w * qpow(qpow(2, k), P - 2) % P << '\n';
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