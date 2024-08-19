#include <bits/stdc++.h>  // 20%
using namespace std;
const int N = 1e5 + 5;
struct node {
    int l, r;
} a[N];

void solve()  
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
    }

    while (m--) {
        int L, R;
        cin >> L >> R;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (L <= a[i].l && a[i].r <= R) ans++;
            else if (L <= a[i].l && (a[i].l + a[i].r) / 2.0 <= R) ans++;
            else if (L <= (a[i].l + a[i].r) / 2.0 && a[i].r <= R) ans++;
        }
        cout << ans << "\n";
    }
    
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