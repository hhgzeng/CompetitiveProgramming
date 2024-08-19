#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int q;
    cin >> q;
    while (q--) {
        for (int i = 1; i <= n; i++) cin >> b[i];
        int t = 0, f = 0, q = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == b[i]) t++;
            else if (b[i] == 0) q++;
            else f++;
        }
        if (f > 0 || q == n) cout << "Ai Ya\n";
        else cout << "Da Jiang!!!\n";
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