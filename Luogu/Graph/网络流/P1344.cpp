#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e3 + 5;
const int p = 1e4 + 5;
const int inf = 1e18;
struct edge {
    int to, w, nxt;
} g[N];
int head[N], dis[N], now[N];
int n, m, s, t, tot = 1;

void add(int u, int v, int w)
{
    g[++tot].to = v;
    g[tot].w = w;
    g[tot].nxt = head[u];
    head[u] = tot;
}

bool bfs()
{
    for (int i = 1; i <= n; i++) dis[i] = inf;
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    now[s] = head[s];

    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = head[x]; i; i = g[i].nxt) {
            int y = g[i].to, w = g[i].w;
            if (w > 0 && dis[y] == inf) {
                dis[y] = dis[x] + 1;
                now[y] = head[y];
                q.push(y);
                if (y == t) return true;
            }
        }
    }
    
    return false;
}

int dfs(int x, int sum)
{
    if (x == t) return sum;
    int res = 0;
    for (int i = now[x]; i && sum; i = g[i].nxt) {
        now[x] = i;
        int y = g[i].to, w = g[i].w;
        if (w > 0 && dis[y] == dis[x] + 1) {
            int k = dfs(y, min(w, sum));
            if (!k) dis[y] = inf;
            g[i].w -= k;
            g[i ^ 1].w += k;
            res += k;
            sum -= k;
        }
    }
    return res;
}

void solve()      // 最小割 == 最大流
{
    cin >> n >> m;
    s = 1, t = n;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w * p + 1);
        add(v, u, 0);
    }

    int ans = 0;
    while (bfs()) ans += dfs(s, inf);
    cout << ans / p << " " << ans % p << "\n";
    
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