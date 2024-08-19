#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
map<string, int> mp;
vector<int> g[N];
int dfn[N], low[N], stk[N], vis[N], scc[N];
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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string a, b;
        cin >> a >> b;
        mp[a] = i;
        mp[b] = i + n;
        g[i].push_back(i + n);
    }

    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        string a, b;
        cin >> a >> b;
        g[mp[b]].push_back(mp[a]);
    }

    for (int i = 1; i <= 2 * n; i++) {
        if (!dfn[i]) tarjan(i);
    }

    for (int i = 1; i <= n; i++) {
        if (scc[i] == scc[i + n]) {
            cout << "Unsafe\n";
        } else {
            cout << "Safe\n";
        }
    }

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