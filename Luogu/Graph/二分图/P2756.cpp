#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
vector<int> g[N];
int match[N], vis[N];

bool dfs(int x, int p)
{
    if (vis[x] == p) return false;
    vis[x] = p;
    for (auto y : g[x]) {
        if (!match[y] || dfs(match[y], p)) {
            match[y] = x;
            return true;
        }
    }
    return false;
}

void solve()
{
    int m, n;
    cin >> m >> n;
    int u, v;
    cin >> u >> v;
    while (u != -1 || v != -1) {
        g[u].push_back(v);
        cin >> u >> v;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dfs(i, i)) ans++;
    }

    cout << ans << "\n";
    for (int i = m + 1; i <= n; i++) {
        if (match[i]) {
            cout << match[i] << " " << i << "\n";
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