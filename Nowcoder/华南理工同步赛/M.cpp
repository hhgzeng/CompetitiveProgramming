#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], ans[N], p[N];
int n;

bool manacher()
{
    int pos = 0, maxpos = 0;
    for (int i = 1; i <= n; i++) {
        if (i <= maxpos) p[i] = min(p[pos - (i - pos)], maxpos - i);   // i <= maxpos,保证p[i] = 0
        while (ans[i - p[i]] == ans[i + p[i]]) p[i]++;
        if (i + p[i] > maxpos) {
            pos = i;
            maxpos = i + p[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] != p[i] * 2 - 1) {
            return false;
        }
    }
    return true;
    
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    ans[1] = 1, ans[2] = 1;
    for (int i = 2; i < n; i++) {
        if (a[i] == 1) {
            ans[i + 1] = ans[i - 1] ^ 1;
        } else {
            ans[i + 1] = ans[i - 1];
        }
    }
    ans[0] = -2, ans[n + 1] = 2;

    if (manacher()) {
        for (int i = 1; i <= n; i++) cout << ans[i];
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }

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