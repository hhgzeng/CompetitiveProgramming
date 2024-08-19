#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

void solve()
{
    int a, b, n;
    cin >> a >> b >> n;

    int ans1 = 0, ans2 = n, cha = 1e9;
    for (int i = 1; i < n; i++) {
        if (a % i == 0 && b % (n - i) == 0) {
            if (a == i || b == (n - i)) continue;
            if (abs(a / i - b / (n - i)) < cha) {
                ans1 = i, ans2 = n - i;
                cha = abs(a / i - b / (n - i));
            }
        }
    }
    if (cha == 1e9) cout << "No Solution";
    else cout << ans1 << " " << ans2;
    
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