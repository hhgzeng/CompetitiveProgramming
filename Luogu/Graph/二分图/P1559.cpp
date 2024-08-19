#include <bits/stdc++.h>
using namespace std;
const int N = 2e1 + 5;
int a[N][N];
int lx[N], ly[N], vx[N], vy[N], pre[N];
int n, d;

bool dfs(int x)
{
    vx[x] = 1;
    for (int i = 1; i <= n; i++) {
        if (!vy[i]) {
            int t = lx[x] + ly[i] - a[x][i];
            if (t == 0) {
                vy[i] = 1;
                if (!pre[i] || dfs(pre[i])) {
                    pre[i] = x;
                    return true;
                }
            } else if (t > 0) {
                d = min(d, t);
            }
        }
    }
    return false;
}

void km()
{
    for (int i = 1; i <= n; i++) {
        while (1) {
            d = 1e9;
            memset(vx, 0, sizeof(vx));
            memset(vy, 0, sizeof(vy));
            if (dfs(i)) break;
            for (int j = 1; j <= n; j++) {
                if (vx[j]) lx[j] -= d;
                if (vy[j]) ly[j] += d;
            }
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int b; cin >> b;
            a[j][i] *= b;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            lx[i] = max(lx[i], a[i][j]);
        }
    }

    km();  // 匈牙利算法
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += a[pre[i]][i];
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