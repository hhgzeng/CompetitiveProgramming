#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int x, y;
    cin >> x >> y;
    int z = ceil((a[x] + a[y]) / 2.0);
    int pos = 1;
    for (int i = 1; i <= n; i++) {
        if (abs(a[pos] - z) > abs(a[i] - z)) {
            pos = i;
        }
    }
    cout << pos << "\n";
    
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