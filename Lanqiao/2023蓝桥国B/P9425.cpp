#include <bits/stdc++.h>   // 100%
#define pii pair<int, int>
using namespace std;
const int N = 1e3 + 5;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char a[N][N];
int dis[N][N][11], vis[N][N][11];

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    memset(dis, 0x3f, sizeof(dis));
    dis[1][1][1] = 0;

    queue<array<int, 3>> q;
    q.push({1, 1, 1});
    int c = 0, t = 1;
    vis[1][1][1] = 1;

    while (!q.empty()) {
        if (t == k) {
            c ^= 1;
            t = 0;
        }
        t++;
        int qs = q.size();
        for (int i = 1; i <= qs; i++) {
            int x = q.front()[0], y = q.front()[1], z = q.front()[2]; q.pop();
            if (x == n && y == m) {
                cout << dis[x][y][z] << "\n";
                return;
            }
            for (int j = 0; j < 4; j++) {
                int xx = x + dx[j];
                int yy = y + dy[j];
                if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
                if (a[xx][yy] != c + 'A') continue;
                if (vis[xx][yy][t]) continue;
                dis[xx][yy][t] = dis[x][y][z] + 1;
                vis[xx][yy][t] = 1;
                q.push({xx, yy, t});
            }
        }
    }
    cout << -1 << "\n";
    
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