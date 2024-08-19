#include <bits/stdc++.h>   // 100%
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    int ans = 0;
    for (int i = 1, j = 1; i <= n && j <= m; i++, j++) {
        if (a[i] == b[j]) continue;
        else if (a[i] > b[j]) {
            b[j + 1] += b[j];
            i--;
            ans++;
        } else {
            a[i + 1] += a[i];
            j--;
            ans++;
        }
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