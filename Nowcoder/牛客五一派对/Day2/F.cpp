#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;
struct node {
    int x;
    int day;
} a[N];
int len;

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int p; cin >> p;
            a[++len].x = p;
            a[len].day = i;    
        }
    }

    sort(a + 1, a + len + 1, [](auto a, auto b) {return a.x < b.x;} );

    unordered_map<int, int> mp;
    int l = 1, r = 1, ans = 1e9;
    while (r <= len) {
        while (r <= len && int(mp.size()) < m) {
            mp[a[r].day]++;
            r++;
        }
        while (l < r && int(mp.size()) >= m) {
            if (--mp[a[l].day] == 0) mp.erase(a[l].day);
            l++;
        }
        ans = min(ans, a[r - 1].x - a[l - 1].x);
    }
    cout << ans << '\n';

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