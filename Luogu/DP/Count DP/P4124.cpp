// author : hhgzeng
#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int l, r;
    cin >> l >> r;

    int dp[12][12][12][2][2][2][2];
    int cnt[12];

    auto dfs = [&](auto && dfs, int p, int a, int b, bool c, bool d, bool i4, bool i8) -> int {
        if (i4 && i8) return 0;
        if (p <= 0) return c;
        if (dp[p][a][b][c][d][i4][i8]) return dp[p][a][b][c][d][i4][i8];

        int res = 0;
        int Max = !d ? cnt[p] : 9;
        for (int i = 0; i <= Max; i++) {
            res += dfs(dfs, p - 1, i, a, c || (i == a && a == b), d || i < Max, i4 || i == 4, i8 || i == 8);
        }
        return dp[p][a][b][c][d][i4][i8] = res;
    };

    auto calc = [&](int x) -> int {
        if (x < 1e10) return 0;
        memset(dp, 0, sizeof(dp));
        int len = 0;
        while (x) {
            cnt[++len] = x % 10;
            x /= 10;
        }

        int res = 0;
        for (int i = 1; i <= cnt[len]; i++) {
            res += dfs(dfs, 10, i, 0, 0, i < cnt[len], i == 4, i == 8);
        }
        return res;
    };

    cerr << calc(r) << '\n';
    cerr << calc(l - 1) << '\n';
    cout << calc(r) - calc(l - 1) << '\n';
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