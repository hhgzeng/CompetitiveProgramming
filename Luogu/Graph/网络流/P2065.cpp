#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int inf = 1e9;
struct edge {
    int to, w, nxt;
} g[N];
int b[N], p[N], dis[N], now[N], head[N];
int n, m, tot, total, s, t;

void add(int u, int v, int w)
{
    g[++tot].to = v;
    g[tot].w = w;
    g[tot].nxt = head[u];
    head[u] = tot;
}

void divide1(int x, int S)
{
    int len = 0;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            p[++len] = i;
            while (x % i == 0) x /= i;
        }
    }

    if (x > 1) p[++len] = x;
    for (int i = 1; i <= len; i++) {
        if (!b[p[i]]) b[p[i]] = ++total;
        add(S, b[p[i]] + n + m, 1);
        add(b[p[i]] + n + m, S, 0);
    }
   
}

void divide2(int x, int S)
{
    int len = 0;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            p[++len] = i;
            while (x % i == 0) x /= i;
        }
    }

    if (x > 1) p[++len] = x;
    for (int i = 1; i <= len; i++) {
        if (!b[p[i]]) continue;
        add(b[p[i]] + n + m, S, 1);
        add(S, b[p[i]] + n + m, 0);
    }
    
}

bool bfs()
{
    for (int i = 1 ; i <= t; i++) dis[i] = inf;
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

int dinic()
{
    int ans = 0;
    while (bfs()) ans += dfs(s, inf);
    return ans;
}

void solve()
{
    memset(head, 0, sizeof(head));
    memset(b, 0, sizeof(b));
    total = 0, tot = 1;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        add(0, i, 1);
        add(i, 0, 0);
    }
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        divide1(a, i);
    }
    for (int i = 1; i <= m; i++) {
        int a; cin >> a;
        divide2(a, i + n);
    }
    for (int i = 1; i <= m; i++) {
        add(i + n, n + m + total + 1, 1);
        add(n + m + total + 1, i + n, 0);
    }
    
    s = 0, t = n + m + total + 1;
    cout << dinic() << "\n";

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