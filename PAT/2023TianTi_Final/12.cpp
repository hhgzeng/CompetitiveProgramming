#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> a;
vector<vector<bool>> vis;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;
bool flag;

void dfs(int x, int y)
{
    vis[x][y] = 1;
    if (a[x][y] > '1') flag = 1;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
        if (a[xx][yy] != '0' && !vis[xx][yy]) dfs(xx, yy);
    }
}

void solve()
{   
    cin >> n >> m;
    a.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 1; i <= n; i++) a[i].resize(m + 1);
    for (int i = 1; i <= n; i++) vis[i].resize(m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j] && a[i][j] != '0') {
                flag = 0;
                dfs(i, j);
                ans1++;
                if (flag) ans2++;
            }
        }
    }
    cout << ans1 << " " << ans2;
    
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