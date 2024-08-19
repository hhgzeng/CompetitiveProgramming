#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int a[N], cnt[N];

void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    cnt[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
        ans += cnt[a[i] % k];
        cnt[a[i] % k]++;
    }
    cout << ans << "\n";
    
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