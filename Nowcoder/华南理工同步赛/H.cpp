#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int N = 2e5 + 5;
vector<int> g[N];
map<pii, int> mp;
pair<int, int> pa[N];
int dp1[N][2], dp2[N][2];

void dfs1(int x, int fa)
{
    dp1[x][0] = 0;
    dp1[x][1] = 1;
    for (auto y : g[x]) {
        if (y == fa) continue;
        dfs1(y, x);
        dp1[x][0] += dp1[y][1];
        dp1[x][1] += min(dp1[y][1], dp1[y][0]);
    }
}

void dfs2(int x, int fa)
{
    for (auto y : g[x]) {
        if (y == fa) continue;
        int f1 = dp2[x][1] - min(dp1[y][0], dp1[y][1]);
        int f0 = dp2[x][0] - dp1[y][1];
        dp2[y][1] = dp1[y][1] + min(f1, f0);
        dp2[y][0] = dp1[y][0] + f1;
        int sum = 0;
        sum += min(f1, f0);
        sum += min(dp1[y][1], dp1[y][0]);
        mp[{x, y}] = sum;
        mp[{y, x}] = sum;
        dfs2(y, x);
    }
}

void solve()
{
    int n;
    cin >> n;
    mp.clear();
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        pa[i].first = u, pa[i].second = v;
    }

    dfs1(1, 1);

    dp2[1][1] = dp1[1][1];
    dp2[1][0] = dp1[1][0];

    dfs2(1, 1);

    for (int i = 1; i < n; i++) {
        int u = pa[i].first;
        int v = pa[i].second;
        cout << n - mp[{u, v}] << " ";
    }
    cout << "\n";

}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}