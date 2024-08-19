#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
vector<int> g[N];
int dfn[N], low[N], stk[N], vis[N];
int scc[N], sz[N], ind[N], outd[N];
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
        } while (stk[top--] != x);
    }
    
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        while (v) {
            g[i].push_back(v);
            cin >> v;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }

    for (int i = 1; i <= n; i++) {
        for (auto y : g[i]) {
            if (scc[y] != scc[i]) {
                outd[scc[i]]++;
                ind[scc[y]]++;
            }   
        }
    }

    int ans1 = 0, ans2 = 0;  // 比较入度和出度的最大值
    for (int i = 1; i <= sc; i++) {
        if (!ind[i]) ans1++;
        if (!outd[i]) ans2++;
    }
    if (sc == 1) cout << 1 << "\n" << 0 << "\n";
    else cout << ans1 << "\n" << max(ans1, ans2) << "\n";

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