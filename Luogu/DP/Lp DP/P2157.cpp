// author : hhgzeng
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e3 + 5;
const int inf = 0x3f3f3f3f;
int t[N], b[N], dp[N][1 << 8][20];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i] >> b[i];

    memset(dp, 0x3f, sizeof(dp));
    dp[1][0][7] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (1 << 8); j++) {
            for (int k = -8; k <= 7; k++) {
                if (dp[i][j][k + 8] == inf) continue;
                if (j & 1) {
                    dp[i + 1][j >> 1][k + 7] = min(dp[i + 1][j >> 1][k + 7], dp[i][j][k + 8]);
                } else {
                    int pos = inf;
                    for (int l = 0; l <= 7; l++) {
                        if (j & (1 << l)) continue;
                        if (i + l > pos) break;
                        pos = min(pos, i + l + b[i + l]);
                        int temp = dp[i][j][k + 8] + (i + k > 0 ? t[i + k] ^ t[i + l] : 0);   // a ^ b == a | b - a & b
                        dp[i][j | (1 << l)][l + 8] = min(dp[i][j | (1 << l)][l + 8], temp);
                    }
                }
            }
        }
    }

    int ans = inf;
    for (int i = 0; i <= 8; i++) {
        ans = min(ans, dp[n + 1][0][i]);
    }
    cout << ans << '\n';
    
}

int main()
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