#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

void solve()
{
    int n, m, k;
    string x;
    cin >> n >> x >> m >> k;
    if (k == n) cout << "mei you mai " << x << " de";
    else if (k == m) cout << "kan dao le mai " << x << " de";
    else cout << "wang le zhao mai " << x << " de";
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