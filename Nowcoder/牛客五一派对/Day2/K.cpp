#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];

void solve()
{
    int n, t;
    cin >> n >> t;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> f(n + 1), dep(n + 1);
    auto dfs = [&](auto && dfs, int x, int fa) -> void {
        dep[x] = dep[fa] + 1;
        for (auto y : g[x]) {
            if (y == fa) continue;
            f[y] = x;
            dfs(dfs, y, x);
        }
    };

    dfs(dfs, 1, 0);

    if (dep[n] - 1 <= t) {
        cout << 0 << '\n';
        return;
    }

    int s = n;
    for (int i = 1; i <= dep[n] - t - 1; i++) s = f[s];

    vector<int> dp1(n + 1), dp2(n + 1);
    auto dfs1 = [&](auto && dfs1, int x, int fa) -> void {
        for (auto y : g[x]) {
            if (y == fa) continue;
            dp1[y] = dp1[x] + 1;
            dfs1(dfs1, y, x);
        }
    };

    auto dfs2 = [&](auto && dfs2, int x, int fa) -> void {
        for (auto y : g[x]) {
            if (y == fa) continue;
            dp2[y] = dp2[x] + 1;
            dfs2(dfs2, y, x);
        }
    };

    dp1[n] = 1;
    dfs1(dfs1, n, 0);
    dfs2(dfs2, s, 0);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dp1[i] / 2 < dp2[i]) ans = max(ans, dp1[s] / 2);
        if (dp1[i] / 2 == dp2[i]) {
            if (!(dp1[i] & 1)) ans = max(ans, dp2[i] - 1);
            else ans = max(ans, dp1[i] / 2);
        }
        if (dp1[i] / 2 > dp2[i]) ans = max(ans, dp1[i] / 2);
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