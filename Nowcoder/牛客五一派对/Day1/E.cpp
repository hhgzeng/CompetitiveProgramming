#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    
    auto dfs = [&](auto && dfs, int x, int y, int k) -> int {
        if (k == 1) {
            if (x == 1 && y == 1) return 1;
            if (x == 2 && y == 1) return 2;
            if (x == 2 && y == 2) return 3;
            if (x == 1 && y == 2) return 4;
        }

        int r = 1 << (k - 1);
        int area = r * r;
        if (x <= r && y <= r) return dfs(dfs, y, x, k - 1);
        if (x > r && y <= r)  return dfs(dfs, x - r, y, k - 1) + area;
        if (x > r && y > r)   return dfs(dfs, x - r, y - r, k - 1) + 2 * area;
        if (x <= r && y > r)  return dfs(dfs, 2 * r - y + 1, r - x + 1, k - 1) + 3 * area;
        return 0;
    };

    map<int, pair<int, int>> mp;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        int ans = dfs(dfs, x, y, k);
        mp[ans] = {x, y};
    }

    for (auto p : mp) cout << p.second.first << " " << p.second.second << '\n';
    
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