#include <bits/stdc++.h>   // 45%
using namespace std;
const int N = 2e3 + 5;
struct node {
    long long x, y;
} a[N];

long long dist(int i, int j)
{
    long long xx = (a[i].x - a[j].x) * (a[i].x - a[j].x);
    long long yy = (a[i].y - a[j].y) * (a[i].y - a[j].y);
    return xx + yy;
}

bool istrue(int i, int j, int k)
{
    if ((a[i].y - a[j].y) * (a[j].x - a[k].x) == (a[j].y - a[k].y) * (a[i].x - a[j].x)) return true;
    else return false;
}

void solve()   // 暴力求解
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }

    if (n < 1000) {
        int ans = 0;
        for (int i = 1; i <= n - 2; i++) {
            for (int j = i + 1; j <= n - 1; j++) {
                for (int k = j + 1; k <= n; k++) {
                    if (istrue(i, j, k)) continue;
                    if (dist(i, j) == dist(i, k) || dist(j, i) == dist(j, k) || dist(k, i) == dist(k, j)) {
                        ans++;
                    }
                }
            }
        }
        cout << ans << "\n";
    } else {
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            unordered_map<long long, int> mp;
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                mp[dist(i, j)]++;
            }
            for (auto [x, y] : mp) {
                if (y >= 2) {
                    ans += y * (y - 1) / 2;
                }
            }
        }
        cout << ans << "\n";
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