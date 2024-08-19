// author: hhgzeng  | easy to hard: B -> D -> F -> A -> H
#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
char a[N][N], b[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int len = 0;
            while (j <= n && a[i][j] == '0') len++, j++;
            ans += max(0, len - m + 1);
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