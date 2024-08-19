#include <bits/stdc++.h>    // 90%
#define int long long
#define pii pair<int, int>
using namespace std;
const int N = 2e5 + 5;
vector<int> g[N];
map<pii, int> mp;
int dfn[N], low[N], isbridge[N], dp[N], vis[N];
int dfncnt;

void tarjan(int x, int fa)
{
    dfn[x] = low[x] = ++dfncnt;
    for (auto y : g[x]) {
        if (!dfn[y]) {
            tarjan(y, x);
            low[x] = min(low[x], low[y]);
            if (low[y] > dfn[x] && mp[{x, y}] + mp[{y, x}] == 1) {
                isbridge[y] = 1;
            }
        } else if (y != fa) {
            low[x] = min(low[x], dfn[y]);
        }
    }
}

void dfs(int x, int fa)
{
    vis[x] = 1;
    for (auto y : g[x]) {
        if (y == fa || vis[y]) continue;
        dfs(y, x);
        dp[x] += dp[y];
    }
}

void solve()  // tarjan算法: 割边
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> dp[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[{u, v}]++;
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i, i);
    }

    dfs(1, 1);

    int ans = 1e18;
    for (int i = 1; i <= n; i++) {
        if (isbridge[i]) {
            ans = min(ans, abs(dp[1] - dp[i] - dp[i]));
        }
    }
    if (ans != 1e18) cout << ans << "\n";
    else cout << -1 << "\n";
    
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