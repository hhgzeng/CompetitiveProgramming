// author : hhgzeng
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int P = 1e6 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1), mx(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mx[i] = max(mx[i - 1], v[i]);
    }

    int ans = 1;
    vector<int> dp(n + 1, 1);
    for (int i = n; i >= 2; i--) {
        ans = (ans + (v[i] - 1) * dp[mx[i - 1]]) % P;
        for (int j = 1; j <= i; j++) {
            dp[j] = (dp[j] * j + dp[j + 1]) % P;
        }
    }
    cout << ans << '\n';
    
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