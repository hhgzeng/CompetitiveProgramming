#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
const int inf = 1e18;
struct edge {
    int to, w, nxt;
} g[N];
int dis[N], now[N], head[N];  // dinic
// int vis[N], pre[N], flag[3000][3000]; // EK
int n, m, s, t, tot = 1, ans;

void add(int u, int v, int w)
{
    g[++tot].to = v;
    g[tot].w = w;
    g[tot].nxt = head[u];
    head[u] = tot;
}

// EK算法求最大流: O(n*m^2)

// bool bfs()
// {
//     for (int i = 1; i <= n; i++) vis[i] = 0;
//     queue<int> q;
//     q.push(s);
//     vis[s] = 1;
//     dis[s] = inf;

//     while (!q.empty()) {
//         int x = q.front(); q.pop();
//         for (int i = head[x]; i; i = g[i].nxt) {
//             int y = g[i].to, w = g[i].w;
//             if (w == 0) continue;
//             if (vis[y]) continue;
//             dis[y] = min(dis[x], w);
//             pre[y] = i;
//             q.push(y);
//             vis[y] = 1;
//             if (y == t) return true;
//         }
//     }

//     return false;
// }

// void update()
// {
//     int x = t;
//     while (x != s) {
//         int y = pre[x];
//         g[y].w -= dis[t];
//         g[y ^ 1].w += dis[t];
//         x = g[y ^ 1].to;
//     }
//     ans += dis[t];
// }

// dinic算法求最大流: O(n^2*m)  主流方法

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
                q.push(y);
                now[y] = head[y];
                dis[y] = dis[x] + 1;
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
            int k = dfs(y, min(sum, w));
            if (k == 0) dis[y] = inf;
            g[i].w -= k;
            g[i ^ 1].w += k;
            res += k;
            sum -= k;
        }
    }
    return res;
}

void solve()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, 0);
        // if (!flag[u][v]) {
        //     add(u, v, w);
        //     add(v, u, 0);
        //     flag[u][v] = tot;
        // } else {
        //     g[flag[u][v] - 1].w += w;
        // }
    }

    while (bfs()) ans += dfs(s, inf);
    // while (bfs()) update();
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