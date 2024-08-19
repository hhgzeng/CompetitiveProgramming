#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
vector<int> g[N];
int vis[N], dfn[N], low[N], flag[N];
int dfncnt, ans;

void tarjan(int x, int fa)   // 割点
{
    vis[x] = 1;
    dfn[x] = low[x] = ++dfncnt;
    int child = 0;

    for (auto y : g[x]) {
        if (!vis[y]) {
            child++;
            tarjan(y, x);
            low[x] = min(low[x], low[y]);
            if (x != fa && low[y] >= dfn[x] && !flag[x]) {
                flag[x] = 1;
                ans++;
            }
        } else if (y != fa) {
            low[x] = min(low[x], dfn[y]);
        }
    }

    if (x == fa && child >= 2 && !flag[x]) {
        flag[x] = 1;
        ans++;
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
        g[v].push_back(u);
    }    

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfncnt = 0;
            tarjan(i, i);
        }
    }

    cout << ans << "\n";
    for (int i = 1; i <= n; i++) if (flag[i]) cout << i << " ";

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