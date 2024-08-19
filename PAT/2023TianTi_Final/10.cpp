#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
string s[N];

void solve()
{
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> a[i];
    }

    vector<int> cnt;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cout << s[i] << " " << (a[i] + c - 1) / c << "\n";
        if (a[i] % c > 0) cnt.push_back(a[i] % c);
        ans += a[i] / c;
    }

    sort(cnt.begin(), cnt.end(), greater<int>());

    while (!cnt.empty()) {
        int sum = 0;
        vector<int> pos;
        for (int i = 0; i < cnt.size(); i++) {
            if (sum + cnt[i] <= c) {
                sum += cnt[i];
                pos.push_back(i);
            }
        }
        ans++;
        for (int i = pos.size() - 1; i >= 0; i--) {
            cnt.erase(cnt.begin() + pos[i], cnt.begin() + pos[i] + 1);
        }
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