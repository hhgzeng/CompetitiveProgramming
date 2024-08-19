#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int p;
    cin >> p;
    vector<int> f(p), vis(p);
    f[1] = 1, vis[1] = 1;

    for (int i = 2; i < p; i++) {
        int t1 = f[i - 1] * 2 % p;
        int t2 = f[i - 1] * 3 % p;
        if (t1 && !vis[t1]) f[i] = t1, vis[t1] = 1;
        else if (t2 && !vis[t2]) f[i] = t2, vis[t2] = 1;
        else break;
    }

    if (count(f.begin() + 1, f.end(), 0) > 0) cout << -1;
    else for (int i = 1; i < p; i++) cout << f[i] << ' ';
    cout << '\n';

}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr), std::cout.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}