// author : hhgzeng
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e1 + 5;
const int P = 1e8;
int dp[N][1 << 12];
int a[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int t; cin >> t;
            a[i] = (a[i] << 1) + t ^ 1;
        }
    }

    for (int i = 0; i < 1 << m; i++) {
        if (i & a[1] || i & (i << 1)) continue;
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 1 << m; j++) {  // now row
            if (j & a[i] || j & (j << 1)) continue;
            for (int k = 0; k < 1 << m; k++) {   // pre row
                if (k & a[i - 1] || k & j || k & (k << 1)) continue;
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % P;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 1 << m; i++) {
        ans = (ans + dp[n][i]) % P;
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