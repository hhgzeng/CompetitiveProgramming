// author : hhgzeng
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e2 + 5;
int dp[N][1 << 10][1 << 10], sum[1 << 10];
int a[N], ans;

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char t; cin >> t;
            a[i] <<= 1;
            a[i] += t == 'H' ? 1 : 0;
        }
    }

    for (int i = 0; i < 1 << m; i++) {
        sum[i] = __builtin_popcount(i);
    }

    for (int i = 0; i < 1 << m; i++) {
        if (!(i & a[1] || i & (i << 1) || i & (i << 2))) {
            dp[1][i][0] = sum[i];
            ans = max(ans, dp[1][i][0]);
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 1 << m; j++) {    // now row
            if (j & a[i] || j & (j << 1) || j & (j << 2)) continue;
            for (int k = 0; k < 1 << m; k++) {   // pre row
                if (k & a[i - 1] || k & j || k & (k << 1) || k & (k << 2)) continue;
                for (int l = 0; l < 1 << m; l++) {   // pre pre row
                    if (l & a[i - 2] || l & j || l & k || l & (l << 1) || l & (l << 2)) continue;
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][k][l] + sum[j]);
                    ans = max(ans, dp[i][j][k]);
                }
            }
        }
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