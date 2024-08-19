// author : hhgzeng
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 5;
int dp[1 << 20], num[21], sum[N][21];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        num[p]++;
        for (int j = 1; j <= m; j++) sum[i][j] = sum[i - 1][j];
        sum[i][p]++;
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;

    for (int i = 1; i < (1 << m); i++) {
        int length = 0;
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                length += num[j + 1];
            }
        }

        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                int p = i ^ (1 << j);
                int l = length - num[j + 1], r = length;
                dp[i] = min(dp[i], dp[p] + num[j + 1] - (sum[r][j + 1] - sum[l][j + 1]));        
            }
        }
    }

    cout << dp[(1 << m) - 1] << '\n';
    
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