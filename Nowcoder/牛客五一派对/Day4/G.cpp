// author: hhgzeng  | easy to hard: B -> D -> F -> A -> H -> G
#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
int a[N], b[N];

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    if (n == 2) {
        if (k & 1) swap(a[1], a[2]);
        cout << abs(a[1] - b[1]) + abs(a[2] - b[2]) << '\n';
        return;
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > b[i]) swap(a[i], b[i]);
        ans += b[i] - a[i];
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    for (int i = 1; i <= min(n, k); i++) {
        int t = 2 * (a[n - i + 1] - b[i]);
        if (t > 0) ans += t;
        else break;
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