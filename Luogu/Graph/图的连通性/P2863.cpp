#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
vector<int> g[N];
int dfn[N], low[N], stk[N], vis[N];
int scc[N], sz[N];
int dfncnt, sc, top;

void tarjan(int x)
{
    dfn[x] = low[x] = ++dfncnt;
    stk[++top] = x, vis[x] = 1;

    for (auto y : g[x]) {
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (vis[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }

    if (dfn[x] == low[x]) {
        sc++;
        do {
            scc[stk[top]] = sc;
            vis[stk[top]] = 0;
        } while (stk[top--] != x);
    }
    
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }

    int ans = 0;
    for (int i = 1; i <= sc; i++) {
        if (sz[i] > 1) ans++;
    }
    cout << ans << "\n";

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