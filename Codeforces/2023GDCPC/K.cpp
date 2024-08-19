#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int px[4] = {0, -2, 0, 2};
int py[4] = {2, 0, -2, 0};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> v(n + 1, vector<int>(m + 1));
    set<pair<int, int>> s;
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        s.insert({x, y});
        v[x][y] = 1;
    }

    auto dfs = [&](set<pair<int, int>> s) -> void {
        set<pair<int, int>> st;
        st = s;
        for (auto [x, y] : s) {
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i], yy = y + dy[i];
                int xp = x + px[i], yp = y + py[i];
                if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
                if (xp < 1 || yp < 1 || xp > n || yp > m) continue;
                if (!v[xx][yy] || v[xp][yp]) continue;
                v[xp][yp] = 1;
                v[x][y] = 0;
                st.erase({xx, yy});
                st.erase({x, y});
                st.insert({xp, yp});
            }
        }
    };
    
    
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