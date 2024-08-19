#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> g[N];
int match[N], vis[N];

bool dfs(int x, int p)   // 匈牙利算法 : 二分图匹配 O(nm)
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
    int n, m, e;
    cin >> n >> m >> e;
    for (int i = 1; i <= e; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dfs(i, i)) ans++;
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