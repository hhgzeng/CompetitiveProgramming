#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 2, vector<int>(m + 2));
    map<int, pair<int, int>> mp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            mp[v[i][j]] = {i, j};
        }
    } 

    int ans = 0;
    set<pair<int, int>> s;
    for (auto p : mp) {
        int x = p.second.first, y = p.second.second;
        if (s.empty()) s.insert({x, y});
        else {
            auto xy = s.lower_bound({x, y});
            if (xy == s.begin()) {
                auto xy2 = *s.lower_bound({x, y});
                if (x <= xy2.first && y <= xy2.second) s.insert({x, y});
                else break;
            } else if (xy == s.end()) {
                auto xy1 = *(--s.lower_bound({x, y}));
                if (x >= xy1.first && y >= xy1.second) s.insert({x, y});
                else break;
            } else {
                auto xy1 = *(--s.lower_bound({x, y}));
                auto xy2 = *s.lower_bound({x, y});
                if (xy1.first <= x && x <= xy2.first && xy1.second <= y && y <= xy2.second) s.insert({x, y});
                else break;
            }
        }
        ans++;
    }
    cout << ans << '\n';
    

}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    // set<pair<int, int>> s;
    // s.insert({1, 2});
    // s.insert({2, 2});
    // auto x = s.lower_bound({2, 1});
    // // auto x1 = *(--s.lower_bound({1, 2}));
    // // auto x2 = *s.lower_bound({1, 2});
    // // if (x == s.begin()) cerr << "error\n";
    // if (x == s.end()) cerr << "error\n";
    // else cout << (*x).first << (*x).second << '\n';
    // cout << (*x).first << (*x).second << '\n';
    // return 0;

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}