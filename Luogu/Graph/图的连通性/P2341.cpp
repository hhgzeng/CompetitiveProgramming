#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
vector<int> g[N];
int dfn[N], low[N], stk[N], vis[N], scc[N], sz[N], ind[N];
int dfncnt, top, sc;

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
        } while (skt[top--] != x);
    }

}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }

    for (int i = 1; i <= n; i++) {
        for (auto y : g[i]) {
            if (scc[y] != scc[i]) {
                ind[scc[y]]++;
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i <= sc; i++) {
        if (!ind[i]) {
            ans.push_back(sz[i]);
        }
    }

    if (ans.size() != 1) cout << 0 << "\n";
    else if (ans.size() == 1) cout << ans[0] << "\n";
    else cout << n << "\n";

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