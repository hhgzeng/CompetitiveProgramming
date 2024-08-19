#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char a[N][N];
int vis[N][N];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'H') {
                vis[i][j] = 1;
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x < 1 || y < 1 || x > n || y > m) continue;
                    vis[x][y] = 1;
                }
            } else if (a[i][j] == 'M') {
                vis[i][j] = 1;
            } else if (a[i][j] == 'L') {
                bool flag = 1;
                vis[i][j] = 1;
                for (int k = 0; k < 8 && flag; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x < 1 || y < 1 || x > n || y > m) {
                        flag = 0;
                        continue;
                    }
                    if (a[x][y] != 'L') flag = 0;
                }
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x < 1 || y < 1 || x > n || y > m) continue;
                    if (a[x][y] == 'G' && !vis[x][y]) {
                        vis[x][y] = 3;
                    }
                }
                if (flag) vis[i][j] = 2;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j] == 0) cout << 'B';
            else if (vis[i][j] == 1) cout << a[i][j];
            else if (vis[i][j] == 2) cout << 'S';
            else cout << 'N';
        }
        cout << "\n";
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