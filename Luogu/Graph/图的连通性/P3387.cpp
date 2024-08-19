#include <bits/stdc++.h>
using namespace std;
const int N = 1e1 + 5;
vector<int> g1[N], g2[N];
int a[N], dfn[N], low[N], stk[N], in_stk[N];
int scc[N], ind[N], p[N], dis[N];
int dfncnt, top, sc, ans;

void tarjan(int x)
{
    dfn[x] = low[x] = ++dfncnt;
    stk[++top] = x, in_stk[x] = 1;

    for (auto y : g1[x]) {
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (in_stk[y]) {
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

void topo()
{
    queue<int> q;
    for (int i = 1; i <= sc; i++) {
        if (!ind[i]) {
            q.push(i);
            dis[i] = p[i];
        }
    }

    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (auto y : g2[x]) {
            dis[y] = max(dis[y], dis[x] + p[y]);
            ind[y]--;
            if (!ind[y]) q.push(y);
        }
    }

    ans = *max_element(dis + 1, dis + sc + 1);

}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g1[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }

    for (int i = 1; i <= n; i++) {
        for (auto y : g1[i]) {
            if (scc[i] != scc[y]) {
                g2[scc[i]].push_back(scc[y]);
                ind[scc[y]]++;
            }
        }
    }

    topo();
    cout << ans << "\n";

}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int T = 1;
    while (T--) {
        solve();
    }

    return 0;
}