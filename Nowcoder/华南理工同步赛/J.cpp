#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
vector<int> g[N];
int f[N], vis[N], loop[N], ans[N], dfn[N];
int len, n, k, dfncnt;

void get_loop(int x, int fa)
{
    dfn[x] = ++dfncnt;
    for (auto y : g[x]) {
        if (y == fa) continue;
        if (dfn[y]) {
            if (dfn[x] > dfn[y]) continue;
            loop[++len] = x;
            for (int i = y; i != x; i = f[i]) {
                loop[++len] = i;
            }
        } else {
            f[y] = x;
            get_loop(y, x);
        }
    }
}

void dfs(int x, int fa)
{
    for (auto y : g[x]) {
        if (y == fa || vis[y]) continue;
        if (k) {
            ans[y] = ans[x] ^ 1;
            k--;
        } else {
            ans[y] = ans[x];
        }
        dfs(y, x);
    }
}

void solve()
{
    cin >> n >> k;

    len = dfncnt = 0;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) f[i] = 0;
    for (int i = 1; i <= n; i++) vis[i] = 0;
    for (int i = 1; i <= n; i++) ans[i] = 0;
    for (int i = 1; i <= n; i++) dfn[i] = 0;
    for (int i = 1; i <= n; i++) loop[i] = 0;

    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    get_loop(1, 0);

    if (len == n && k & 1) cout << -1 << "\n";
    else if (k == n && len & 1) cout << -1 << "\n";
    else {
        int s = 1;
        while (k > 1 && s <= len) {
            ans[loop[s]] = 1, vis[loop[s]] = 1;
            if (s + 1 <= len) ans[loop[s + 1]] = 0, vis[loop[s + 1]] = 1;
            if (s + 1 <= len) k -= 2;
            s += 2;
        }
        while (s <= len) ans[loop[s]] = 1, vis[loop[s]] = 1, s++;
        for (int i = 1; i <= len; i++) dfs(loop[i], 0);
        if (k) cout << -1;
        else for (int i = 1; i <= n; i++) cout << ans[i];
        cout << "\n";
    }


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