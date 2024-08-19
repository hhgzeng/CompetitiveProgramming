// author : hhgzeng
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e1 + 5;
const int P = 1e9 + 7;

void solve()
{
    int l, r;
    vector<int> dp(20), mi(20);

    cin >> l >> r;

    auto init = [&]() -> void {
        mi[0] = 1;
        for (int i = 1; i <= 18; i++) {
            dp[i] = (dp[i - 1] * 10 + mi[i - 1]) % P;
            mi[i] = mi[i - 1] * 10;
        }
    };

    init();

    auto get = [&](int x) -> int {
        vector<int> v(20), ans(10);
        int n = 0, t = x;
        while (x) {
            v[++n] = x % 10;
            x /= 10;
        }

        for (int i = n; i >= 1; i--) {
            for (int j = 0; j <= 9; j++) ans[j] = (ans[j] + dp[i - 1] * v[i]) % P;
            for (int j = 0; j < v[i]; j++) ans[j] = (ans[j] + mi[i - 1]) % P;
            t -= v[i] * mi[i - 1];
            ans[v[i]] = (ans[v[i]] + t + 1) % P;
            ans[0] = (ans[0] - mi[i - 1] + P) % P;
        }

        int res = 0;
        for (int i = 0; i <= 9; i++) res = (res + ans[i] * i) % P;
        return res;
    }; 

    cerr << get(r) << '\n';
    cerr << get(l - 1) << '\n';

    cout << (get(r) - get(l - 1) + P) % P << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}