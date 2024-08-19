#include <bits/stdc++.h>
using namespace std;
const int N = 5e1 + 5;
int a[N][N];
int lx1[N], ly1[N], vx1[N], vy1[N], pre1[N];  // 求二分图最小权值匹配
int lx2[N], ly2[N], vx2[N], vy2[N], pre2[N];  // 求二分图最大权值匹配
int n, d1, d2;

bool dfs1(int x)
{
    vx1[x] = 1;
    for (int i = 1; i <= n; i++) {
        if (!vy1[i]) {
            int t = lx1[x] + ly1[i] - a[x][i];
            if (t == 0) {
                vy1[i] = 1;
                if (!pre1[i] || dfs1(pre1[i])) {
                    pre1[i] = x;
                    return true;
                }
            } else if (t < 0) {
                d1 = max(d1, t);
            }
        }
    }
    return false;
}

bool dfs2(int x)
{
    vx2[x] = 1;
    for (int i = 1; i <= n; i++) {
        if (!vy2[i]) {
            int t = lx2[x] + ly2[i] - a[x][i];
            if (t == 0) {
                vy2[i] = 1;
                if (!pre2[i] || dfs2(pre2[i])) {
                    pre2[i] = x;
                    return true;
                }
            } else if (t > 0) {
                d2 = min(d2, t);
            }
        }
    }
    return false;
}

void mk1()
{
    for (int i = 1; i <= n; i++) {
        while (1) {
            d1 = -1e9;
            memset(vx1, 0, sizeof(vx1));
            memset(vy1, 0, sizeof(vy1));
            if (dfs1(i)) break;
            for (int i = 1; i <= n; i++) {
                if (vx1[i]) lx1[i] -= d1;
                if (vy1[i]) ly1[i] += d1;
            }
        }
    }
}

void mk2()
{
    for (int i = 1; i <= n; i++) {
        while (1) {
            d2 = 1e9;
            memset(vx2, 0, sizeof(vx2));
            memset(vy2, 0, sizeof(vy2));
            if (dfs2(i)) break;
            for (int i = 1; i <= n; i++) {
                if (vx2[i]) lx2[i] -= d2;
                if (vy2[i]) ly2[i] += d2;
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
            lx1[i] = min(lx1[i], a[i][j]);
            lx2[i] = max(lx2[i], a[i][j]);
        }
    }

    mk1();
    mk2();
    int ans1 = 0, ans2 = 0;    // ans1: min, ans2: max
    for (int i = 1; i <= n; i++) {
        ans1 += a[pre1[i]][i];
        ans2 += a[pre2[i]][i];
    }
    cout << ans1 << "\n";
    cout << ans2 << "\n";


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