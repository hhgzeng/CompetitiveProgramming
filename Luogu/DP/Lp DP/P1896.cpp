// author : hhgzeng
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e1 + 5;
ll dp[N][N * N][1 << 9];
int sum[1 << 9];

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < 1 << n; i++) {
        sum[i] = __builtin_popcount(i);
    }

    for (int i = 0; i < 1 << n; i++) {
        if (i & (i << 1)) continue;
        dp[1][sum[i]][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k < 1 << n; k++) {
                if (k & (k << 1) || j < sum[k]) continue;
                for (int l = 0; l < 1 << n; l++) {
                    if (l & (l << 1) || l & k || l & (k << 1) || l & (k >> 1)) continue;
                    dp[i][j][k] += dp[i - 1][j - sum[k]][l];
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < 1 << n; i++) {
        ans += dp[n][m][i];
    }
    cout << ans << "\n";
    
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