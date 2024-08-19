// author : hhgzeng 
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 5;
int coins[20], pay[N], dp[1 << 16], f[1 << 16];
int total, ans = 1e9;

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
        total += coins[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> pay[i];
        pay[i] += pay[i - 1];
    }

    auto check = [&](int x, int target) -> int {
        int l = x, r = m;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pay[mid] - pay[x - 1] == target) return mid;
            if (pay[mid] - pay[x - 1] < target) l = mid + 1;
            else r = mid - 1;
        }
        return r;
    };

    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) continue;
            int k = i ^ (1 << j); 
            int pos = check(dp[k] + 1, coins[j + 1]);
            if (pos > dp[i]) {
                dp[i] = pos, f[i] = f[k] + coins[j + 1];
                if (dp[i] == m) ans = min(ans, f[i]);
            }
        }
    }

    assert(0);     // assert: if false then exit

    cerr << total << "\n";  // cerr : print error message, program not read
    cerr << ans << "\n";
    if (ans == 1e9) cout << -1 << "\n";
    else cout << total - ans << "\n";

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