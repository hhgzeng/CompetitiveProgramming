#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> v(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    sort(v.begin() + 1, v.end(), [](auto a, auto b) {
        if (abs(a[0] - a[1]) > abs(b[0] - b[1])) return 1;
        else return 0;
    });
    
    vector<int> v1, v2;
    for (int i = 1; i <= n; i++) {
        int a = v[i][0], b = v[i][1];
        if (a >= b) v1.push_back(i);
        else v2.push_back(i);
    }

    int len1 = v1.size();
    int len2 = v2.size();

    if (len1 == 1 && len2 > 0 && len1 + 2 * len2 <= m) {
        if (v1[0] < n) {
            int ans = v[v1[0]][0] + v[v2[len2 - 1]][0];
            for (int i = 0; i < len2 - 1; i++) {
                ans += v[v2[i]][1];
            }
            cout << ans << "\n";
            return;
        }
    }

    bool flag = 1;
    vector<int> vis(m + 5);
    for (int i = 0, j = m; i < v2.size(); i++) {
        vis[j] = v2[i];
        if (flag) {
            j -= 2;
            if (j == 0) j = 1, flag = 0;
            if (j == 1) flag = 0;
        } else {
            j += 2;
        }
    }
    
    for (int i = 0, j = 1; i < v1.size(); i++) {
        while (vis[j]) j++;
        vis[j] = v1[i];
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (vis[i]) {
            if (vis[i + 1] > 0 || vis[i - 1] > 0) ans += v[vis[i]][0];
            else ans += v[vis[i]][1];
        }
    }
    cout << ans << '\n';

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