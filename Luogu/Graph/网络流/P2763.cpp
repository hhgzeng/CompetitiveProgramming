#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int inf = 1e9;
struct edge {
    int to, w, nxt;
} g[N];
int head[N], dis[N], now[N];
int tot = 1, s, t, n, m;

void add(int u, int v, int w)
{
    g[++tot].to = v;
    g[tot].w = w;
    g[tot].nxt = head[u];
    head[u] = tot;

    g[++tot].to = u;
    g[tot].w = 0;
    g[tot].nxt = head[v];
    head[v] = tot;
}

bool bfs()
{
    for (int i = 0; i <= n + m + 1; i++) dis[i] = inf;

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
        now[x] = head[i];
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
    int total = 0;
    cin >> m >> n;
    s = 0, t = n + m + 1;
    for (int i = 1; i <= n; i++) add(s, i, 1);
    for (int i = 1; i <= m; i++) {
        int w; cin >> w;
        total += w;
        add(n + i, t, w);
    }
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        while (p--) {
            int x; cin >> x;
            add(i, n + x, 1);
        }   
    }

    int ans = 0;
    while (bfs()) ans += dfs(s, inf);

    if (ans != total) cout << "No Solution!\n";
    else {
        vector<int> cnt[m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = head[i]; j; j = g[j].nxt) {
                int y = g[j].to, w = g[j].w;
                if (!w && y) cnt[y - n].push_back(i);
            }
        }
        for (int i = 1; i <= m; i++) {
            cout << i << ": ";
            for (auto x : cnt[i]) {
                cout << x << " ";
            }
            cout << "\n";
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