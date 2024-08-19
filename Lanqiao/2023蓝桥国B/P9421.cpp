#include <bits/stdc++.h> // 100%
using namespace std;
const int N = 1e5 + 5;
int a[N], cnt[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 1) cnt1++;
        if (cnt[i] >= 3) cnt2 += cnt[i] - 2;
    }

    if (cnt1 >= cnt2) cout << (cnt1 + cnt2) / 2 << "\n";
    else cout << cnt2 << "\n";
    
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